#include <iostream>
#include <functional>
#include <ctime>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <deque>
#include <set>
#include <cstdlib>
#include <random>


using namespace std;

class Person
{
public:
	Person()
	{
		name = "Chito";
		age = 27;
	}
	Person(string n, int a)
	{
		name = n;
		age = a;
	}

	string getName()
	{
		return name;
	}

	void setName(string n)
	{
		name = n;
	}

	int getAge()
	{
		return age;
	}

	void setAge(int a)
	{
		age = a;
	}

private:
	string name;
	int age;
};

ostream& operator<<(ostream& out, Person p)
{
	out << "Person name is "<< p.getName() << " and age is " << p.getAge() << endl;
	return out;
}

bool comAge(Person p1, Person p2)
{
	return p1.getAge() < p2.getAge();
}

class Student : public Person
{
public:
	Student(): Person("James", 222)
	{
		grades = { 1,2,3,4,5 };

	}

	Student(string n, int a):Person(n,a)
	{
		grades;

		for (int b = 0; b < 5; b++)
		{
			double z = getRand100();

			grades.push_back(z);
		}
	}

	list<double> getGrades()
	{
		return grades;
	}

	double getRand100()
	{
		srand(time(NULL));
		double a = (rand() % 100) + 1;
		return a;
	}

	string GetName(Student p)
	{
		return p.getName();
	}

private:
	list<double> grades;
};

void printGrades(list <double> g)
{
	list <double>::iterator it;
	for (it = g.begin(); it != g.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

ostream& operator<<(ostream& out, Student p)
{
	out << "Person name is " << p.GetName(p) << " and grades are ";
	printGrades(p.getGrades());

	return out;
}

void printStudent(Student a)
{
	cout << a;
}

bool comName(Student p1, Student p2)
{
	return p1.getName() < p2.getName();
}

bool comAgeStudent(Student p1, Student p2)
{
	return p1.getAge() < p2.getAge();
}

int main()
{
	Person a1;
	Person a2("Jose", 400);

	cout << a1;
	cout << a2;

	comAge(a1, a2);

	if (comAge(a1, a2) == false)
	{
		cout << "The older person is ";
		cout << a1;
	}
	else
	{
		cout << "The older person is ";
		cout << a2;
	}

	cout << "==================================================================" << endl;

	vector<Student> s(2);

	Student s2("Jessie", 8);

	cout << s2;

	s.push_back(s2);

	for_each(s.begin(), s.end(), printStudent);

	cout << "==================================================================" << endl;

	sort(s.begin(), s.end(), comAge);
	for_each(s.begin(), s.end(), printStudent);

	cout << "==================================================================" << endl;

	sort(s.begin(), s.end(), comName);
	for_each(s.begin(), s.end(), printStudent);

	system("pause");
	return 0;
}