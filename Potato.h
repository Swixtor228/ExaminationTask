#pragma once
#include"Header.h"
class Potato : public Vegetable
{
public:
	Potato();
	~Potato();
	void read(std::istream&) override;
	std::ostream& print()override;
private:
	bool isYoung;
};

Potato::Potato()
{
}

Potato::~Potato()
{
}
void Potato::read(std::istream& in)
{
	Vegetable::read(in);
	in >> isYoung;

}
std::ostream& Potato::print()
{
	Vegetable::print();
	std::cout << " is young: " << isYoung;
	return std::cout;
}