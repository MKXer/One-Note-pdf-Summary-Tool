#include "Sentence.h"


Sentence::Sentence() : SummaryElement("", SummaryElement::Type::SENTENCE)
{

}


Sentence& Sentence::operator<<(QString const& textSegment)
{
	QString trimmedSegment = textSegment.trimmed();
	QString sentence = getData();

	if (sentence.endsWith("-")) {
		sentence = sentence.left(sentence.size() - 1);
		sentence += trimmedSegment;
	}
	else
	{
		sentence += " ";
		sentence += trimmedSegment;
		sentence.replace("  ", " ");
	}

	this->changeData(sentence);

	return *this;
}

bool Sentence::isComplete() const
{
	return getData().endsWith(".") || getData().endsWith("«");
}


