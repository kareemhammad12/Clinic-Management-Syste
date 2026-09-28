#pragma once
#include "Visit.h"

class VisitHistory
{
private:
    struct Node
    {
        Visit *visit;
        Node *next;
    };
    Node *head;

    double calculateTotal(Node *current) const; //Recursive function
public:
    VisitHistory();
    ~VisitHistory();

    void addVisit(Visit *visit);
    void displayHistory() const;
    
    double getTotalPaid() const; //Total
};
