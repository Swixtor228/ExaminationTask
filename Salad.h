#pragma once
#include "Header.h"
class Salad
{
public:
	Salad();
	~Salad();
	void print();
	void fomrSalad(vector<std::shared_ptr<Vegetable>>, double);
	void sortByName();
	void sortByCalorie();
	void sortByWeight();
	void sortByPrice();
	void searchByCalRange();

private:
	vector<std::shared_ptr<Vegetable>> salad;
};

Salad::Salad()
{
}
Salad::~Salad()
{
}

void Salad::fomrSalad(vector<std::shared_ptr<Vegetable>> v, double cal)
{
	std::sort(v.begin(), v.end(),
		[](std::shared_ptr<Vegetable> v1, std::shared_ptr<Vegetable> v2)
		{
			return v1->getCalories() > v2->getCalories();
		}
	 );

	while (cal >= v.back()->getCalories())
	{
		std::for_each(v.begin(), v.end(),
			[this, &cal](std::shared_ptr<Vegetable> veg) 
			{
				if (veg->getCalories() <= cal)
				{
					this->salad.push_back(veg);
					cal -= veg->getCalories();
				}
			}
			);
	 }
}

void Salad::print() {
	cout << "\nSalad\n";
	std::copy(salad.begin(), salad.end(), std::ostream_iterator<std::shared_ptr<Vegetable>>(cout, "\n"));
}

void Salad::sortByName()
{
	std::sort(salad.begin(), salad.end(),
		[](std::shared_ptr<Vegetable> v1, std::shared_ptr<Vegetable> v2) 
		{
			return v1->getName() < v2->getName();
		}
		);
}

void Salad::sortByCalorie()
{
	std::sort(salad.begin(), salad.end(),
		[](std::shared_ptr<Vegetable> v1, std::shared_ptr<Vegetable> v2)
		{
			return v1->getCalories() < v2->getCalories();
		}
	);
}

void Salad::sortByWeight()
{
	std::sort(salad.begin(), salad.end(),
		[](std::shared_ptr<Vegetable> v1, std::shared_ptr<Vegetable> v2)
		{
			return v1->getWeight() < v2->getWeight();
		}
	);
}

void Salad::sortByPrice()
{
	std::sort(salad.begin(), salad.end(),
		[](std::shared_ptr<Vegetable> v1, std::shared_ptr<Vegetable> v2)
		{
			return v1->getPrice() < v2->getPrice();
		}
	);
}
void Salad::searchByCalRange()
{
	double min, max;
	vector<std::shared_ptr<Vegetable>> perfectSalad;

	system("cls");

	cout << "Enter min of range: ";
	cin >> min;
	cout << "Enter max of range: ";
	cin >> max;

	system("cls");
	cout << "Range: " << min << "-" << max << endl;

	for (size_t i = 0; i < salad.size(); i++)
		if (salad[i]->getCalories() < max && salad[i]->getCalories() > min) 
			perfectSalad.push_back(salad[i]);	

	std::copy(perfectSalad.begin(), perfectSalad.end(), std::ostream_iterator<std::shared_ptr<Vegetable>>(cout, "\n"));
	std::shared_ptr<Vegetable> minCal = perfectSalad.front();
	
	for (size_t i = 0; i < perfectSalad.size(); i++)
		if (minCal->getCalories() > perfectSalad[i]->getCalories())
			minCal = perfectSalad[i];
	
	cout << "\nMin calorie in:\n" << minCal << endl;
}