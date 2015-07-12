#include <iostream>

using namespace std;

class IntElement
{
	private:
		IntElement* _next;
		int _data;

	public:
		IntElement(int aValue);

		~IntElement();

		IntElement* getNextElement() const;

		int getValue() const;

		void setNextElement(IntElement* apElement);

		void setValue(int aValue);
};