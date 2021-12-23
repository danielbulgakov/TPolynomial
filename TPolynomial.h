#pragma once
#include "TMonomial.h"
class TPolynomial
{
private:

	TMonomial* Head;
	size_t Size;


	void Push_front(double mult, std::vector<std::pair<std::string, int>> values);
	void Push_back(double mult, std::vector<std::pair<std::string, int>> values);

	TPolynomial operator*(TMonomial& monom);
	TPolynomial operator/(TMonomial& monom);

	TPolynomial& operator*=(TMonomial& monom);
	TPolynomial& operator/=(TMonomial& monom);
public:

	TPolynomial(const TPolynomial& tpl);
	TPolynomial();
	~TPolynomial();

	TMonomial& GetElement(size_t index);
	TMonomial& GetElement(size_t index) const;
	size_t GetSize();

	TMonomial& operator[](size_t index);
	TPolynomial& operator=(const TPolynomial tmp);

	TPolynomial& operator*=(const double a);
	TPolynomial& operator/=(const double a);

	TPolynomial& operator*=(const std::string name);
	TPolynomial& operator/=(const std::string name);


	TPolynomial operator*(const double a);
	TPolynomial operator/(const double a);

	TPolynomial operator*(const std::string name);
	TPolynomial operator/(const std::string name);

	TPolynomial operator*(const TPolynomial& polynom);


	TPolynomial& operator*=(const TPolynomial& polynom);



	void Add(double mult, std::vector<std::pair<std::string, int>> values);
	void Mult(double mult, std::vector<std::pair<std::string, int>> values);
	void Div(double mult, std::vector<std::pair<std::string, int>> values);


	double Evaluate(const std::map<std::string, double> &KeyMap);
	TPolynomial Pow(uint32_t power);
	

	void Print();
};

