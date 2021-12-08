#pragma once
#include "TMonomial.h"
class TPolynomial
{
private:
	TMonomial* Head;
	size_t Size;

	TMonomial& GetElement(size_t index);

public:
	TPolynomial();

	TMonomial& operator[](size_t index);

	size_t GetSize();
	void Push_front(int mult, std::vector<std::pair<std::string, int>> values);
	void Push_back(int mult, std::vector<std::pair<std::string, int>> values);
	void Print();
};

