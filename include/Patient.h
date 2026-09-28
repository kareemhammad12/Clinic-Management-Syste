#include <string>
#include "Person.h"
#include "VisitHistory.h"

#ifndef PATIENT_H
#define PATIENT_H

class Patient : public Person
{
private:
  int age;
  string phone;
  VisitHistory history; 
public:
    Patient(string name,int id,int age,string phone);
    int getAge() const;
    string getPhone() const;

    void setAge(int age);
    void setPhone(string phone);

    void displayInfo() const override;

    void addVisit(Visit *visit);
    void displayHistory() const;
    double getTotalPaid() const;

    bool operator<(const Patient& other) const;

};

#endif