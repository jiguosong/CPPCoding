/*
 * inheritance.cpp
 *
 *  Created on: Dec 19, 2016
 *      Author: songjiguo
 */

// these are some note code: IKM, GoTW

// http://stackoverflow.com/questions/860339/difference-between-private-public-and-protected-inheritance#1372858
#include <iostream>
#include <string>

using namespace std;

/////////////////////
///////   1   ///////
/////////////////////
class Person
{
	string *namePtr;
public:
	Person()
	{
		namePtr = new string;
	}
	void setName(char *s)
	{
		*namePtr = s;
	}
	string *getName()
	{
		return namePtr;
	}
};

/////////////////////
///////   2   ///////
/////////////////////

class Object1
{
	virtual ~Object1()
	{
	}
};
class Object2
{
	virtual ~Object2()
	{
	}
};

/////////////////////
///////   3   ///////
/////////////////////

class widget
{
};

/////////////////////
///////   4   ///////
/////////////////////

class Sup
{
protected:
	int storage;
public:
	void set(int val)
	{
		storage = val;
	}
	int get()
	{
		return storage;
	}
};

class Sub: public Sup
{
public:
	void print(void)
	{
		cout << "storage in sub " << storage << endl;
	}
};

/////////////////////
///////   5   ///////
/////////////////////

class Fruit
{
public:
	int weight;
	char season;
};

class Apple: public Fruit
{
public:
	enum variety
	{
		Gala, Fuji, Granny
	};

	void setVariety(variety v)
	{
		type = v;
	}
private:
	variety type;
};

class Orange: Fruit
{
	enum use
	{
		Easting, Juice
	};

public:
	using Fruit::season;
	use type;
};

int main()
{

	Orange f1;
	Apple f2;
	// how to generate access error here?
	f1.season = 'S';
	//f1.type = Orange::Juice;  //  error: ‘Orange::use Juice’ is private
	//f1.weight = 12;           //  error: ‘int Fruit::weight’ is inaccessible
	f2.setVariety(Apple::Fuji);
	f2.weight = 14;

	Sup object;
	object.set(100);
	int ans = object.get();
	cout << ans << endl;

	Sub object_sub;
	object_sub.set(101);
	int ans_sub = object_sub.get();
	cout << ans_sub << endl;
	object_sub.print();

	enum DAY
	{
		Mon = 11, Tue = 12
	};
	enum DAY var = Mon;
	enum DAY var2 = DAY::Mon;

	widget const *cw = new widget;
	widget *w;

	w = const_cast<widget *>(cw);

	Object2 *obj2 = new Object2;
	std::cout << obj2 << std::endl;
	std::cout << dynamic_cast<Object1 *>(obj2) << std::endl;

	/////////////////////
	///////   6   ///////
	/////////////////////
	cout << "---6---" << endl;

	short high = 0x0060;
	short low = 0x0003;
	short res = low | high;

	cout << res << endl;


	Person president;
	Person chairman;

	president.setName("Tom");
	chairman = president;

	cout << chairman.getName() << endl;

	// delete &president;  this will cause fault

	//chairman.setName("Tom");
//	cout << president.getName() << endl;

	/////////////////////
	///////   6   ///////
	/////////////////////
	cout << "---7---" << endl;
	//for (;;)          // endless
	for (int i = 15; i; i--)

	//for(true);   // wrong
	for (double d = 1.0; d <= 1.9; d += 0.1)
		;
	//for(int i = 0, i < 10, i++);  // wrong

}

