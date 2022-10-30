#ifndef CHILD_H_
#define CHILD_H_
#include <string>
#include <iostream>
using namespace std;

class Child
{

friend ostream& operator<<(ostream &, const Child &); 
friend istream& operator>>(istream &, Child &);  

public:
	Child();
	Child(string fName, string lName, int age);
	Child(string fName, string lName);

	string getName() const;
	int getAge() const;
	bool getBehavior() const;

	void setFirstName(const string &);
	void setLastName(const string &);
	void setNice(bool behavior);

	bool operator<(const Child &) const;
	bool operator<=(const Child &) const;
	bool operator>=(const Child &) const;
	bool operator>(const Child &) const;
	bool operator==(const Child &) const;
	bool operator!=(const Child &) const;
	~Child();

private:
	string firstName;
	string lastName;
	int age;
};
#endif

