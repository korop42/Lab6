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
		<< " " << Base::getColor()
		<< " " << age;
	return oss.str();
}

void Tree::fromString(const string& str)
{
	string tmp, tmp1;
	int tmp2;
	istringstream iss(str);
	iss >> tmp >> tmp1 >> tmp2;
	setName(tmp);
	setColor(tmp1);
	setAge(tmp2);
}

ostream& operator << (ostream& os, const Tree& obj) {
	cout << "\nObject to string: ";
	os << obj.toString() << endl;
	return os;
}

istream& operator >> (istream& is, Tree& obj) {
	string tmp;
	getline(is, tmp);
	obj.fromString(tmp);
	return is;
}

Tree::~Tree()
{
	num_tree--;
}