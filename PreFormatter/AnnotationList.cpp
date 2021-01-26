#include "AnnotationList.h"



void AnnotationList::sort()
{
	std::sort(this->begin(), this->end(),
		[](const Annotation* a, const Annotation* b)
		{
			bool pageCompare = a->pageNumber() < b->pageNumber();
			bool retn = pageCompare;


			if (a->pageNumber() == b->pageNumber()) {
				bool yPosition = a->position().y() < b->position().y();
				retn = yPosition;

				if (a->position().y() == b->position().y()) {
					bool xPosition = a->position().x() < b->position().x();
					retn = xPosition;
				}
			}
			return retn;
		});
}






 