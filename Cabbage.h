#pragma once
#include"Header.h"

class Cabbage : public Vegetable
{
public:
	Cabbage();
	~Cabbage();
	void read(std::istream&) override;
	std::ostream& print()override;
private:
		bool withSlug;
};

Cabbage::Cabbage()
{
}

Cabbage::~Cabbage()
{
}
void Cabbage::read(std::istream& in)
{
	Vegetable::read(in);
	in >> withSlug;

}
std::ostream& Cabbage::print()
{
	Vegetable::print();
	std::cout << " wiht slug: " << withSlug;
	return std::cout;
}