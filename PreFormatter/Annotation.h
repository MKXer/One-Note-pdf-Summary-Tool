#pragma once
#include <QObject>
#include <QColor>
#include <QRectF>
#include <QImage>



class Annotation
{

public:
	struct Data
	{
		const ushort pageIdx;
		const QColor color;
		const QRectF rect;
	};

	enum class Type : uchar
	{
		TEXT,
		FIGURE
	};

	Annotation(Type type, Data const& annotationData);

	double getHeight() const;

	bool operator<(const Annotation& str) const;

	bool isText() const
	{
		return getType() == Annotation::Type::TEXT;
	}


	bool isFigure() const
	{
		return getType() == Annotation::Type::FIGURE;
	}


	Type getType() const
	{
		return type;
	}

	const QPointF position() const;

	ushort pageNumber() const;




private:
	const Type type;
	const Data data;

};


class TextSegment : public Annotation
{

public:
	TextSegment(Annotation::Data const& anno, QString const& text) : 
		Annotation(Annotation::Type::TEXT, anno),
		text(text)
	{

	}

	QString const& getText() const {
		return text;
	}


	ushort getFontSize() const	{
		return (ushort)getHeight();
	}
	

	bool isRegularText() const
	{
		return getHeight() < 14;
	}


private:
	const QString text;
};


class Figure : public Annotation
{

public:
	Figure(Annotation::Data const& anno, QImage const& figure) :
		Annotation(Annotation::Type::FIGURE, anno),
		figure(figure)
	{

	}

	operator QImage const& () const
	{
		return figure;
	}

private:
	const QImage figure;
};
