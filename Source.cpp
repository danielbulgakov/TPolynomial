#include <iostream>
#include <vector>

#include "TPolynomial.h"

int main() {

	std::vector<std::pair<std::string, int>> Values = { { "x",5 } , {"x",7} };
	std::vector<std::pair<std::string, int>> Values1 = { { "z",3 } , {"v",1} };
	int mult = -3;
	
	TPolynomial Polynom;

	Polynom.Push_back(6, Values);
	Polynom.Push_back(-9, Values);
	Polynom.Push_back(18, Values);

	Polynom /= 3;
	Polynom *= -3;

	Polynom.Print();

	//Polynom.Print();

	

	return 0;
}