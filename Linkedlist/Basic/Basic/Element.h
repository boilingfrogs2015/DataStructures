#include <iostream>

using namespace std;

class IntElement
{
	private:
		IntElement* _next;
		int _data;

	public:
		IntElement(int aValue)
		{
			_next = NULL;
			_data = aValue;
		}

		~IntElement()
		{
		
		}

		IntElement* getNextElement() const
		{
			return _next;
		}

		int getValue() const
		{
			return _data;
		}

		void setNextElement(IntElement* apElement)
		{
			_next = apElement;
		}

		void setValue(int aValue)
		{
			_data = aValue;
		}
};