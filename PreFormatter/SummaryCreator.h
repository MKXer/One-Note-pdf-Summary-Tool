#pragma once

#include <poppler-qt6.h>
#include <QCoreApplication>
#include "AnnotationList.h"
#include "Sentence.h"
#include "Headline.h"
#include "Summary.h"
#include "Image.h"



class SummaryCreator
{

public:
	SummaryCreator(AnnotationList const& annotationList);

	Summary generateSummary() const;

private:
	TextSegment* getRegularText(Annotation* const annotation) const;

	Sentence* collectSentence(int& startIndex) const;
	HeadLine* collectHeadline(TextSegment* const textSegment) const;

	const AnnotationList annotationList;

};

