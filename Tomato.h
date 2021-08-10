#pragma once
#include"Header.h"
class Tomato : public Vegetable
{
public:
	Tomato();
	~Tomato();
	void read(std::istream&) override;
	std::ostream& print()override;
private:
	int jusiness;
};

Tomato::Tomato()
{
}

Tomato::~Tomato()
{
}
void Tomato::read(std::istream& in)
{
	Vegetable::read(in);
	in >> jusiness;

}
std::ostream& Tomato::print()
{
	Vegetable::print();
	std::cout << " jusiness: " << jusiness;
	return std::cout;
}