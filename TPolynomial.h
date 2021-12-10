#pragma once
#include "TMonomial.h"
class TPolynomial
{
private:
	TMonomial* Head;
	size_t Size;

	TMonomial& GetElement(size_t index);
	TPolynomial(const TPolynomial& tpl);

public:
	TPolynomial();

	TMonomial& operator[](size_t index);

	
	TPolynomial& operator*=(const double a);
	TPolynomial& operator/=(const double a);

	TPolynomial& operator*=(const std::string name);
	TPolynomial& operator/=(const std::string name);

	TPolynomial operator*(const double a);
	TPolynomial operator/(const double a);

	TPolynomial operator*(const std::string name);
	TPolynomial operator/(const std::string name);


	double Evaluate(const std::map<std::string, double> &KeyMap);
	size_t GetSize();
	void Push_front(double mult, std::vector<std::pair<std::string, int>> values);
	void Push_back(double mult, std::vector<std::pair<std::string, int>> values);
	void Print();
};

