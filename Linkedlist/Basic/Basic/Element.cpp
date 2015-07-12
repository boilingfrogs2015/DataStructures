#include "Element.h"

IntElement::IntElement(int aValue)
{
	_next = NULL;
	_data = aValue;
}

IntElement::~IntElement()
{
}

IntElement* IntElement::getNextElement() const
{
	return _next;
}

int IntElement::getValue() const
{
	return _data;
}

void IntElement::setNextElement(IntElement* apElement)
{
	_next = apElement;
}

void IntElement::setValue(int aValue)
{
	_data = aValue;
}