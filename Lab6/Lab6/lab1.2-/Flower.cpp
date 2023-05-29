#include "Header.h"

int Flower::num_flowers = 0;

Flower::Flower() : FlowerByRegion()//����������� ��� ���������
{
	num_flowers++;
	petals = 0;
	floweringMonth = "no bloom";

}

Flower::Flower(string n, string c, string reg, int i, string flowMonth) : FlowerByRegion(n, c, reg)//����������� � �����������(��'� , ������� ��������, ���� �����, ����� ������ �����) 
{
	petals = i;
	num_flowers++;
	floweringMonth = flowMonth;

}

Flower::Flower(const Flower& other)//����������� ���������
{
	num_flowers++;
	petals = other.petals;
	floweringMonth = other.floweringMonth;
}

void Flower::Print(string msg)//������� ������������� ��'���� �� �����
{
	cout << "\nFlower: ";
	FlowerByRegion::Print(" ");
	cout << petals << setw(w) << floweringMonth << msg;
}

void Flower::setFloweringMonth(int a)//�������������� ����� ������������ ����� ������ (������� �������� � �����)
{
	string months[] = { "Wrong month", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	if (a < 1 || a > 12) {
		floweringMonth = months[0];
	}
	else {
		floweringMonth = months[a];
	}

}

void setFloweringMonth()//�������������� ����� ���������� ������ ������ �� �������������
{
	cout << "Flower bloom all year. ";
}


string Flower::toString() const
{
	ostringstream oss;
	oss << Base::getName()
		<< " " << Base::getColor()
		<< " " << FlowerByRegion::getRegion()
		<< " " << petals
		<< " " << floweringMonth;
	return oss.str();
}

void Flower::fromString(const string& str)
{
	string tmp, tmp1, tmp2, tmp3;
	int p;
	istringstream iss(str);
	iss >> tmp >> tmp1 >> tmp2 >> tmp3 >> p;
	setName(tmp);
	setColor(tmp1);
	setRegion(tmp2);
	setNumberOfPetals(p);
	setFloweringMonth(tmp3);
}

ostream& operator << (ostream& os, const Flower& obj) {
	cout << "\nObject to string: ";
	os << obj.toString() << endl;
	return os;
}

istream& operator >> (istream& is, Flower& obj) {
	string tmp;
	getline(is, tmp);
	obj.fromString(tmp);
	return is;
}

Flower::~Flower()//����������
{
	num_flowers--;
	cout << "\nObject deleted.\n";
}
