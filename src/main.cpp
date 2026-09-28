#include "../include/Clinic.h"
#include <iostream>
#include <string>

using namespace std;

int readInt()
{
    int value;

    while(!(cin>>value))
    {
        cin.clear();
        cin.ignore(1000,'\n');

        cout<<"Invalid input. Enter a number: ";
    }

    return value;
}

double readDouble()
{
    double value;

    while(!(cin>>value))
    {
        cin.clear();
        cin.ignore(1000,'\n');

        cout<<"Invalid input. Enter a number: ";
    }

    return value;
}

void waitingRoomMenu(Clinic& clinic)
{
    int choice;

    do
    {
        cout<<"\n===== Waiting Room Menu =====\n";
        cout<<"1. Add Patient\n";
        cout<<"2. View Waiting Room\n";
        cout<<"3. Call Next Patient\n";
        cout<<"4. Back\n";
        cout<<"Enter choice: ";
        choice=readInt();

        if(choice==1)
        {
            int patientId;
            int priority;

            cout<<"Enter patient ID: ";
            patientId=readInt();

            cout<<"Enter priority:\n";
            cout<<"1. Emergency\n";
            cout<<"2. Normal\n";
            cout<<"Enter choice: ";
            priority=readInt();

            if(priority!=1&&priority!=2)
            {
                cout<<"Invalid priority.\n";
            }
            else if(clinic.addToWaitingRoom(patientId,priority))
            {
                cout<<"Patient added to waiting room successfully.\n";
            }
            else
            {
                cout<<"Patient not found or waiting room is full.\n";
            }
        }
        else if(choice==2)
        {
            clinic.viewWaitingRoom();
        }
        else if(choice==3)
        {
            int patientId;
            int priority;

            if(!clinic.peekNextPatient(patientId,priority))
            {
                cout<<"Waiting Room is empty.\n";
            }
            else
            {
                cout<<"Next Patient ID: "<<patientId<<endl;

                if(priority==1)
                {
                    cout<<"Priority: Emergency\n";
                }
                else
                {
                    cout<<"Priority: Normal\n";
                }

                int doctorId;

                cout<<"Enter doctor ID: ";
                doctorId=readInt();

                if(clinic.searchDoctorById(doctorId)==nullptr)
                {
                    cout<<"Doctor not found. Patient remains in waiting room.\n";
                }
                else
                {
                    string date;
                    string diagnosis;

                    cout<<"Enter visit date: ";
                    cin>>date;

                    cout<<"Enter diagnosis: ";
                    cin>>diagnosis;

                    if(clinic.callNextPatient(patientId,priority))
                    {
                        if(clinic.recordVisit(patientId,doctorId,date,diagnosis,priority))
                        {
                            cout<<"Visit recorded successfully.\n";
                        }
                    }
                }
            }
        }
        else if(choice==4)
        {
            cout<<"Returning to main menu...\n";
        }
        else
        {
            cout<<"Invalid choice.\n";
        }

    }while(choice!=4);
}

void doctorsMenu(Clinic& clinic)
{
    int choice;

    do
    {
        cout<<"\n===== Doctors Menu =====\n";
        cout<<"1. Add Doctor\n";
        cout<<"2. View Doctors\n";
        cout<<"3. Back\n";
        cout<<"Enter choice: ";
        choice=readInt();

        if(choice==1)
        {
            string name;
            int id;
            string specialization;
            double consultationFee;

            cout<<"Enter doctor name: ";
            cin>>name;

            cout<<"Enter doctor ID: ";
            id=readInt();

            cout<<"Enter specialization: ";
            cin>>specialization;

            cout<<"Enter consultation fee: ";
            consultationFee=readDouble();

            if(clinic.addDoctor(name,id,specialization,consultationFee))
            {
                cout<<"Doctor added successfully.\n";
            }
            else
            {
                cout<<"Could not add doctor. ID may already exist or storage is full.\n";
            }
        }
        else if(choice==2)
        {
            clinic.viewDoctors();
        }
        else if(choice==3)
        {
            cout<<"Returning to main menu...\n";
        }
        else
        {
            cout<<"Invalid choice.\n";
        }

    }while(choice!=3);
}

void patientsMenu(Clinic& clinic)
{
    int choice;

    do
    {
        cout<<"\n===== Patients Menu =====\n";
        cout<<"1. Add Patient\n";
        cout<<"2. View Patients\n";
        cout<<"3. Search Patient\n";
        cout<<"4. Delete Patient\n";
        cout<<"5. View Patient History\n";
        cout<<"6. Sort Patients\n";
        cout<<"7. Back\n";
        cout<<"Enter choice: ";
        choice=readInt();

        if(choice==1)
        {
            string name;
            int id;
            int age;
            string phone;

            cout<<"Enter patient name: ";
            cin>>name;

            cout<<"Enter patient ID: ";
            id=readInt();

            cout<<"Enter patient age: ";
            age=readInt();

            cout<<"Enter patient phone: ";
            cin>>phone;

            if(clinic.addPatient(name,id,age,phone))
            {
                cout<<"Patient added successfully.\n";
            }
            else
            {
                cout<<"Could not add patient. ID may already exist or storage is full.\n";
            }
        }
        else if(choice==2)
        {
            clinic.viewPatients();
        }
        else if(choice==3)
        {
            int id;

            cout<<"Enter patient ID: ";
            id=readInt();

            Patient* patient=clinic.searchPatientById(id);

            if(patient==nullptr)
            {
                cout<<"Patient not found.\n";
            }
            else
            {
                patient->displayInfo();
            }
        }
        else if(choice==4)
        {
            int id;

            cout<<"Enter patient ID: ";
            id=readInt();

            if(clinic.deletePatient(id))
            {
                cout<<"Patient deleted successfully.\n";
            }
            else
            {
                cout<<"Patient not found.\n";
            }
        }
        else if(choice==5)
        {
            int id;

            cout<<"Enter patient ID: ";
            id=readInt();

            clinic.displayPatientHistory(id);

            double total=clinic.getPatientTotalPaid(id);

            if(total!=-1)
            {
                cout<<"Total Paid: "<<total<<endl;
            }
        }
        else if(choice==6)
        {
            int sortChoice;

            cout<<"\n===== Sort Patients =====\n";
            cout<<"1. Sort by Name\n";
            cout<<"2. Sort by Age\n";
            cout<<"Enter choice: ";
            sortChoice=readInt();

            if(sortChoice==1)
            {
                clinic.sortPatientsByName();
            }
            else if(sortChoice==2)
            {
                clinic.sortPatientsByAge();
            }
            else
            {
                cout<<"Invalid choice.\n";
            }
        }
        else if(choice==7)
        {
            cout<<"Returning to main menu...\n";
        }
        else
        {
            cout<<"Invalid choice.\n";
        }

    }while(choice!=7);
}

int main()
{
    Clinic clinic;

    int choice;

    do
    {
        cout<<"\n===== Clinic Management System =====\n";
        cout<<"1. Patients\n";
        cout<<"2. Doctors\n";
        cout<<"3. Waiting Room\n";
        cout<<"4. Exit\n";
        cout<<"Enter choice: ";
        choice=readInt();

        if(choice==1)
        {
            patientsMenu(clinic);
        }
        else if(choice==2)
        {
            doctorsMenu(clinic);
        }
        else if(choice==3)
        {
            waitingRoomMenu(clinic);
        }
        else if(choice==4)
        {
            cout<<"Goodbye.\n";
        }
        else
        {
            cout<<"Invalid choice.\n";
        }

    }while(choice!=4);

    return 0;
}