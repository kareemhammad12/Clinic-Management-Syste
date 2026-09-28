#include "../include/NormalVisit.h"


NormalVisit :: NormalVisit(string date,string diagnosis,int doctorId) : Visit(date,diagnosis,doctorId)
{

}


double NormalVisit :: calculateFee() const 
{
    return 300;    
}

