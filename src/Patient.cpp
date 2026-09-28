#include "../include/Patient.h"
#include <iostream>

Patient::Patient(string name,int id,int age,string phone) : Person(name,id)
{
    this->age=age;
    this->phone=phone;
}

int Patient :: getAge() const
{
    return age;
}

string Patient :: getPhone() const
{
    return phone;
}

void Patient :: setAge(int age)
{
    this->age=age;
}

void Patient :: setPhone(string phone)
{
    this->phone=phone;
}

void Patient :: displayInfo() const
{
    cout<<"ID: "<<getId()<<endl;
    cout<<"Name: "<<getName()<<endl;
    cout<<"Age: "<<getAge()<<endl;
    cout<<"Phone: "<<getPhone()<<endl;

}

void Patient :: addVisit(Visit *visit)
{
    history.addVisit(visit);
}

void Patient :: displayHistory() const
{
    history.displayHistory();
}

double Patient :: getTotalPaid() const
{
    return history.getTotalPaid();
}

bool Patient :: operator<(const Patient &other) const
{
    return getName() < other.getName();
}

