#pragma once

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
#include <sstream>
#pragma warning(disable: 4996)
using namespace std;
enum { Exit, ConstructorFlower, ConstructorTree, ConstructorCountryTree, ConstructorFlowerWithThorns, CreateArray, PrintArray, slen = 10, w = 10 };// констант≥ значенн€ 

class IGetNumber
{
public:
	virtual int getNumber() = 0;
	virtual int getCount() = 0;
};

class IConvertToString {
public:
	virtual string toString() const = 0;
	virtual void fromString(const string&) = 0;
};

class Base : public IConvertToString, public IGetNumber
{
private:
	string name;
	string color;
	int number;
	static int base_Stat;
public:
	string getName() const { return name; }
	void setName(string n) { name = n; }
	string getColor() const { return color; }
	void setColor(string c) { color = c; }
	Base();
	Base(string, string);
	virtual void Print(string) = 0;
	/*virtual int getNumber() { return number; }
	virtual int getCount() { return base_Stat; }
	virtual string toString() const ;
	virtual void fromString(const string&);
	friend ostream& operator << (ostream&, const IConvertToString&);
	friend istream& operator >> (istream&, IConvertToString&);*/
	virtual ~Base();
};

class FlowerByRegion : public Base
{
private:
	string Region;
	static int num_flowerByReg;
	int number;
public:
	void setRegion(string reg) { Region = reg; }
	string getRegion() const { return Region; }
	static int GetCount() { return num_flowerByReg; }
	FlowerByRegion();
	FlowerByRegion(string, string, string);
	void Print(string) override;
	virtual int getNumber() { return number; }
	virtual int getCount() { return num_flowerByReg; }
	virtual string toString() const;
	virtual void fromString(const string&);
	/*friend ostream& operator << (ostream&, const IConvertToString&);
	friend istream& operator >> (istream&, IConvertToString&);*/
	~FlowerByRegion();
};

class Flower : public FlowerByRegion
{
private:
	int petals;//к≥льк≥сть пелюсток
	static int num_flowers;//статичне поле , €ке рахуЇ к≥лк≥сть об'Їкт≥в
	string floweringMonth;// м≥с€ць цв≥т≥нн€
	int number;
public:
	void setNumberOfPetals(int num) { petals = num; }// метод встановленн€ к≥лькост≥ пелюсток закритому полю petals
	string getFloweringMonth() const { return floweringMonth; }//метод повертаЇ значенн€ закритого пол€ floweringMonth
	int getNumberOfPetals() const { return petals; }//метод повертаЇ значенн€ закритого пол€ petals
	static int GetCount() { return num_flowers; }//метод повертаЇ значенн€ статичного пол€
	Flower();//конструктор без параметр≥в
	Flower(string, string, string,int, string);//конструктор з параметрами(≥м'€ , к≥льк≥сть пелюсток, кол≥р кв≥тки, м≥с€ць цв≥т≥нн€ кв≥тки) 
	Flower(const Flower&);//конструктор коп≥юванн€
	virtual void Print(string) override;//функц≥€ роздрукуванн€ об'Їкта на екран
	void setFloweringMonth(int);//перевантажений метод встановленн€ м≥с€ц€ цв≥т≥нн€ (позиц≥€ елемента в масив≥)
	void setFloweringMonth(string month) { floweringMonth = month; }//перевантажений метод встановлюЇ м≥сц€ цв≥т≥нн€ (назва м≥с€ц€)
	void setFloweringMonth();//перевантажений метод встановлюЇ м≥сц€ць цв≥т≥нн€ за замовчуванн€м
	virtual int getNumber() { return number; }
	virtual int getCount() { return num_flowers; }
	virtual string toString() const;
	virtual void fromString(const string&);
	/*friend ostream& operator << (ostream&, const IConvertToString&);
	friend istream& operator >> (istream&, IConvertToString&);*/
	~Flower();//деструктор
};

class Tree : public Base
{
private:
	static int num_tree;
	int age;
	int number;
public:
	int getAge() const { return age; }
	void setAge(int a) { age = a; }
	static int getStatic() { return num_tree; }
	Tree();
	Tree(string, string, int);
	virtual void Print(string) override;
	virtual int getNumber() { return number; }
	virtual int getCount() { return num_tree; }
	virtual string toString() const;
	virtual void fromString(const string&);
	/*friend ostream& operator << (ostream&, const IConvertToString&);
	friend istream& operator >> (istream&, IConvertToString&);*/
	~Tree();
};

class CountryTree : public Tree
{
private:
	string country;
	static int num_countryTree;
	int number;
public:
	static int getStatic() { return num_countryTree; }
	string getCountry() { return country; }
	void setCountry(string c) { country = c; }
	CountryTree();
	CountryTree(string, string, int, string);
	virtual void Print(string) override;
	virtual int getNumber() { return number; }
	virtual int getCount() { return num_countryTree; }
	virtual string toString() const;
	virtual void fromString(const string&);
	friend ostream& operator << (ostream&, const IConvertToString&);
	friend istream& operator >> (istream&, IConvertToString&);
	~CountryTree();
};

class FlowerwithThorns : public Flower 
{
private:
	int thorns;
	static int num_flowerswiththorns;
	int number;
public:
	void setThorns(int l) { thorns = l; }
	int getThorns() { return thorns; }
	FlowerwithThorns(string, string,string, int, string, int);
	FlowerwithThorns();
	virtual void Print(string) override;
	virtual int getNumber() { return number; }
	virtual int getCount() { return num_flowerswiththorns; }
	virtual string toString() const;
	virtual void fromString(const string&);
	/*friend ostream& operator << (ostream&, const IConvertToString&);
	friend istream& operator >> (istream&, IConvertToString&);*/
	~FlowerwithThorns() { "\nObject deleted\n"; }
};

void print(IConvertToString&);
void sortByIGetNumber(IGetNumber**, int);
void ArrayPrint(IGetNumber**&,int &);
void Array(IGetNumber**&,int&);
int EnterNumber(const char*);//функц≥€ введенн€ числа
int Menu();//функц≥€ меню