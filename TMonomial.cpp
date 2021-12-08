#include "TMonomial.h"

TMonomial::TMonomial(int mult, std::vector<std::pair<std::string, int>> values)
{
	this->Mult = mult;
	this->Values = values;
}

void TMonomial::SetNext(TMonomial* next)
{
	this->Next = next;
}

int TMonomial::GetMult()
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
		std::cout << elem.first << "^" << elem.second << (elem != Values.back() ? "*" : "");
	}
}
