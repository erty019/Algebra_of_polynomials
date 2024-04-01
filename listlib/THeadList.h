#pragma once
#include "TList.h"
using namespace std;


template<class T>
class THeadList : public TList<T>
{
protected:
	TNode<T>* pHead;  // заголовок, pFirst - звено за pHead
public:
	THeadList();
	~THeadList();
	void InsertFirst(T item); // вставка звеньев после заголовка
	void DeleteFirst(); // удалить первое звено
};

template<class T>
THeadList<T>::THeadList()
{
	pHead = new TNode<T>();
	if (pHead == nullptr) throw bad_alloc();
	this->pLast = pHead;
	pHead->pNext = this->pFirst;
}

template<class T>
THeadList<T>::~THeadList(){ delete pHead; }

template <class T>
void THeadList<T>::InsertFirst(T item)
{
	TNode<T>* pNode = new TNode<T>{ item, nullptr };

	if (newNode == nullptr) throw bad_alloc();
	newNode->pNext = pHead->pNext;
	pHead->pNext = newNode;
	if (this->IsEmpty()) {
		this->pLast = newNode;
	}
	this->length++;
}

template <class T>
void THeadList<T>::DeleteFirst()
{
	if (this->pFirst == nullptr) throw runtime_error("List is empty");
	TNode<T>* temp = this->pFirst;
	this->pFirst = this->pFirst->pNext;
	if (this->pFirst == nullptr) {
		this->pLast = nullptr;
	}
	if (this->pCurrent == temp) {
		this->pCurrent = this->pFirst;
		this->pPrevious = nullptr;
	}
	delete temp;
	this->length--;
}