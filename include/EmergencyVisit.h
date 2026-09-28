#include "Visit.h"

#ifndef EMERGENCY_VISIT_H
#define EMERGENCY_VISIT_H

class EmergencyVisit : public Visit
{
private:

public:
    EmergencyVisit(string date,string diagnosis,int doctorId);

    double calculateFee() const override;


};





#endif