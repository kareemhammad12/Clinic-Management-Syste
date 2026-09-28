#include "../include/Clinic.h"
#include "../include/EmergencyVisit.h"
#include "../include/NormalVisit.h"
#include <iostream>
using namespace std;


Clinic :: Clinic (int patientCapacity,int doctorCapacity)
{
    this->patientCapacity=patientCapacity;
    this->doctorCapacity=doctorCapacity;

    patientCount=0;
    doctorCount=0;

    patients=new Patient*[patientCapacity];
    doctors=new Doctor*[doctorCapacity];
}

Clinic::~Clinic()
{
    for(int i=0;i<patientCount;i++){
        delete patients[i];
    }

    for(int i=0;i<doctorCount;i++){
        delete doctors[i];
    }

    delete []patients;
    delete []doctors;
}

bool Clinic :: addPatient(string name,int id,int age,string phone)
{
    if(patientCount==patientCapacity){
        return false;
    }

    for(int i=0;i<patientCount;i++){
        if(patients[i]->getId()==id){
            return false;
        }
    }
    Patient* newPatient = new Patient(name, id, age, phone);

    int position=patientCount;

    while(position>0 && patients[position-1]->getId()>id)
    {
        patients[position]=patients[position- 1];
        position--;
    }


    patients[position] = newPatient;

    patientCount++;



    return true;
};

Patient* Clinic::searchPatientById(int id) const
{
    int low=0;
    int high=patientCount-1;

    while(low<=high)
    {
        int mid=(low+high)/2;

        int currentId=patients[mid]->getId();

        if(currentId==id)
        {
            return patients[mid];
        }

        if(currentId<id)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }

    return nullptr;
}




void Clinic :: viewPatients() const
{
    if(patientCount==0){
        cout<<"No patient found\n";
        return;
    }

    for(int i=0;i<patientCount;i++){
        patients[i]->displayInfo();
        cout<<"--------------------\n";
    }
}



bool Clinic::addDoctor(string name,int id,string specialization,double consultationFee)
{
    if(doctorCount==doctorCapacity){
        return false;
    }

    for(int i=0;i<doctorCount;i++){
        if(doctors[i]->getId()==id){
            return false;
        }
    }

    doctors[doctorCount]=new Doctor(name,id,specialization,consultationFee);
    doctorCount++;

    return true;
}

void Clinic :: viewDoctors() const
{
    if(doctorCount==0){
        cout<<"No doctors found\n";
        return;
    }

    for(int i=0;i<doctorCount;i++){
        doctors[i]->displayInfo();
        cout<<"--------------------\n";
    }

}


bool Clinic::deletePatient(int id)
{
    int low=0;
    int high=patientCount-1;

    while(low<=high)
    {
        int mid=(low+high)/2;

        int currentId=patients[mid]->getId();

        if(currentId==id)
        {
            delete patients[mid];

            for(int i=mid;i<patientCount-1;i++)
            {
                patients[i]=patients[i+1];
            }

            patientCount--;

            return true;
        }

        if(currentId<id)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }

    return false;
}

void Clinic::sortPatientsByName() const
{
    if(patientCount==0)
    {
        cout<<"No patients found.\n";
        return;
    }

    Patient **temp=new Patient*[patientCount];

    for(int i=0;i<patientCount;i++)
    {
        temp[i]=patients[i];
    }

    int comparisons=0;

    for(int i=0;i<patientCount-1;i++)
    {
        int minIndex=i;

        for(int j=i+1;j<patientCount;j++)
        {
            comparisons++;

            if(*temp[j]<*temp[minIndex])
            {
                minIndex=j;
            }
        }

        if(minIndex != i)
        {
            Patient* swap = temp[i];
            temp[i] = temp[minIndex];
            temp[minIndex] = swap;
        }
    }

    cout << "\nPatients sorted by name:\n";

    for(int i=0;i<patientCount;i++)
    {
        temp[i]->displayInfo();
        cout<<"--------------------\n";
    }

    cout<<"Number of comparisons: " <<comparisons<<endl;

    delete[] temp;
}

void Clinic::sortPatientsByAge() const
{
    if(patientCount==0)
    {
        cout<<"No patients found.\n";
        return;
    }

    Patient** temp=new Patient*[patientCount];

    for(int i=0;i<patientCount;i++)
    {
        temp[i]=patients[i];
    }

    int comparisons=0;

    for(int i=0;i<patientCount-1;i++)
    {
        int minIndex=i;

        for(int j=i+1;j<patientCount;j++)
        {
            comparisons++;

            if(temp[j]->getAge()<temp[minIndex]->getAge())
            {
                minIndex=j;
            }
        }

        if(minIndex!=i)
        {
            Patient* swap=temp[i];
            temp[i]=temp[minIndex];
            temp[minIndex]=swap;
        }
    }

    cout<<"\nPatients sorted by age:\n";

    for(int i=0;i<patientCount;i++)
    {
        temp[i]->displayInfo();
        cout<<"--------------------\n";
    }

    cout<<"Number of comparisons: "<<comparisons<<endl;

    delete[] temp;
}


void Clinic::displayPatientHistory(int patientId) const
{
    Patient* patient=searchPatientById(patientId);

    if(patient==nullptr)
    {
        cout<<"Patient not found.\n";
        return;
    }

    patient->displayHistory();
}


double Clinic::getPatientTotalPaid(int patientId) const
{
    Patient* patient=searchPatientById(patientId);

    if(patient==nullptr)
    {
        return -1;
    }

    return patient->getTotalPaid();
}


bool Clinic::addToWaitingRoom(int patientId,int priority)
{
    Patient* patient=searchPatientById(patientId);

    if(patient==nullptr)
    {
        return false;
    }

    return waitingRoom.addPatient(patientId,priority);
}


void Clinic::viewWaitingRoom() const
{
    waitingRoom.displayWaiting();
}


bool Clinic::callNextPatient(int& patientId,int& priority)
{
    return waitingRoom.callNext(patientId,priority);
}


Doctor* Clinic::searchDoctorById(int id) const
{
    for(int i=0;i<doctorCount;i++)
    {
        if(doctors[i]->getId()==id)
        {
            return doctors[i];
        }
    }

    return nullptr;
}


bool Clinic::recordVisit(int patientId,int doctorId,string date,string diagnosis,int priority)
{
    Patient* patient=searchPatientById(patientId);

    if(patient==nullptr)
    {
        return false;
    }

    Doctor* doctor=searchDoctorById(doctorId);

    if(doctor==nullptr)
    {
        return false;
    }

    Visit* visit;

    if(priority==1)
    {
        visit=new EmergencyVisit(date,diagnosis,doctorId);
    }
    else
    {
        visit=new NormalVisit(date,diagnosis,doctorId);
    }

    patient->addVisit(visit);

    return true;
}


bool Clinic::peekNextPatient(int& patientId,int& priority) const
{
    return waitingRoom.peekNext(patientId,priority);
}
