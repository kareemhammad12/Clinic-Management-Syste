#ifndef CLINIC_H
#define CLINIC_H

#include "Patient.h"
#include "Doctor.h"
#include "WaitingRoom.h"


class Clinic
{
private:

    Patient **patients;
    int patientCount;
    int patientCapacity;

    Doctor **doctors;
    int doctorCount;
    int doctorCapacity;

    WaitingRoom waitingRoom;
public:
    Clinic(int patientCapacity=100,int doctorCapacity=50);
    ~Clinic();

    bool addPatient(string name,int id,int age,string phone);
    bool addDoctor(string name,int id,string specialization,double consultationFee);
    
    Patient* searchPatientById(int id) const;
    bool deletePatient(int id);

    void viewPatients() const;
    void viewDoctors() const;


    void sortPatientsByName() const;
    void sortPatientsByAge() const;

    void displayPatientHistory(int patientId) const;
    double getPatientTotalPaid(int patientId) const;

    bool addToWaitingRoom(int patientId,int priority);
    bool peekNextPatient(int& patientId,int& priority) const;
    void viewWaitingRoom() const;
    bool callNextPatient(int& patientId,int& priority);

    Doctor* searchDoctorById(int id) const;

    bool recordVisit(int patientId,int doctorId,string date,string diagnosis,int priority);
    


};




#endif