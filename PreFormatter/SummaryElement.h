#pragma once
#include <QString>

class SummaryElement
{

protected:
	enum class Type : uchar
	{
		LIST,
		SENTENCE,
		HEADLINE,
		IMAGE
	};

	SummaryElement(QString const& data, const Type type) : type(type), data(data)
	{

	}

	Type getType() const {
		return type;
	}

	void changeData(QString const& data) const {
		this->data = data;
	}

public:
	bool isSentence() const {
		return getType() == SummaryElement::Type::SENTENCE;
	}
	bool isList() const {
		return getType() == SummaryElement::Type::LIST;
	}

	bool isHeadline() const {
		return getType() == SummaryElement::Type::HEADLINE;
	}

	bool isImage() const {
		return getType() == SummaryElement::Type::IMAGE;
	}


	const QString& getData() const;

private:
	mutable QString data;
	const Type type;
};
