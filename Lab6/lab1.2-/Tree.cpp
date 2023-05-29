#include "Header.h"

int Tree::num_tree = 0;

Tree::Tree() : Base()
{
	num_tree++;
	age = 0;
}

Tree::Tree(string n, string c, int a) : Base(n, c)
{
	num_tree++;
	age = a;
}

void Tree::Print(string msg)
{
	cout << "\nTree:";
	Base::Print(" ");
	cout << age << msg;
}

string Tree::toString() const
{
	ostringstream oss;
	oss << Base::getName()
		<< Base::getColor()
		<< age;
	return oss.str();
}

void Tree::fromString(const string& str)
{
	string tmp, tmp1;
	int a;
	istringstream iss;
	iss >> tmp >> tmp1 >> a;
	setName(tmp);
	setColor(tmp1);
	setAge(a);
}

//ostream& operator << (ostream& os, const IConvertToString& obj) {
//	os << obj.toString();
//	return os;
//}
//
//istream& operator >> (istream& is, IConvertToString& obj) {
//	string tmp;
//	is >> tmp;
//	obj.fromString(tmp);
//	return is;
//}

Tree::~Tree()
{
	num_tree--;
}