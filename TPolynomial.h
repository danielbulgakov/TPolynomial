#pragma once
#include "TMonomial.h"
class TPolynomial
{
private:
	TMonomial* Head;
	size_t Size;

	TMonomial& GetElement(size_t index);
	TPolynomial(const TPolynomial& tpl);

	void Push_front(double mult, std::vector<std::pair<std::string, int>> values);
	void Push_back(double mult, std::vector<std::pair<std::string, int>> values);

public:

	TPolynomial();
	~TPolynomial();

	size_t GetSize();

	TMonomial& operator[](size_t index);
	
	TPolynomial& operator*=(const double a);
	TPolynomial& operator/=(const double a);

	TPolynomial& operator*=(const std::string name);
	TPolynomial& operator/=(const std::string name);

	TPolynomial operator*(const double a);
	TPolynomial operator/(const double a);

	TPolynomial operator*(const std::string name);
	TPolynomial operator/(const std::string name);

	void Add(double mult, std::vector<std::pair<std::string, int>> values);

	double Evaluate(const std::map<std::string, double> &KeyMap);
	TPolynomial Pow(uint32_t power);
	std::vector<uint32_t> PascalTriangle(size_t row);

	void Print();
};

