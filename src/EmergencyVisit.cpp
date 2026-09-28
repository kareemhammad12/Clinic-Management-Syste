#include "../include/EmergencyVisit.h"


EmergencyVisit :: EmergencyVisit(string date,string diagnosis,int doctorId): Visit(date,diagnosis,doctorId)
{

}

double EmergencyVisit :: calculateFee() const
{
    return 500;
}