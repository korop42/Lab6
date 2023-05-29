#include "Header.h"

int CountryTree::num_countryTree = 0;

CountryTree::CountryTree() : Tree()
{
	num_countryTree++;
	country = "Whole world";
}

CountryTree::CountryTree(string n, string c, int a, string count) : Tree(n, c, a)
{
	num_countryTree++;
	country = count;
}

void CountryTree::Print(string msg)
{
	cout << "\nCountry Tree:";
	Tree::Print(" ");
	cout << setw(w) << country << msg;
}

string CountryTree::toString() const
{
	ostringstream oss;
	oss << Base::getName()
		<< Base::getColor()
		<< Tree::getAge()
		<< country;
	return oss.str();
}

void CountryTree::fromString(const string& str)
{
	string tmp, tmp1,tmp2;
	int a;
	istringstream iss;
	iss >> tmp >> tmp1 >> a >> tmp2;
	setName(tmp);
	setColor(tmp1);
	setAge(a);
	setCountry(tmp2);
}

ostream& operator << (ostream& os, const IConvertToString& obj) {
	os << obj.toString();
	return os;
}

istream& operator >> (istream& is, IConvertToString& obj) {
	string tmp;
	is >> tmp;
	obj.fromString(tmp);
	return is;
}

CountryTree::~CountryTree()
{
	num_countryTree--;
	cout << "\nObject deleted\n";
}