#pragma once
#include <vector>
#include <string>
#include <iostream>
class TMonomial
{
private:

	double Mult = 0;
	std::vector<std::pair<std::string, int>> Values;
	TMonomial* Next;

public:
	
	TMonomial(double mult, std::vector<std::pair<std::string, int>> values);

	
	TMonomial& operator*=(double a);
	TMonomial& operator/=(double a);

	void SetNext(TMonomial* next);
	TMonomial* GetNext();
	double GetMult();
	auto GetValues();
	void Print();
	friend std::ostream& operator<<(std::ostream& out, const TMonomial& ts);

};

