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
	

	bool isListItem() const {
		return text.startsWith(bulletChar);
	}

	bool isRegularText() const {
		return getHeight() < 14;
	}


private:
	const QString text;

	const QChar bulletChar{ 0x2022 };


};


class Figure : public Annotation
{

public:
	Figure(Annotation::Data const& anno, QString const& filePath, QSize const& imageSize) :
		Annotation(Annotation::Type::FIGURE, anno),
		filePath(filePath),
		imageSize(imageSize)
	{

	}

	QString const& getFilePath() const {
		return filePath;
	}


	QSize const& getSize() const{
		return imageSize;
	}

private:
	
	const QString filePath;
	const QSize imageSize;
};
