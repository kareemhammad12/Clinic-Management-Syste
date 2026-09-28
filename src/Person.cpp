#include "../include/Person.h"

Person::Person(string name,int id)
{
    this->name=name;
    this->id=id;
}

int Person::getId() const
{
    return id;
}

string Person::getName() const
{
    return name;
}

void Person::setId(int id)
{
    this->id=id;
}

void Person::setName(string name)
{
    this->name=name;
}

