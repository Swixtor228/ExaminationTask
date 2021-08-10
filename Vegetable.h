#pragma once
#include"Header.h"
class Vegetable
{
public:
	Vegetable();
	virtual ~Vegetable();
	virtual void read(std::istream&);
	virtual std::ostream& print();
	double getCalories()const { return calories; }
	double getWeight()const { return weight; }
	double getPrice()const { return price; }
	string getName()const { return name; }
	friend std::ostream& operator<<(std::ostream&, std::shared_ptr<Vegetable>);
private:
	string name;
	double calories;
	double price;
	double weight;
};

Vegetable::Vegetable()
{
}

Vegetable::~Vegetable()
{
}
void Vegetable::read(std::istream& in)
{
	in >> name >> calories >> price >> weight;
}
std::ostream& Vegetable::print()
{
	std::cout << "name: " << name << " calories: " << calories << " price: " << price << " weight: " << weight << " ";
	return std::cout;
}
std::ostream& operator<<(std::ostream& out, std::shared_ptr<Vegetable> bs)
{
	bs->print();
	return out;
}