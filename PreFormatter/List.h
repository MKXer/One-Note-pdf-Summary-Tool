#pragma once
#include "SummaryElement.h"



class List : public SummaryElement
{
public:
	List();

	List& operator<<(QString const& listItem);

	

private:

};
