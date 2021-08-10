#pragma once
#include"Header.h"
class Cucumber : public Vegetable
{
public:
	Cucumber();
	~Cucumber();
	void read(std::istream&) override;
	std::ostream& print()override;
private:
	double lenght;
};

Cucumber::Cucumber()
{
}

Cucumber::~Cucumber()
{
}
void Cucumber::read(std::istream& in)
{
	Vegetable::read(in);
	in >> lenght;

}
std::ostream& Cucumber::print()
{
	Vegetable::print();
	std::cout << " length: " << lenght;
	return std::cout;
}