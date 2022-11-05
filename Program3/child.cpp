
#include "child.h"

// Consturctors and Desctructor

Child::Child()
{
}

Child::Child(string fName, string lName, int a)
{
	firstName = fName;
	lastName = lName;
	age = a;
}

Child::Child(string fName, string lName)
{
	firstName = fName;
	lastName = lName;
	age = 0;
}

string Child::getName() const
{
	return (firstName + lastName);
}

int Child::getAge() const
{
	return age;
}

void Child::setFirstName(const string &fName)
{
	firstName = fName;
}

void Child::setLastName(const string &lName)
{
	lastName = lName;
}

Child::~Child()
{
}

// Operator Overloads

bool Child::operator==(const Child &c) const
{
	return ((firstName == c.firstName) &&
			(lastName == c.lastName) &&
			(age == c.age));
}

bool Child::operator!=(const Child &c) const
{
	return ((firstName != c.firstName) ||
			(lastName != c.lastName) ||
			(age != c.age));
}

bool Child::operator<(const Child &c) const
{
	if (lastName == c.lastName)
	{
		return (firstName < c.firstName);
	}
	else
	{
		return (lastName < c.lastName);
	}
}

bool Child::operator<=(const Child &c) const
{
	if (lastName == c.lastName)
	{
		return (firstName <= c.firstName);
	}
	else
	{
		return (lastName <= c.lastName);
	}
}

bool Child::operator>=(const Child &c) const
{
	if (lastName == c.lastName)
	{
		return (firstName >= c.firstName);
	}
	else
	{
		return (lastName >= c.lastName);
	}
}

bool Child::operator>(const Child &c) const
{
	if (lastName == c.lastName)
	{
		return (firstName > c.firstName);
	}
	else
	{
		return (lastName > c.lastName);
	}
}

ostream &operator<<(ostream &outStream, const Child &c)
{
	outStream << c.firstName << c.lastName << c.age;
	return outStream;
}

istream &operator>>(istream &inStream, Child &c)
{
	inStream >> c.firstName;
	inStream >> c.lastName;
	inStream >> c.age;
	return inStream;
}
