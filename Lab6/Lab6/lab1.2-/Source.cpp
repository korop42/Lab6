#include "Header.h"
using namespace std;

int main() {
	FlowerwithThorns* fl1 = new FlowerwithThorns{ "Rose", "Red", "Ukraine" ,10, "July", 15 };
	Flower flower("Tulip", "Red", "Ukraine", 40, " July");
	flower.setColor("Pink");
	int choice = 0;
	Tree tree("Oak", "Brown", 50);
	CountryTree cTree("Oak", "Brown", 50, "California");
	Base**ptr_Base = nullptr;
	int n;
	do
	{
		choice = Menu();
		switch (choice)
		{
		default: choice = Exit; break;
		case ConstructorFlower: flower.Print("\n"); break;
		case ConstructorTree:  tree.Print("\n"); break;
		case ConstructorCountryTree: cTree.Print("\n"); break;
		case ConstructorFlowerWithThorns:  fl1->Print("\n"); break;
		case CreateArray: n = EnterNumber("size of array"); Array(ptr_Base, n); cout << "\nArray has been created.\n"; break;
		case PrintArray: /*n = EnterNumber("how many random objects you want to print");*/ ArrayPrint(ptr_Base, n); break;
		case NumberObj: n = EnterNumber("how many objects you want to number"); printInstances(ptr_Base, n);
		case SortArray: sortByIGetNumber(ptr_Base, n); break;
		case ToString: cout << flower; break;
		case FromString: cin >> flower; break;
		}
	} while (choice);
	ClearArray(ptr_Base, n);
	cout << "\nEnd of Program.\n";
	system("pause");
	return 0;
}
