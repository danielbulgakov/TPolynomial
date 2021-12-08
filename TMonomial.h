#pragma once
#include <vector>
#include <string>
#include <iostream>
class TMonomial
{
private:

	int Mult = 0;
	std::vector<std::pair<std::string, int>> Values;
	TMonomial* Next;

public:
	
	TMonomial(int mult, std::vector<std::pair<std::string, int>> values);
	void SetNext(TMonomial* next);
	TMonomial* GetNext();
	int GetMult();
	auto GetValues();
	void Print();
	friend std::ostream& operator<<(std::ostream& out, const TMonomial& ts);

};

