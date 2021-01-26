#pragma once
#include "Annotation.h"


class AnnotationList : public QList<Annotation*>
{


public:
	AnnotationList() = default;

	void sort();


};
