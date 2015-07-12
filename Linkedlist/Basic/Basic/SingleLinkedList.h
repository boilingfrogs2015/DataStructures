#include "Element.h"

class SingleLinkedList
{
	private:
		IntElement* _pHeadElement;

		IntElement* _createElement(int iaValue)
		{
			IntElement* pNewElement = new IntElement(iaValue);
			return pNewElement;
		}

	public:
		SingleLinkedList()
		{
			_pHeadElement = NULL;
		}

		~SingleLinkedList()
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

		void AddElementAtFront(int iaValue)
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

		void AddElement(int iaValue)
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

		void ReverseLinkedList()
		{
			if (_pHeadElement == NULL)
				return;

			IntElement* pNewHead = _pHeadElement;
			IntElement* pNextElement = _pHeadElement->getNextElement();

			IntElement* pTemp = NULL;

			IntElement* pPreviousElement = _pHeadElement;
			pPreviousElement->setNextElement(NULL);

			while (pNextElement != NULL)
			{
				pTemp = pNextElement->getNextElement();

				pNewHead = pNextElement;
				pNewHead->setNextElement(pPreviousElement);

				pNextElement = pTemp;
				pPreviousElement = pNewHead;
			}	

			_pHeadElement = pNewHead;
		}

		void ReverseLinkedListOptimized()
		{
			IntElement* pCurrentElement = _pHeadElement;
			IntElement* pNextElement = NULL;
			IntElement* pPrevElement = NULL;

			while (pCurrentElement != NULL)
			{
				pNextElement = pCurrentElement->getNextElement();

				pCurrentElement->setNextElement(pPrevElement);

				pPrevElement = pCurrentElement;

				pCurrentElement = pNextElement;
			}	

			_pHeadElement = pPrevElement;			
		}

		void AddElementAtPosition(int iaValue, int iaPosition)
		{			
			if (iaPosition == 1)
			{
				IntElement* newElement = _createElement(iaValue);
				newElement->setNextElement(_pHeadElement);
				_pHeadElement = newElement;
			}
			
			if ( iaPosition <= 0 )
			{
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
		
		void DisplayElements()
		{
			IntElement* pTemp = _pHeadElement;
			while (pTemp)
			{
				cout << pTemp->getValue();
				cout << endl;
				pTemp = pTemp->getNextElement();

			}
		}
};