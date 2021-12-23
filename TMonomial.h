#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>
class TMonomial
{
private:

	double Mult = 0;
	std::vector<std::pair<std::string, int>> Values;
	TMonomial* Next;

	std::pair<std::string, int> GetPair(std::string value);

public:
	TMonomial(const TMonomial& tmnl);
	
	TMonomial(double mult, std::vector<std::pair<std::string, int>> values);
	void SetNext(TMonomial* next);
	void SetMult(double value);
	
	TMonomial* GetNext() const;
	double GetMult() const ;
	std::vector<std::pair<std::string, int>> GetValues() const ;

	TMonomial& operator=(const TMonomial& monom);
	
	TMonomial operator*(const TMonomial& monom);
	TMonomial operator/(const TMonomial& monom);

	TMonomial& operator*=(const double a);
	TMonomial& operator/=(const double a);

	TMonomial& operator*=(const std::string name);
	TMonomial& operator/=(const std::string name);

	TMonomial operator*(const double a);
	TMonomial operator/(const double a);

	TMonomial operator*(const std::string name);
	TMonomial operator/(const std::string name);
	
	double Evaluate(const std::map<std::string, double>& KeyMap);
	TMonomial Pow(uint32_t Power);
	bool isEqual(TMonomial& monom);
	void SortValues();
	
	void Print();
	friend std::ostream& operator<<(std::ostream& out, const TMonomial& ts);

};

