#include <iostream>
#include <vector>
#include <map>

#include "TPolynomial.h"

int main() {

	std::map<std::string, double> HashMap = { {"a", 1}, {"b" , 2}, {"c", 3},{"e", 3}, {"f", 3}};

	std::vector<std::pair<std::string, int>> Values = { {"a",2} };
	std::vector<std::pair<std::string, int>> Values1 = { {"c",2} , {"b", 3} };
	std::vector<std::pair<std::string, int>> Values2 = { {"b",3} , {"c", 2} };

	int mult = -3;
	
	TPolynomial Polynom;
	Polynom.Add(1, Values);
	Polynom.Add(1, Values);
	Polynom.Add(1, Values);
	Polynom.Add(1, Values);
	Polynom.Add(1, Values);
	Polynom.Add(1, Values1);
	Polynom.Add(1, Values1);
	


	//Polynom.Push_back(1, Values2);


	//Polynom /= "a^2";
	//Polynom *= "b^-3"; // ��������� ��������, ����� b^(-3)

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

	// x + x^2 + x^3 + x^2 �������� ����
	// ��������� �������� ��������      (ready)
	// �������� / ��������� �� �����    (ready)
	// �������� / ������ �� ����������  (ready)
	// ��������� ���������� ��� ����������
	// ���������� �������� � ������� 


	return 0;
}