#include "TMonomial.h"

TMonomial::TMonomial(double mult, std::vector<std::pair<std::string, int>> values)
{
	this->Mult = mult;
	this->Values = values;
}


TMonomial& TMonomial::operator*=(double a)
{
	this->Mult *= a;
	return *this;
}

TMonomial& TMonomial::operator/=(double a)
{
	this->Mult /= a;
	return *this;
}

void TMonomial::SetNext(TMonomial* next)
{
	this->Next = next;
}

TMonomial* TMonomial::GetNext()
{
	return Next;
}

double TMonomial::GetMult()
{
	return this->Mult;
}

auto TMonomial::GetValues()
{
	return this->Values;
}

void TMonomial::Print()
{
	std::cout << Mult << "*";
	for (auto elem : Values) {
		std::cout << elem.first << "^" << elem.second << (elem != Values.back() ? "*" : std::string());
	}
}

std::ostream& operator<<(std::ostream& out, const TMonomial& ts)
{

	std::cout << (ts.Mult < 0 ? "(" : std::string()) << ts.Mult 
		<< (ts.Mult < 0 ? ")" : std::string()) << "*";
	for (auto elem : ts.Values) {
		std::cout << elem.first << "^" << elem.second << (elem != ts.Values.back() ? "*" : std::string());
	}
	return out;
}
