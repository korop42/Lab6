#include "Header.h"

void print(IConvertToString& obj) {
	cout << obj.toString();
}

//void printInstances(const IGetNumber**& a, int& count) {
//	for (int i = 0; i < count; i++) {
//		cout << "Object " << a[i]->getNumber() << ": " << a[i]->IConvertToString::toString() << endl;
//	}
//}

void sortByIGetNumber(IGetNumber**& a, int& n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; i++) {
			if (a[j]->getNumber() > a[j + 1]->getNumber()) {
				IGetNumber* temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void Array(IGetNumber**& ptr, int& n)
{
	if (n > 4) {
		n = EnterNumber("size of array(less then 4)");
	}
	n = 10;
	ptr = new IGetNumber*[n];
	for(int i = 0; i < n; i++)
	{
		IGetNumber* ptr_E = NULL;
		switch (rand() % 4)
		{
		case 0: ptr_E = new FlowerByRegion; break;
		case 1: ptr_E = new Flower("Tulip", "Red", "Ukraine", 40, " July"); break;
		case 2: ptr_E = new FlowerwithThorns; break;
		case 3: ptr_E = new Tree("Oak", "Brown", 50); break;
		}
		ptr[i] = ptr_E;
	}
}

//void ArrayPrint(IGetNumber**& ptr,int & n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		ptr[i]->
//	}
//	for (int i = 0; i < n; i++)
//	{
//		delete ptr[i];
//	}
//	delete[]ptr;
//
//}

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
		<< Exit << " - Exit\n";
	return EnterNumber("your choice");
}
