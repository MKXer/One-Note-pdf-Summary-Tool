#pragma once
#include <poppler-qt6.h>
#include "AnnotationFactory.h"
#include "AnnotationList.h"

#include <QCoreApplication>
#include <QApplication>
#include <QBuffer>
#include <QMimeData>
#include <QClipboard>
#include "SummaryCreator.h"

class AnnotationExtractor
{

public:
	AnnotationExtractor(const Poppler::Document* file);
	AnnotationList extract();


protected:
	struct Page {
		const ushort index;
		const QSize size;
		const Poppler::Page* popplerInstance;
	};

private:
	bool isItAPossiblePageNumber(int pageNumber) const;

	const QImage extractRectangleFromPage(Page const& page, const QRectF& rect) const;
	Annotation* extractFigure(Page const& page, Poppler::Annotation* figureAnnotation) const;

	const AnnotationList extractHighligtedText(Page const& page, Poppler::Annotation* textAnnotation) const;


	const Poppler::Document* pdfFile;

	const ushort numberOfPages;
	const AnnotationFactory& factory = AnnotationFactory::factory();
};


