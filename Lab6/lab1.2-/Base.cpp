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

//string Base::toString() const
//{
//	ostringstream oss;
//	oss << name
//		<< color;
//	return oss.str();
//}
//
//void Base::fromString(const string& str)
//{
//	istringstream iss(str);
//	iss >> name
//		>> color;
//}
//
//ostream& operator << (ostream& os , const IConvertToString& obj) {
//	os << obj.toString();
//	return os;
//}
//
//istream& operator >> (istream& is, IConvertToString& obj) {
//
//	string tmp;
//	is >> tmp;
//	obj.fromString(tmp);
//	return is;
//}

Base::~Base()
{
	base_Stat--;
}