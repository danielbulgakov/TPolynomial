#include <iostream>
#include <vector>

#include "TPolynomial.h"

int main() {

	std::vector<std::pair<std::string, int>> Values = { { "x",5 } , {"x",7} };
	std::vector<std::pair<std::string, int>> Values1 = { { "z",3 } , {"v",1} };
	int mult = -3;
	
	TPolynomial Polynom;

	Polynom.Push_back(mult, Values);
	Polynom.Push_back(mult, Values);
	Polynom.Push_back(mult, Values);
	Polynom.Push_back(mult, Values);
	Polynom.Push_back(mult, Values);
	Polynom.Push_back(mult, Values);
	Polynom.Push_back(mult, Values);
	Polynom.Push_front(-1, Values1);

	std::cout << Polynom[0];

	//Polynom.Print();

	

	return 0;
}