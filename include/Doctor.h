#include <string>
#include "Person.h"

#ifndef DOCTOR_H
#define DOCTOR_H

class Doctor : public Person
{
private:
    string specialization;
    double consultationFee;
public:
    Doctor(string name,int id,string specialization,double consultationFee);
    string getSpecialization() const;
    double getConsultationFee() const;

    void setSpecialization(string specialization);
    void setConsultationFee(double consultationFee);

    void displayInfo() const override;
};



#endif