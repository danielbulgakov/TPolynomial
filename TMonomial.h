#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <cmath>
class TMonomial
{
private:

	double Mult = 0;
	std::vector<std::pair<std::string, int>> Values;
	TMonomial* Next;

	std::pair<std::string, int> GetPair(std::string value);
	TMonomial(const TMonomial& tmnl);

public:
	
	TMonomial(double mult, std::vector<std::pair<std::string, int>> values);
	

	
	TMonomial& operator*=(double a);
	TMonomial& operator/=(double a);

	TMonomial& operator*=(std::string name);
	TMonomial& operator/=(std::string name);

	TMonomial operator*(double a);
	TMonomial operator/(double a);

	TMonomial operator*(std::string name);
	TMonomial operator/(std::string name);
	

	double Evaluate(const std::map<std::string, double>& KeyMap);
	void SetNext(TMonomial* next);
	TMonomial* GetNext();
	double GetMult();
	auto GetValues();
	void Print();
	friend std::ostream& operator<<(std::ostream& out, const TMonomial& ts);

};

