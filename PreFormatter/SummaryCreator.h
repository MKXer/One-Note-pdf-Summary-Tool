#pragma once

#include <poppler-qt6.h>
#include <QCoreApplication>
#include "AnnotationList.h"
#include "Sentence.h"
#include "List.h"
#include "Headline.h"
#include "Summary.h"
#include "Image.h"
#include "OneNoteLib.h"




class SummaryCreator
{

public:
	SummaryCreator(AnnotationList const& annotationList);


	QString createOneNoteSummary()
	{
		QString retn;
		auto summary = generateSummary();

		const auto factory = OneNoteLib::factory();
		auto newLines = std::move(factory.newLines(2));

		for (const auto* item : summary)
		{
			std::unique_ptr<OneNote::HtmlElement> element;
	
			if (item->isSentence() ) {
				element = std::move(factory.text(item->getData()));
			}
			else if (item->isList()) {
			
				element = std::move(factory.list(item->getData()));
			}
			else if (item->isHeadline()) {
				const auto* headline = static_cast<const HeadLine*>(item);
				
				element = std::move(factory.text(item->getData(), headline->getHeight() ));
			}
			else if (item->isImage()) {
				const Image* image = static_cast<const Image*>(item);

				element = std::move( factory.image(item->getData(), image->getSize()) );
			}

			retn += element->getHtml();
			retn += newLines->getHtml();

		}
		return retn;
	}

	
	
private:
	Summary generateSummary() const;


	TextSegment* getRegularText(Annotation* const annotation) const;

	List* collectList(int& startIndex) const;
	Sentence* collectSentence(int& startIndex) const;
	HeadLine* collectHeadline(TextSegment* const textSegment) const;

	const AnnotationList annotationList;

};

