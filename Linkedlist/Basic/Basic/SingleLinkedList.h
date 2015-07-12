#include "Element.h"

class SingleLinkedList
{
	private:
		IntElement* _pHeadElement;

		IntElement* _createElement(int iaValue);		

	public:
		SingleLinkedList();

		~SingleLinkedList();

		void AddElementAtFront(int iaValue);

		void AddElement(int iaValue);

		void AddElementAtPosition(int iaValue, int iaPosition);
				
		void DisplayElements();	
};