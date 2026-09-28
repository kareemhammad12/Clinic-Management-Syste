#include <string>
#ifndef PERSON_H
#define PERSON_H



using namespace std;

class Person
{
private:
    string name;
    int id;
public:
    Person(string name,int id);
    int getId()const;
    string getName()const;

    void setId(int id);
    void setName(string name);

    virtual void displayInfo() const=0;
    virtual ~Person() = default;


};



#endif