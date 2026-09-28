#ifndef WAITING_ROOM_H
#define WAITING_ROOM_H


class WaitingRoom
{
private:
    struct Entry
    {
        int patientId;
        int priority; // Emergency=1,Normal=2
        int arrivalOrder;
    };

    Entry *entries;   //pointer ->dynamic array

    int size;
    int capacity;
    int nextArrivalOrder;

public:
    WaitingRoom(int capacity=100);
    ~WaitingRoom();

    bool isEmpty() const;

    bool addPatient(int patientId,int priority);

    bool peekNext(int& patientId,int& priority) const;

    bool callNext(int &patientId, int & priority);

    void displayWaiting() const;
    
};





#endif