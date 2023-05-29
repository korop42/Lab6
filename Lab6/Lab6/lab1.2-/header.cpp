#include "Header.h"

void print(IConvertToString& obj) {//Base
	cout << "\n" << obj.toString() << endl;;
}

void printInstances(Base** a, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Object " << a[i]->getNumber() << ": " << a[i]->toString() << endl;
	}
}

void sortByIGetNumber(Base**& a, int n) {
	int flag = 1;
	while (flag && n > 1) {
		flag = 0;
		n--;
		for (int j = 0; j < n; j++) {
			if (a[j]->getNumber() < a[j + 1]->getNumber()) {
				Base* temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}
		}
	}
	ArrayPrint(a, n);
}

void Array(Base**& ptr, int& n)
{
	if (n > 4) {
		n = EnterNumber("size of array(less then 4)");
	}
	ptr = new Base*[n];
	for (int i = 0; i < n; i++)
	{
		Base* ptr_E = NULL;
		switch (rand() % 4)
		{
		case 0:  ptr_E = new FlowerByRegion; break;
		case 1:  ptr_E = new Flower("Tulip", "Red", "Ukraine", 40, " July"); break;
		case 2:  ptr_E = new FlowerwithThorns; break;
		case 3:  ptr_E = new Tree("Oak", "Brown", 50); break;
		}
		ptr[i] = ptr_E;
	}
}

void ArrayPrint(Base**& ptr, int & n)
{
	for (int i = 0; i < n; i++)
	{
		print(*ptr[i]);
	}
}

void ClearArray(Base**& ptr, int& n)
{
	for (int i = 0; i < n, i++;) {
		delete ptr[i];
	}
	delete[]ptr;
}

int EnterNumber(const char* msg)//функція введення числа 
{
	cout << "Enter " << msg << " = ";
	char numbers[slen + 1];
	cin.getline(numbers, slen);
	return atoi(numbers);
}

int Menu()//функція меню

{
	cout << "\nGet your choice of task: \n"
		<< ConstructorFlower << " - Create Flower object\n"
		<< ConstructorTree << " - Create Tree object\n"
		<< ConstructorCountryTree << " - Create Tree by region object\n"
		<< ConstructorFlowerWithThorns << " - Create FLower with thorns object\n"
		<< CreateArray << " - Create array of objects using interface IGetNumber\n"
		<< PrintArray << " - Print array of objects using interface IGetNumber\n"
		<< NumberObj << " - Number all obj in array\n"
		<< SortArray << " - Sort array by number\n"
		<< ToString << " - Convert obj to string\n"
		<< FromString << " - Convert obj from string\n"
		<< Exit << " - Exit\n";
	return EnterNumber("your choice");
}
