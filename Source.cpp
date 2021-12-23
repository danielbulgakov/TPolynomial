#include <iostream>
#include <vector>
#include <map>

#include "TPolynomial.h"

int main() {

	std::map<std::string, double> HashMap = { {"a", 1}, {"b" , 2}, {"c", 3},{"e", 3}, {"f", 3}};

	std::vector<std::pair<std::string, int>> Values = { {"a",1} };
	std::vector<std::pair<std::string, int>> Values1 = { {"c",1} };
	std::vector<std::pair<std::string, int>> Values3 = { {"b",1} };

	int mult = -3;
	
	TPolynomial Polynom1;
	TPolynomial Polynom;

	Polynom1.Add(1, Values);
	Polynom1.Add(1, Values1);
	Polynom1.Add(1, Values3);

	Polynom.Add(1, Values);
	Polynom.Add(1, Values3);



	Polynom = Polynom1 / Polynom1;

	//Polynom.Add(1,Values);


	

	//Polynom.Div(1, Values1);
	//Polynom *= "a^2";


	//Polynom.Push_back(1, Values2);


	//Polynom /= "a^2";
	//Polynom *= "b^-3"; // Прочитать ситуацию, когда b^(-3)

	//Polynom /= 3;
	//Polynom *= -3;

	//Polynom /= 5;
	//Polynom = Polynom * 5;
	//Polynom /= "g^2";

	Polynom.Print();

	std::cout << std::endl;
	std::cout << "Result = " << Polynom.Evaluate(HashMap);
	std::cout << std::endl;

	//Polynom.Print();

	// x + x^2 + x^3 + x^2 изменить коэф
	// Посчитать значение полинома      (ready)
	// Умножить / разделить на число    (ready)
	// Умножать / делить на переменную  (ready)
	// Учитывать сокращение при добавлении
	// Возведение полинома в степень 


	return 0;
}