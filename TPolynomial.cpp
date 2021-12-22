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

TPolynomial::TPolynomial(const TPolynomial& tpl)
{
	this->Head = tpl.Head;
	this->Size = tpl.Size;
}

TPolynomial::TPolynomial()
{
	this->Head = nullptr;
	this->Size = 0;
}

TPolynomial::~TPolynomial()
{
	TMonomial* Next = nullptr;

	while (Head != nullptr) {
		Next = Head->GetNext();
		delete Head;
		Head = Next;
	} 

}

double TPolynomial::Evaluate(const std::map<std::string, double>& KeyMap)
{
	double Answer = 0;

	for (size_t i = 0; i < Size; i++){
		Answer += GetElement(i).Evaluate(KeyMap);
	}
	return Answer;
}

TPolynomial TPolynomial::Pow(uint32_t Power)
{
	if (Power > 20) throw std::runtime_error("Power is too big");
	TPolynomial tmp(*this);

	return tmp;
}

std::vector<uint32_t> TPolynomial::PascalTriangle(size_t row)
{
	std::vector<uint32_t> tmp;
	return std::vector<uint32_t>();
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

TPolynomial& TPolynomial::operator*=(const std::string name) {
	for (size_t i = 0; i < Size; i++) {
		GetElement(i) *= name;
	}
	return *this;
}

TPolynomial& TPolynomial::operator/=(const std::string name) {
	for (size_t i = 0; i < Size; i++) {
		GetElement(i) /= name;
	}
	return *this;
}

TPolynomial TPolynomial::operator*(const double a)
{
	TPolynomial tmp(*this);
	for (size_t i = 0; i < tmp.Size; i++) {
		tmp.GetElement(i) *= a;
	}
	return tmp;
}

TPolynomial TPolynomial::operator/(const double a)
{
	TPolynomial tmp(*this);
	for (size_t i = 0; i < tmp.Size; i++) {
		tmp.GetElement(i) /= a;
	}
	return tmp;
}

TPolynomial TPolynomial::operator*(const std::string name) {
	TPolynomial tmp(*this);
	for (size_t i = 0; i < tmp.Size; i++) {
		tmp.GetElement(i) *= name;
	}
	return tmp;
}

TPolynomial TPolynomial::operator/(const std::string name) {
	TPolynomial tmp(*this);
	for (size_t i = 0; i < tmp.Size; i++) {
		tmp.GetElement(i) /= name;
	}
	return tmp;
}

void TPolynomial::Add(double mult, std::vector<std::pair<std::string, int>> values)
{
	Push_back(mult, values);
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
		if (this->Size == 1) {
			if (tmp->isEqual(*nMonom)) {
				tmp->SetMult(tmp->GetMult() + (*nMonom).GetMult());
				return;
			}
		}
		while (tmp->GetNext() != nullptr) {
			tmp = tmp->GetNext();
			if (tmp->isEqual(*nMonom)) {
				tmp->SetMult(tmp->GetMult() + (*nMonom).GetMult());
				return;
			}
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