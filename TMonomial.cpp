#include "TMonomial.h"

std::pair<std::string, int> TMonomial::GetPair(std::string value)
{
	auto index = value.find('^');
	if (index != std::string::npos) {
		return (std::make_pair(value.substr(0, index),
			stoi(value.substr(index + 1))));
	}
	return  (std::make_pair(value.substr(0, index),1));
}

TMonomial::TMonomial(double mult, std::vector<std::pair<std::string, int>> values)
{
	this->Mult = mult;
	this->Values = values;

	
}

TMonomial::TMonomial(double mult)
{
	this->Mult = Mult;
}

TMonomial::TMonomial(const TMonomial& tmnl)
{
	this->Mult = tmnl.Mult;
	this->Values = tmnl.Values;
	this->Next = tmnl.Next;

}


TMonomial& TMonomial::operator*=(const double a)
{
	this->Mult *= a;

	return *this;
}

TMonomial& TMonomial::operator/=(const double a)
{
	this->Mult /= a;

	return *this;
}

TMonomial& TMonomial::operator*=(const std::string name) {
	std::pair<std::string, int> pair = GetPair(name);
	for (auto& el : Values) {
		if (pair.first == el.first) {
			el.second += pair.second;

			if (el.second == 0) {
				auto it = std::find(Values.begin(), Values.end(), el);
				Values.erase(Values.begin() + distance(Values.begin(), it));
			}

			return *this;
		}
	}
	Values.push_back(pair);

	return *this;

}

TMonomial& TMonomial::operator/=(const std::string name) {
	std::pair<std::string, int> pair = GetPair(name);
	for (auto& el : Values) {
		if (pair.first == el.first) {
			el.second -= pair.second;

			if (el.second == 0) {
				auto it = std::find(Values.begin(), Values.end(), el);
				Values.erase(Values.begin() + distance(Values.begin(), it));
			}

			return *this;
		}


	}
	Values.push_back(std::make_pair(pair.first, pair.second * (-1)));

	return *this;

}

TMonomial TMonomial::operator*(const double a)
{
	TMonomial tmp(*this);
	tmp.Mult *= a;

	return tmp;
}

TMonomial TMonomial::operator/(const double a)
{
	TMonomial tmp(*this);
	tmp.Mult /= a;

	return tmp;
}

TMonomial TMonomial::operator*(const std::string name) {
	TMonomial tmp(*this);
	std::pair<std::string, int> pair = GetPair(name);
	for (auto& el : tmp.Values) {
		if (pair.first == el.first) {
			el.second += pair.second;

			if (el.second == 0) {
				auto it = std::find(tmp.Values.begin(), tmp.Values.end(), el);
				tmp.Values.erase(tmp.Values.begin() + distance(tmp.Values.begin(), it));
			}

			return tmp;
		}
	}
	tmp.Values.push_back(pair);

	return tmp;

}

TMonomial TMonomial::operator/(const std::string name) {
	TMonomial tmp(*this);
	std::pair<std::string, int> pair = GetPair(name);
	for (auto& el : tmp.Values) {
		if (pair.first == el.first) {
			el.second -= pair.second;

			if (el.second == 0) {
				auto it = std::find(tmp.Values.begin(), tmp.Values.end(), el);
				tmp.Values.erase(tmp.Values.begin() + distance(tmp.Values.begin(), it));
			}

			return tmp;
		}
	}
	tmp.Values.push_back(pair);

	return tmp;

}

double TMonomial::Evaluate(const std::map<std::string, double>& KeyMap)
{
	double Answer = this->Mult;

	for (const auto& value : Values) {
		if (KeyMap.find(value.first) == KeyMap.end()) throw  std::invalid_argument("Value not found");
		else {
			Answer *= pow(KeyMap.find(value.first)->second, value.second);
		}
	}

	return Answer;
}

