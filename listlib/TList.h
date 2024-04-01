#pragma once
#include "TNode.h"
#include <iostream>
using namespace std;

template<class T>
class TList
{
protected:
	TNode<T>* pFirst; // первое звено
	TNode<T>* pCurrent; // текущее звено
	TNode<T>* pPrevious; // звено перед текущим
	TNode<T>* pLast; // последнее звено
	TNode<T>* pStop; // значение указателя, означающего конец списка
	int length; // количество звеньев в списке

public:

	TList();
	~TList();
	int GetLength() { return length; }
	bool IsEmpty(); // список пуст ?
	// вставка звеньев
	void InsertFirst(T item); // перед первым
	void InsertCurrent(T item); // перед текущим 
	void InsertLast(T item);  // вставить последним 

	// удаление звеньев
	void DeleteFirst(); // удалить первое звено 
	void DeleteCurrent(); // удалить текущее звено

	void GoNext(); // сдвиг вправо текущего звена
	// (=1 после применения GoNext для последнего звена списка)

	void Reset(); // установить на начало списка
	bool IsEnd();  // список завершен ?

	T GetCurrentItem();
	void SetCurrentItem(T item) { pCurrent->value = item; }


};
template <class T>
TList<T>::TList()
{
	pFirst = nullptr;
	pCurrent = nullptr;
	pPrevious = nullptr;
	pLast = nullptr;
	pStop = nullptr;
	length = 0;
}

template <class T>
TList<T>::~TList()
{
}

template <class T>
bool TList<T>::IsEmpty()
{
	return pFirst == nullptr;
}

template <class T>
void TList<T>::InsertFirst(T item)
{
	TNode<T>* New_Node = new TNode<T>{ item, pFirst };
	pFirst = New_Node;
	if (length == 0) { pLast = pFirst }
	length++;
}

template <class T>
void TList<T>::InsertLast(T item)
{
	TNode<T>* New_Node = new TNode<T>{ item, nullptr };
	if (IsEmpty()) { pFirst = pLast = New_Node; }
	else {
		pLast->pNext = New_Node;
		pLast = New_Node;
	}
	length++;


}

template <class T>
void TList<T>::InsertCurrent(T item)
{
	if (pCurrent == nullptr || pCurrent == pFirst) {
		InsertFirst(item);
		return;
	}
	TNode<T>* New_Node = new TNode<T>{ item, pCurrent };
	pPrevious->pNext = New_Node;
	length++;
}

template <class T>
void TList<T>::DeleteFirst()
{
	if (IsEmpty()) throw runtime_error("List is empty");
	TNode<T>* temp = pFirst;
	pFirst = pFirst->pNext;
	if (pFirst == nullptr) pLast = nullptr;
	delete temp;
	length--;
}

template <class T>
void TList<T>::DeleteCurrent()
{
	if (pCurrent == nullptr) throw runtime_error("Current node is null");
	if (pCurrent == pFirst) {
		DeleteFirst();
		return;
	}
	if (pCurrent == pLast) {
		delete pCurrent;
		pPrevious->pNext = nullptr;
		pLast = pPrevious;
		pCurrent = nullptr;
	}
	else {
		pPrevious->pNext = pCurrent->pNext;
		delete pCurrent;
		pCurrent = pPrevious->pNext;
	}
}

template <class T>
T TList<T>::GetCurrentItem()
{
	if (pCurrent == nullptr)
		throw " ";
	return pCurrent->value;
}

template <class T>
void TList<T>::Reset()
{
	pCurrent = pFirst;
	pPrevious = nullptr;
}

template <class T>
void TList<T>::GoNext()
{
	if (pCurrent != nullptr)
	{
		pPrevious = pCurrent;
		pCurrent = pCurrent->pNext;

		if (pCurrent == nullptr)
		{
			pLast = pPrevious;
		}
	}
}

template <class T>
bool TList<T>::IsEnd()
{
	return pCurrent == pStop;
}





