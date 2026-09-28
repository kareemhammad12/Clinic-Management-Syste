#include <string>

#ifndef VISIT_H
#define VISIT_H

using namespace std;

class Visit
{
private:
   string date;
   string diagnosis;
   int doctorId;
public:
    Visit(string date,string diagnosis,int doctorId);
    string getDate() const;
    string getDiagnosis() const;
    int getDoctorId() const;

    virtual double calculateFee() const=0;
    virtual ~Visit() = default;
};







#endif