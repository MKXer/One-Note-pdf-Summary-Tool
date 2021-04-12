#include "AnnotationExtractor.h"


AnnotationExtractor::AnnotationExtractor(const Poppler::Document* file, QString const& figurePath) 
	: pdfFile(file), numberOfPages(file->numPages()), figuresPath(figurePath)
{
	
}

bool AnnotationExtractor::isItAPossiblePageNumber(int pageNumber) const {
	return pageNumber < numberOfPages;
}

const QImage AnnotationExtractor::extractRectangleFromPage(Page const& page, const QRectF& rect) const
{
	const auto cropResolutionFactor = 2;
	constexpr auto resolution = 72 * cropResolutionFactor;
	const auto pageSize = page.size * cropResolutionFactor;

	return page.popplerInstance->renderToImage(resolution, resolution,
		(rect.x() + 0.006)	   * pageSize.width(),
		(rect.y() + 0.005)	   * pageSize.height(),
		(rect.width() - 0.012) * pageSize.width(),
		(rect.height() - 0.01) * pageSize.height());
}

Annotation* AnnotationExtractor::extractFigure(Page const& page, Poppler::Annotation* figureAnnotation) const
{
	const auto highlight = static_cast<Poppler::GeomAnnotation*>(figureAnnotation);
	const auto boundary	{ figureAnnotation->boundary() };
	const auto figure	{ extractRectangleFromPage(page, boundary) };
	const auto filePath = figuresPath + QString::number(figureCount) + ".png";

	increaseFigureCountByOne();

	figure.save(filePath);

	return factory.figure({ page.index , highlight->style().color(), boundary }, filePath, figure.size() );
}

void AnnotationExtractor::increaseFigureCountByOne() const{
	figureCount++;
}

const AnnotationList AnnotationExtractor::extractHighligtedText(Page const& page, Poppler::Annotation* textAnnotation) const 
{
	AnnotationList retn;

	const auto highlight = static_cast<Poppler::HighlightAnnotation*>(textAnnotation);
	auto quads = highlight->highlightQuads();

	for (auto const& quad : quads) {
		const QPointF topLeft	  { quad.points[0].x() * page.size.width(), quad.points[0].y() * page.size.height() };
		const QPointF bottomRight { quad.points[2].x() * page.size.width(), quad.points[2].y() * page.size.height() };
		const QRectF rect		  { topLeft, bottomRight };
		const auto text = page.popplerInstance->text(rect);
	
		retn << factory.regularText({ page.index , highlight->style().color(), rect }, text);
	}

	return retn;
}

AnnotationList AnnotationExtractor::extract()
{
	AnnotationList annotations;

	for (ushort i = 0; i < numberOfPages; ++i) {

		const auto popplerPage = pdfFile->page(i);

		if (popplerPage) {
			
			const auto list = popplerPage->annotations({ Poppler::Annotation::AHighlight, Poppler::Annotation::AGeom });
			const Page page{ i, popplerPage->pageSize(), popplerPage };

			qDebug() << "process page" << i;

			for (Poppler::Annotation* item : list) {
				const auto type = item->subType();

				if (type == Poppler::Annotation::AHighlight) {
					annotations << extractHighligtedText(page, item);
				}
				else if (type == Poppler::Annotation::AGeom) {
					qDebug() << "figures" ;
					annotations << extractFigure(page, item);
				}
				delete item;
			}
		}
	}

	annotations.sort();

	return annotations;
}
