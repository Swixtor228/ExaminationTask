#include"Header.h"

std::shared_ptr<Vegetable> getptr(char);
void fillingVegList(vector<std::shared_ptr<Vegetable>>&);
void print(vector<std::shared_ptr<Vegetable>>&);
void printMenu(vector<std::shared_ptr<Vegetable>>&, Salad&);
void sortMenu(vector<std::shared_ptr<Vegetable>>&, Salad&);
void createSalad(vector<std::shared_ptr<Vegetable>>&, Salad&);

int main()
{
	vector<std::shared_ptr<Vegetable>> vegetables;
	Salad salad;
	fillingVegList(vegetables);
	createSalad(vegetables, salad);
	return 0;
}

std::shared_ptr<Vegetable> getptr(char marker)
{
	try
	{
		if (marker == 'c') return std::make_shared<Cucumber>();
		else if (marker == 'b') return std::make_shared<Cabbage>();
		else if (marker == 't') return std::make_shared<Tomato>();
		else if (marker == 'p') return std::make_shared<Potato>();
		else throw "Error: nothing matched!";
	}
	catch(string& error)
	{
		cout << error << endl;
	}
}

void fillingVegList(vector<std::shared_ptr<Vegetable>>& v)
{
	std::ifstream in("Text.txt");
	while (!in.eof())
	{
		char s;
		in >> s;
		std::shared_ptr<Vegetable> ptr = getptr(s);
		v.push_back(ptr);
		v.back()->read(in);
	}
}

void print(vector<std::shared_ptr<Vegetable>>& v)
{
	system("cls");
	std::copy(v.begin(), v.end(), std::ostream_iterator<std::shared_ptr<Vegetable>>(cout, "\n"));
}

void printMenu(vector<std::shared_ptr<Vegetable>>& v, Salad& s)
{
	int choice;
	system("cls");
	cout << "CHEF COOKER\n";
	cout << "1.Sort by...\n";
	cout << "2.Search by suitable calorie range\n";
	cout << "\n0.Exit\n\n";

	cout << "Your choice: ";
	cin >> choice;

	switch(choice)
	{
	case 0:
		return;
		break;
	case 1:
		sortMenu(v, s);
		break;
	case 2:
		s.searchByCalRange();
		break;
	default:
		cout << "Incorrect index\n";
		system("pause");
		printMenu(v, s);
	}
}

void sortMenu(vector<std::shared_ptr<Vegetable>>& v, Salad& s)
{
	system("cls");

	int choice;

	cout << "SORT BY...\n";
	cout << "1.Sort by name\n";
	cout << "2.Sort by calorie\n";
	cout << "3.Sort by price\n";
	cout << "4.Sort by weight\n";
	cout << "\n0.Return to menu\n\n";
	
	cout << "Your choice: ";
	cin >> choice;

	switch(choice)
	{
	case 0:
		printMenu(v, s);
		break;
	case 1:
		s.sortByName();
		s.print();
		break;
	case 2:
		s.sortByCalorie();
		s.print();
		break;
	case 3:
		s.sortByPrice();
		s.print();
		break;
	case 4:
		s.sortByWeight();
		s.print();
		break;
	default:
		cout << "Incorrect index\n";
		system("pause");
		sortMenu(v, s);
	}
}

void createSalad(vector<std::shared_ptr<Vegetable>>& v, Salad& s)
{
	double cal;
	
	cout << "Enter how many calories salad need: ";	
	cin >> cal;

	if (cal <= 0)
	{
		cout << "incorrect index\n";
		createSalad(v, s);
	}

	s.fomrSalad(v, cal);
	s.print();

	cout << "\n";

	system("pause");
	printMenu(v, s);
}

