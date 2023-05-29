#include "Header.h"

int FlowerByRegion::num_flowerByReg = 0;

FlowerByRegion::FlowerByRegion() : Base()
{
	num_flowerByReg++;
	Region = "Milky Way";
}

FlowerByRegion::FlowerByRegion(string n , string c , string r) : Base(n,c)
{
	num_flowerByReg++;
	Region = r;
}

void FlowerByRegion::Print(string msg)
{
	Base::Print(" ");
	cout << Region << setw(w) << msg;
}

string FlowerByRegion::toString() const
{
	ostringstream oss;
	oss << Base::getName()
		<< Base::getColor()
		<< Region;
	return oss.str();
}

void FlowerByRegion::fromString(const string& str)
{
	string tmp,tmp1,tmp2;
	istringstream iss;
	iss >> tmp >> tmp1 >> tmp2;
	setName(tmp);
	setColor(tmp1);
	setRegion(tmp2);
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

FlowerByRegion::~FlowerByRegion()
{
	num_flowerByReg--;
	cout << "\nObject deleted\n";
}
