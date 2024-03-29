// Decorator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include <string>

class Pizza
{
	std::string str = "This Pizza";
	int cost = 0;

public:
	virtual void show() = 0;
	std::string getStr()
	{
		return str;
	}
	void addStr(std::string str)
	{
		this->str += str;
	}
	void addCost(int a)
	{
		cost += a;
	}
	void setStr(std::string str)
	{
		this->str = str;
	}
	int getCost()
	{
		return cost;
	}
	void setCost(int a)
	{
		cost = a;
	}

};

class Margherita: public Pizza
{
public:
	Margherita()
	{
		addStr(" is a Margherita");
		addCost(50);
	}

	void show()
	{
		std::cout << getStr() << " and costs: "<<getCost()<<" \n";
	}
};

class DecoratorPizza: public Pizza
{
	std::shared_ptr<Pizza> a;
};

class Tomatoes: public DecoratorPizza
{
public:
	void show()
	{
		std::cout << getStr() << " and costs: " << getCost() << " \n";

	}
	Tomatoes(std::shared_ptr<Pizza> a)
	{
		//std::cout<<a->getStr();
		setStr(a->getStr() + "+ 1 tomatoes,");
		setCost(a->getCost());
		addCost(35);
		//std::cout << "\n" << this->a->getStr();
		//addStr("");
	}
};

class Cheese : public DecoratorPizza
{
public:
	void show()
	{
		std::cout << getStr() << " and costs: " << getCost() << " \n";

	}
	Cheese(std::shared_ptr<Pizza> a)
	{
		//std::cout<<a->getStr();
		setStr(a->getStr() + "+ 1 cheese ");
		setCost(a->getCost());
		addCost(35);
		//std::cout << "\n" << this->a->getStr();
		//addStr("");
	}
};



int main()
{
	std::shared_ptr<Pizza> b = std::make_shared<Margherita>();

	while(true)
	{
		b->show();
		int input;
		std::cout << "Want tomatoes or cheese(1 | 2) ?\n";
		std::cin >> input;
		if(input==1)
			b = std::shared_ptr<Pizza>(new Tomatoes(b));
		if (input == 2)
			b = std::shared_ptr<Pizza>(new Cheese(b));
	}
	
}

