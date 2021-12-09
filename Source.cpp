#include <iostream>
#include <vector>

#include "TPolynomial.h"

int main() {

	std::vector<std::pair<std::string, int>> Values = { { "a", 2} , {"b",3 } };
	std::vector<std::pair<std::string, int>> Values1 = { { "c",4 } , {"d",5} };
	std::vector<std::pair<std::string, int>> Values2 = { { "e",6 } , {"f",7} };

	int mult = -3;
	
	TPolynomial Polynom;

	Polynom.Push_back(5, Values);
	Polynom.Push_back(1, Values1);
	Polynom.Push_back(1, Values2);


	Polynom /= "a^2";
	Polynom *= "b^-3";

	//Polynom /= 3;
	//Polynom *= -3;

	//Polynom /= 5;
	//Polynom = Polynom * 5;
	//Polynom /= "g^2";

	Polynom.Print();

	//Polynom.Print();

	
	// Посчитать значение полинома
	// Умножить / разделить на число    (ready)
	// Умножать / делить на переменную  (ready)
	// Возведение полинома в степень


	return 0;
}