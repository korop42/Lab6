#include"Header.h"
int Base::base_Stat = 0;

Base::Base()
{
	base_Stat++;
	name = "noname";
	color = "uncolor";
}

Base::Base(string n, string c)
{
	base_Stat++;
	name = n;
	color = c;
}

void Base::Print(string msg)
{
	cout << "\n";
	cout << name << setw(w) << color << setw(w) << msg;
}

string Base::toString() const
{
	ostringstream oss;
	oss << name
		<< " " << color;
	return oss.str();
}

void Base::fromString(const string& str)
{
	istringstream iss(str);
	iss >> name
		>> color;
}

ostream& operator << (ostream& os, const Base& obj) {
	cout << "\nObject to string: ";
	os << obj.toString() << endl;
	return os;
}

istream& operator >> (istream& is, Base& obj) {

	string tmp;
	getline(is, tmp);
	obj.fromString(tmp);
	return is;
}

Base::~Base()
{
	base_Stat--;
}