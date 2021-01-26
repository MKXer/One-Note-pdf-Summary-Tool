#include "Sentence.h"


Sentence& Sentence::operator<<(QString const& textSegment)
{
	QString trimmedSegment = textSegment.trimmed();

	if (data.endsWith("-")) {
		data = data.left(data.size() - 1);
		data += trimmedSegment;
	}
	else
	{
		data += " ";
		data += trimmedSegment;
		data.replace("  ", " ");
	}


	return *this;
}

bool Sentence::isComplete() const
{
	return data.endsWith(".") || data.endsWith("«");
}

Sentence::operator QString const& () {
	return data;
}

