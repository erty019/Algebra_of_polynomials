#pragma once
#include "THeadList.h"
#include "TMonom.h"
#include <string>

const int nonDisplayedZeros = 4; // Количество неотображаемых нулей при выводе коэффициента полинома
								 // Кол-во символов после запятой = 6 - nonDisplayedZeros

const double EPSILON = 1e-6;
class TPolinom : public THeadList<TMonom>
{
public:
	TPolinom();
	TPolinom(TPolinom& other);
	TPolinom(string str);
	TPolinom& operator=(TPolinom& other); // присваивание
	TPolinom& operator+(TPolinom& q); // сложение полиномов

	// дополнительно можно реализовать:
	void AddMonom(TMonom newMonom); // добавление монома
	TPolinom MultMonom(TMonom monom); // умножение мономов
	TPolinom AddPolinom(TPolinom& other); // добавление полинома
	TPolinom operator*(double coef); // умножение полинома на число
	TPolinom operator* (TPolinom& other); // умножение полиномов
	bool operator==(TPolinom& other); // сравнение полиномов на равенство
	string ToString(); // перевод в строку
};

TPolinom::TPolinom() :THeadList<TMonom>::THeadList()
{
	length = 0;
}

TPolinom::TPolinom(TPolinom& other)
{
	pHead = new TNode<TMonom>;
	TNode<TMonom>* h = other.pHead->pNext;
	while (h != other.pStop) {
		this->AddMonom(h->value);
		h = h->pNext;
	}
}

TPolinom::TPolinom(string str)
{	
	size_t pos = 0;
	while (pos < str.length()) {
		double coef = 0.0;
		int degX = 0, degY = 0, degZ = 0;
		char var;
		if (isdigit(str[pos]) || str[pos] == '-' || str[pos] == '+') {
			size_t nextPos;
			coef = stod(str.substr(pos), &nextPos);
			pos += nextPos;
		}
		while (pos < str.length() && (str[pos] == 'x' || str[pos] == 'X' ||
			str[pos] == 'y' || str[pos] == 'Y' ||
			str[pos] == 'z' || str[pos] == 'Z')) {
			var = tolower(str[pos]);
			pos++;
			if (pos < str.length() && str[pos] == '^') {
				pos++;
				size_t nextPos;
				int deg = stoi(str.substr(pos), &nextPos);
				pos += nextPos;
				switch (var) {
				case 'x': degX = deg; break;
				case 'y': degY = deg; break;
				case 'z': degZ = deg; break;
				}
			}
			else {
				switch (var) {
				case 'x': degX = 1; break;
				case 'y': degY = 1; break;
				case 'z': degZ = 1; break;
				}
			}
		}
		this->AddMonom(TMonom(coef, degX, degY, degZ));
	}
}

TPolinom& TPolinom::operator=(TPolinom& other)
{
	if (this != &other) {
		while (!this->IsEmpty()) {
			this->DeleteFirst();
		}
		TNode<TMonom>* current = other.pHead->pNext;
		while (current != nullptr) {
			this->AddMonom(current->value);
			current = current->pNext;
		}
	}
	return *this;
}

void TPolinom::AddMonom(TMonom m)
{
	if (m.coef == 0) throw invalid_argument(" ");
	this->Reset();
	bool isAdded = false;
	while (!this->IsEnd()) {
		if (this->pCurrent->value.index == m.index) {
			this->pCurrent->value.coef += m.coef;
			if (fabs(this->pCurrent->value.coef) < EPSILON) {
				this->DeleteCurrent();
			}
			isAdded = true;
			break;
		}
		this->GoNext();
	}
	if (!isAdded) this->InsertLast(m);
	pHead->pNext = this->pFirst;
}

TPolinom TPolinom::MultMonom(TMonom monom)
{
	TPolinom res(*this);
	TNode<TMonom>* current = res.pHead->pNext;
	while (current != nullptr) {
		current->value.coef *= monom.coef;
		current->value.index += monom.index;
		current = current->pNext;
	}
	return res;
}

TPolinom& TPolinom::operator+(TPolinom& other)
{
	if (other.IsEmpty()) throw invalid_argument(" ");
	TNode<TMonom>* current = other.pHead->pNext;
	while (current != nullptr) {
		this->AddMonom(current->value);
		current = current->pNext;
	}
	return *this;
}

TPolinom TPolinom::AddPolinom(TPolinom& other)
{
	
	return *this;
}

TPolinom TPolinom::operator*(double coef)
{
	if (this->IsEmpty()) throw invalid_argument(" ");
	TNode<TMonom>* current = this->pHead->pNext;
	while (current != nullptr) {
		current->value.coef *= coef;
		if (current->pNext == nullptr) break;
		current = current->pNext;
	}
	return *this;
}

TPolinom TPolinom::operator*(TPolinom& other)
{
	return *this;
}

bool TPolinom::operator==(TPolinom& other)
{
	if (this->GetLength() != other.GetLength()) return false;
	TNode<TMonom>* thisCurrent = this->pHead->pNext;
	TNode<TMonom>* otherCurrent = other.pHead->pNext;
	while (thisCurrent != nullptr && otherCurrent != nullptr) {
		if (!(thisCurrent->value == otherCurrent->value)) { return false; }
		thisCurrent = thisCurrent->pNext;
		otherCurrent = otherCurrent->pNext;
	}
	return thisCurrent == otherCurrent;
	
}


string TPolinom::ToString()
{
	string result;
	TNode<TMonom>* current = this->pHead->pNext;
	while (current != nullptr) {
		int degX = current->value.index % 10;
		int degY = (current->value.index / 10) % 10;
		int degZ = current->value.index / 100;
		if (!result.empty()) result += (current->value.coef > 0) ? " + " : " - ";
		else if (current->value.coef < 0) { result += "-"; }
		result += to_string(abs(current->value.coef));
		if (degX > 0) {
			result += "x";
			if (degX > 1) {
				result += "^" + to_string(degX);
			}
		}
		if (degY > 0) {
			result += "y";
			if (degY > 1) {
				result += "^" + to_string(degY);
			}
		}
		if (degZ > 0) {
			result += "z";
			if (degZ > 1) {
				result += "^" + to_string(degZ);
			}
		}
		current = current->pNext;
	}

	return result;
}
