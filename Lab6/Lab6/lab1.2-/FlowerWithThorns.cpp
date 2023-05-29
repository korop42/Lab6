#include "Header.h"

int FlowerwithThorns::num_flowerswiththorns = 0;

FlowerwithThorns::FlowerwithThorns() : Flower()
{
	num_flowerswiththorns++;
	thorns = 0;
}

FlowerwithThorns::FlowerwithThorns(string n, string c, string reg, int i, string flowMonth, int t) : Flower(n, c, reg, i, flowMonth)
{
	num_flowerswiththorns++;
	thorns = t;
}

void FlowerwithThorns::Print(string msg)
{
	Flower::Print(" ");
	cout << "\nFlower with thorns: ";
	cout << setw(w) << thorns << msg;
}

string FlowerwithThorns::toString() const
{
	ostringstream oss;
	oss << Base::getName()
		<< " " << Base::getColor()
		<< " " << FlowerByRegion::getRegion()
		<< " " << Flower::getNumberOfPetals()
		<< " " << Flower::getFloweringMonth()
		<< " " << thorns;
	return oss.str();
}

void FlowerwithThorns::fromString(const string& str)
{

	string tmp, tmp1, tmp2, tmp3;
	int p, t;
	istringstream iss;
	iss >> tmp >> tmp1 >> tmp2 >> tmp3 >> p >> t;
	setName(tmp);
	setColor(tmp1);
	setRegion(tmp2);
	setNumberOfPetals(p);
	setFloweringMonth(tmp3);
	setThorns(t);
}

ostream& operator << (ostream& os, const FlowerwithThorns& obj) {
	cout << "\nObject to string: ";
	os << obj.toString() << endl;
	return os;
}

istream& operator >> (istream& is, FlowerwithThorns& obj) {
	string tmp;
	getline(is, tmp);
	obj.fromString(tmp);
	return is;
}
