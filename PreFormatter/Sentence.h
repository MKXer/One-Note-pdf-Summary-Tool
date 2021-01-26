#pragma once
#include "SummaryElement.h"



class Sentence : public SummaryElement
{
public:
	Sentence() = default;

	Sentence& operator<<(QString const& textSegment);

	bool isComplete() const;

	operator QString const& ();

private:
	QString data = "";

};
