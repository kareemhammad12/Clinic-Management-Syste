#include "../include/Doctor.h"
#include <iostream>


Doctor :: Doctor(string name,int id,string specialization,double consultationFee) : Person(name,id)
{
    this->specialization=specialization;
    this->consultationFee=consultationFee;
}

string Doctor :: getSpecialization() const
{
    return specialization;
}

double Doctor :: getConsultationFee() const
{
    return consultationFee;
}

void Doctor :: setSpecialization(string specialization)
{
    this->specialization=specialization;
}

void Doctor :: setConsultationFee(double consultationFee)
{
    this->consultationFee=consultationFee;
}

void Doctor :: displayInfo() const 
{
    cout<<"ID: "<<getId()<<endl;
    cout<<"Name: "<<getName()<<endl;
    cout<<"Specialization: "<<getSpecialization()<<endl;
    cout<<"Consultation Fee: "<<getConsultationFee()<<endl;
}
