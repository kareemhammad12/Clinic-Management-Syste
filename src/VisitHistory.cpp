#include "../include/VisitHistory.h"
#include <iostream>


VisitHistory :: VisitHistory()
{
    head=nullptr;
}

void VisitHistory :: addVisit(Visit *visit)
{
    Node *newNode= new Node;
    newNode->visit=visit;
    newNode->next=head;
    head=newNode;  
}

void VisitHistory :: displayHistory() const
{
    if(head==nullptr){
        cout<<"No visit history found.\n";
        return;
    }
    Node *current=head;
    while(current!=nullptr){
        cout<<"Date: "<<current->visit->getDate()<<endl;
        cout<<"Diagnosis: "<<current->visit->getDiagnosis()<<endl;
        cout<<"Doctor Id: "<<current->visit->getDoctorId()<<endl;
        cout<<"Fee: "<<current->visit->calculateFee()<<endl;
        current=current->next;
    }
}

double VisitHistory :: getTotalPaid() const
{
    return calculateTotal(head);
}

double VisitHistory :: calculateTotal(Node *current) const
{
    if(current==nullptr){
        return 0;
    }

    return current->visit->calculateFee()+calculateTotal(current->next);
}

VisitHistory :: ~VisitHistory()
{
    Node *current=head;

    while(current!=nullptr){
        Node *next=current->next;

        delete current->visit;
        delete current;

        current=next;
    }
}
