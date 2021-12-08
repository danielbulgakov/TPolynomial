#include <iostream>
#include <vector>
#include "TMonomial.h"

int main() {

	std::vector<std::pair<std::string, int>> Values = { { "x",5 } , {"x",7} };
	int mult = 3;
	TMonomial ex(mult, Values);
	ex.Print();


	

	return 0;
}