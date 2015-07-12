#include "SingleLinkedList.h"

void main()
{
	SingleLinkedList objSingleLinkedList;

	objSingleLinkedList.AddElement(10);
	objSingleLinkedList.AddElement(20);
	objSingleLinkedList.AddElementAtPosition(5, 2);
	//objSingleLinkedList.AddElementAtFront(5);
	
	objSingleLinkedList.DisplayElements();

	cout << endl << endl;
}