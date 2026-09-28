#include "../include/WaitingRoom.h"
#include <iostream>
using namespace std;



WaitingRoom :: WaitingRoom(int capacity)
{
    this->capacity=capacity;
    size=0;
    nextArrivalOrder=0;

    entries=new Entry[capacity];
}

WaitingRoom :: ~WaitingRoom()
{
    delete [] entries;
}

bool WaitingRoom :: isEmpty() const
{
    return size==0;
}

bool WaitingRoom :: addPatient(int patientId,int priority)
{
    if(size==capacity){
        return false;
    }

    Entry newEntry;

    newEntry.patientId=patientId;
    newEntry.priority=priority;
    newEntry.arrivalOrder=nextArrivalOrder;

    nextArrivalOrder++;

    int position=size;

    while(position>0){
        Entry previous=entries[position-1];

        if(previous.priority < newEntry.priority){
            break;
        }

        if(previous.priority==newEntry.priority && previous.arrivalOrder<newEntry.arrivalOrder){
            break;
        }

        entries[position]=previous;
        position--;
    }
    entries[position]=newEntry;
    size++;

    return true;
}

bool WaitingRoom :: callNext(int &patientId,int &priority)
{
    if(size==0){
        return false;
    }

    patientId=entries[0].patientId;
    priority=entries[0].priority;

    for(int i=0;i<size-1;i++){
        entries[i]=entries[i+1];
    }
    size--;

    return true;
}

void WaitingRoom :: displayWaiting() const
{
    if(size==0){
        cout<<"Waiting Room is empty\n";
        return;
    }

    for(int i=0;i<size;i++){
        cout<<"Patient ID: "<<entries[i].patientId<<" | Priority: ";
        if(entries[i].priority==1){
            cout<<"Emergency";
        }
        else{
            cout<<"Normal";
        }
        cout<<endl;
    }
}


bool WaitingRoom::peekNext(int& patientId,int& priority) const
{
    if(size==0)
    {
        return false;
    }

    patientId=entries[0].patientId;
    priority=entries[0].priority;

    return true;
}