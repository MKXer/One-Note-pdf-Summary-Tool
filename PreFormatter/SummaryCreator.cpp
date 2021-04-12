#include "SummaryCreator.h"


SummaryCreator::SummaryCreator(AnnotationList const& annotationList) :
	annotationList(annotationList)
{

}

TextSegment* SummaryCreator::getRegularText(Annotation* const annotation) const
{
	TextSegment* regularText = nullptr;

	if (annotation->isText()) {
		regularText = static_cast<TextSegment*>(annotation);
		regularText = regularText->isRegularText() ? regularText : nullptr;
	}

	return regularText;
}

List* SummaryCreator::collectList(int& startIndex) const
{
	List* list = new List;
	bool shouldCollect = true;

	for (; shouldCollect && startIndex < annotationList.size(); ++startIndex)
	{
		Annotation* const annotation = annotationList.at(startIndex);

		if (auto textAnnotation = getRegularText(annotation);
			shouldCollect = (textAnnotation && textAnnotation->isListItem()) ) {

			const auto textSegment = textAnnotation->getText();
			*list << textSegment;

		}
	}
	startIndex--;

	return list;
}


Sentence* SummaryCreator::collectSentence(int& startIndex) const
{
	Sentence* newSentence = new Sentence;
	bool shouldCollect    = true;

	for (; shouldCollect && startIndex < annotationList.size(); ++startIndex)
	{
		Annotation* const annotation = annotationList.at(startIndex);

		if (auto textAnnotation = getRegularText(annotation);
				  shouldCollect = textAnnotation) {

			const QString textSegment = textAnnotation->getText();

			*newSentence << textSegment;

			
			shouldCollect = !newSentence->isComplete();
		
		}
		else {
			startIndex--;
		}
	}
	startIndex--;
	return newSentence;
}


HeadLine* SummaryCreator::collectHeadline(TextSegment* const textSegment) const
{
	return new HeadLine{ textSegment->getText(), textSegment->getHeight() };
}

Summary SummaryCreator::generateSummary() const
{
	Summary retn;

	int i = 0;
	for (; i < annotationList.size(); ++i) {

		Annotation* const annotation = annotationList.at(i);
		SummaryElement* element = nullptr;

		if (annotation->isText()) {
			
			const auto textSegment = static_cast<TextSegment*>(annotation);
	

			if (textSegment->isListItem())
			{
				element = collectList(i);
			}
			else if (textSegment->isRegularText()) {
				element = collectSentence(i);
			}
			else {
				element = collectHeadline(textSegment);
			}
		}
		else if (annotation->isFigure()) {
			const auto figure = static_cast<Figure*>(annotation);

			element = new Image{ figure->getFilePath(), figure->getSize() };


			
		}
		retn << element;
	}

	return retn;
}