#include "Visit.h"

#ifndef NORMAL_VISIT_H
#define NORMAL_VISIT_H



class NormalVisit : public Visit
{
private:

public:
    NormalVisit(string date,string diagnosis,int doctorId);
    
    double calculateFee() const override;

};





#endif