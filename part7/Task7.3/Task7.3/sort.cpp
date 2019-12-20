#include <string.h>

#include "sort.h"

bool less(ListElement* element1, ListElement* element2, bool byPhone)
{
	if (byPhone)
	{
		return strcmp(fieldPhone(element1), fieldPhone(element2)) < 0;
	}
	else
	{
		return strcmp(fieldName(element1), fieldName(element2)) < 0;
	}
}

void mergeSort(List* list, ListElement* head, ListElement* tail, bool byPhone)
{
	if (head == tail || isEmpty(list))
	{
		return;
	}

	ListElement* leftDelimetr = head;
	ListElement* rightDelimetr = tail;

	while (shiftNext(leftDelimetr) != rightDelimetr && shiftNext(leftDelimetr) != shiftPrev(rightDelimetr))
	{
		leftDelimetr = shiftNext(leftDelimetr);
		rightDelimetr = shiftPrev(rightDelimetr);
	}
	if (shiftNext(leftDelimetr) == shiftPrev(rightDelimetr))
	{
		leftDelimetr = shiftNext(leftDelimetr);
	}
	mergeSort(list, head, leftDelimetr, byPhone);
	mergeSort(list, rightDelimetr, tail, byPhone);

	List* bufferList = create();
	ListElement* leftHelper = head;
	ListElement* rightHelper = rightDelimetr;

	while (leftHelper != rightDelimetr || rightHelper != shiftNext(tail))
	{
		if ((rightHelper == shiftNext(tail) || less(leftHelper, rightHelper, byPhone)) && leftHelper != rightDelimetr)
		{
			addElement(fieldName(leftHelper), fieldPhone(leftHelper), bufferList);
			leftHelper = shiftNext(leftHelper);
		}
		else
		{
			addElement(fieldName(rightHelper), fieldPhone(rightHelper), bufferList);
			rightHelper = shiftNext(rightHelper);
		}
	}
	
	ListElement* bufferHelper = headPointer(bufferList);
	ListElement* listHelper = head;
	while (bufferHelper != nullptr)
	{
		copyFields(&listHelper, &bufferHelper);
		listHelper = shiftNext(listHelper);
		bufferHelper = shiftNext(bufferHelper);
	}
	deleteList(bufferList);
}