#include "SingleLinkedList.h"

IntElement* SingleLinkedList::_createElement(int iaValue)
{
	IntElement* pNewElement = new IntElement(iaValue);
	return pNewElement;
}

SingleLinkedList::SingleLinkedList()
{
	_pHeadElement = NULL;
}

SingleLinkedList::~SingleLinkedList()
{
	// Traverse through the list and delete the memory allocated for each element.
	IntElement* pNextElement = NULL;
	while (_pHeadElement)
	{
		pNextElement = _pHeadElement->getNextElement();
		delete _pHeadElement;

		_pHeadElement = pNextElement;
	}
}

void SingleLinkedList::AddElementAtFront(int iaValue)
{
	IntElement* newElement = _createElement(iaValue);
	if (!_pHeadElement)
	{
		_pHeadElement = newElement;
	}
	else
	{
		newElement->setNextElement(_pHeadElement);
		_pHeadElement = newElement;
	}
}

void SingleLinkedList::AddElement(int iaValue)
{
	IntElement* newElement = _createElement(iaValue);
	
	if (!_pHeadElement)
	{
		_pHeadElement = newElement;
		_pHeadElement->setNextElement(NULL);
	}
	else
	{
		IntElement* pTemp = _pHeadElement;
		IntElement* pPreviousElement = NULL;
	
		while (pTemp)
		{
			pPreviousElement = pTemp;
			pTemp = pTemp->getNextElement();
		}
	
		pPreviousElement->setNextElement(newElement);
	}
}

void SingleLinkedList::AddElementAtPosition(int iaValue, int iaPosition)
{			
	if ( iaPosition <= 0 )
	{
		return;
	}

	// This is equivalent to adding first element as well 
	if (iaPosition == 1)
	{
		IntElement* newElement = _createElement(iaValue);
		newElement->setNextElement(_pHeadElement);
		_pHeadElement = newElement;
		return;
	}		
		
	int iCount = 1;
	IntElement* pPreviousElement = NULL;
	IntElement* pTraverseElement =_pHeadElement;

	while (pTraverseElement != NULL && iCount != iaPosition)
	{
		pPreviousElement = pTraverseElement;
		pTraverseElement = pTraverseElement->getNextElement();
		iCount += 1;
	}

	if( iCount == iaPosition)
	{
		IntElement* newElement = _createElement(iaValue);

		pPreviousElement->setNextElement(newElement);
		newElement->setNextElement(pTraverseElement);
	}
	else
	{
		cout << "Invalid position" << endl;
	}
}
		
void SingleLinkedList::DisplayElements()
{
	IntElement* pTraverseElement = _pHeadElement;
	while (pTraverseElement)
	{
		cout << pTraverseElement->getValue();
		cout << "\t";
		pTraverseElement = pTraverseElement->getNextElement();
	}
}
