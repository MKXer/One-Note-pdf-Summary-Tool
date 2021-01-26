#include "Annotation.h"


Annotation::Annotation(Type type, Data const& annotationData) :
	type(type),
	data(annotationData)
{

}

double Annotation::getHeight() const {
	return data.rect.height();
}

bool Annotation::operator<(const Annotation& str) const
{
	bool isVerticalBelow = data.rect.topLeft().y() < str.data.rect.topLeft().y();
	//bool isOnTheLeft  = rect.topLeft().x() < str.rect.topLeft().x() ;

	return isVerticalBelow;
}



const QPointF Annotation::position() const {
	return data.rect.center();
}

ushort Annotation::pageNumber() const {
	return data.pageIdx + 1;
}



