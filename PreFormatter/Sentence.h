#pragma once
#include "SummaryElement.h"



class Sentence : public SummaryElement
{
public:
	Sentence();

	Sentence& operator<<(QString const& textSegment);

	bool isComplete() const;



private:

};
