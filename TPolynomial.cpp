#include "TPolynomial.h"

TMonomial& TPolynomial::GetElement(size_t index)
{
	TMonomial* tmp = Head;
	if (index == 0) return *Head;
	for (size_t i = 0; i < index; i++) {
		tmp = tmp->GetNext();
	}
	return *tmp;
}


TPolynomial::TPolynomial()
{
	this->Head = nullptr;
	this->Size = 0;
}

size_t TPolynomial::GetSize()
{
	return Size;
}

TMonomial& TPolynomial::operator[](size_t index)
{
	return (const_cast<TMonomial&>(GetElement(index)));
}



TPolynomial& TPolynomial::operator*=(const double a)
{
	for (size_t i = 0; i < Size; i++) {
		GetElement(i) *= a;
	}
	return *this;
}


TPolynomial& TPolynomial::operator/=(const double a)
{
	for (size_t i = 0; i < Size; i++) {
		GetElement(i) /= a;
	}
	return *this;
}

void TPolynomial::Push_front(double mult, std::vector<std::pair<std::string, int>> values)
{
	TMonomial* nMonom = new TMonomial(mult, values);
	nMonom->SetNext(Head);
	this->Head = nMonom;
	this->Size++;
}

void TPolynomial::Push_back(double  mult, std::vector<std::pair<std::string, int>> values) {
	TMonomial* nMonom = new TMonomial(mult, values);
	if (this->Head == nullptr) {
		Head = nMonom;
	}
	else {
		TMonomial* tmp = Head;
		while (tmp->GetNext() != nullptr) {
			tmp = tmp->GetNext();
		}
		tmp->SetNext(nMonom);
	}
	this->Size++;
}

void TPolynomial::Print()
{
	for (size_t i = 0; i < Size; i++) {

		std::cout <<
			(i != 0 ? " + " : std::string()) <<
			GetElement(i);
			
	}
}