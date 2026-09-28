#include "../include/Visit.h"



Visit :: Visit(string date,string diagnosis,int doctorId)
{
    this->date=date;
    this->diagnosis=diagnosis;
    this->doctorId=doctorId;
}

string Visit :: getDate() const
{
    return date;
}

string Visit :: getDiagnosis() const
{
    return diagnosis;
}

int Visit :: getDoctorId() const
{
    return doctorId;
}
