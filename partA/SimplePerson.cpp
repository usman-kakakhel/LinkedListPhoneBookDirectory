#include "SimplePerson.h"

Person::Person(const string name)
{
    this->name = name;
}

Person::~Person()
{
}

Person::Person(const Person &personToCopy)
{
    this->name = personToCopy.name;
}

void Person::operator=(const Person &right)
{
    this->name = right.name;
}

string Person::getName()
{
    return this->name;
}