TMonomial TMonomial::Pow(uint32_t Power)
{
	TMonomial tmp(*this);
	tmp.Mult = pow(tmp.Mult, Power);
	for (auto& el : tmp.Values) {
		el.second = pow(el.second, Power);
	}
	return tmp;
}

bool TMonomial::isEqual(TMonomial& monom)
{
	std::vector<std::pair<std::string, int>> Tmp = this->Values;
	std::vector<std::pair<std::string, int>> Tmp1 = monom.GetValues();
	std::sort(Tmp.begin(), Tmp.end());
	std::sort(Tmp1.begin(), Tmp1.end());

	if (Tmp == Tmp1) {
		this->Values = Tmp;
		return true;
	}
	return false;


}


void TMonomial::SetNext(TMonomial* next)
{
	this->Next = next;
}

void TMonomial::SetMult(double value)
{
	this->Mult = value;
}

TMonomial* TMonomial::GetNext() const
{
	return Next;
}

double TMonomial::GetMult() const
{
	return this->Mult;
}

std::vector<std::pair<std::string, int>> TMonomial::GetValues() const
{
	return this->Values;
}

TMonomial& TMonomial::operator=(const TMonomial& monom)
{
	this->Mult = monom.Mult;
	this->Values = monom.Values;
	this->Next = monom.Next;
	return *this;
}

TMonomial TMonomial::operator*(const TMonomial& monom)
{
	TMonomial tmp(*this);
	tmp.Mult *= monom.GetMult();
	for (auto el : monom.GetValues()) {
		bool Contains = false;
		std::pair<std::string, int> pair = el;
		for (auto& el : tmp.Values) {
			if (pair.first == el.first) {
				el.second += pair.second;
				Contains = true;
				if (el.second == 0) {
					auto it = std::find(tmp.Values.begin(), tmp.Values.end(), el);
					tmp.Values.erase(tmp.Values.begin() + distance(tmp.Values.begin(), it));
				}

				break;
			}
		}
		if (!Contains)
			tmp.Values.push_back(pair);
	}
	return tmp;
}

TMonomial TMonomial::operator/(const TMonomial& monom)
{
	TMonomial tmp(*this);
	tmp.Mult *= monom.GetMult();
	for (auto el : monom.GetValues()) {
		bool Contains = false;
		std::pair<std::string, int> pair = el;
		for (auto& el : tmp.Values) {
			if (pair.first == el.first) {
				el.second -= pair.second;
				Contains = true;
				if (el.second == 0) {
					auto it = std::find(tmp.Values.begin(), tmp.Values.end(), el);
					tmp.Values.erase(tmp.Values.begin() + distance(tmp.Values.begin(), it));
				}

				break;
			}
		}
		if (!Contains)
			tmp.Values.push_back(pair);
	}
	return tmp;
}

void TMonomial::Print()
{
	std::cout << Mult << "*";
	for (auto elem : Values) {
		std::cout << elem.first << "^" << elem.second << (elem != Values.back() ? "*" : std::string());
	}
}

std::ostream& operator<<(std::ostream& out, const TMonomial& ts)
{
	if (ts.Mult == 0 ) {
		std::cout << "0";
		return out;
	}
	if (ts.Mult != 1) {
		std::cout << (ts.Mult < 0 ? "(" : std::string()) << ts.Mult
			<< (ts.Mult < 0 ? ")" : std::string()) << "*";
	}
	if (ts.Values.size() == 0) {
		std::cout << (ts.Mult < 0 ? "(" : std::string()) << ts.Mult
			<< (ts.Mult < 0 ? ")" : std::string());
	}
	for (auto elem : ts.Values) {
		if ( elem != ts.Values[0])
			std::cout <<  "*" ;
		if (elem.second != 0) {
			std::cout << elem.first;
		}
		if (elem.second != 1 && elem.second != 0) {
			std::cout << "^" << (elem.second < 0 ? "(" : std::string()) << elem.second << (elem.second < 0 ? ")" : std::string());
		}

		
	}
	return out;
}
