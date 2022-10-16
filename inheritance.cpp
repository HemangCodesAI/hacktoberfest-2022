/*Inheritance: acquirng properties from parent class to child class this feature enables ''is a'' relationship and denoted with an arrow head
line.
ex:  a person is a student and employee

BASE class constructer is called first even if an child class object is created.

FUNCTION OVERLOADING : functions having same name with different signatures is called as function overloading
which is si,ilar to constructer overloading.


HYBRID INHERITANCE :::


*/
#include<iostream>

using namespace std;

class person
{
    public:
    int id;
    string name;

   person(int id , string name)
    {
        this->id=id;
        this->name=name;
    }

    void printperson()
    {
        cout<<id<<endl;
        cout<<name<<endl;

    }
};

class student:public person
{
    int cid;
    char grade;
public:
    student(string name,int id,int cid,char grade)
    {
        this->name=name;
        this->id=id;
        this->cid=cid;
        this->grade=grade;
    }

    void printstudent()
    {
        cout<<"Name : "<<name<<endl;
        cout<<"grade : "<<grade<<endl;
    }
};

class employ:public person
{
public:
    int num_days_worked;
    float salary;
    int eid;

    employ(string name,int id,int eid,float salary,int num_days_worked)
    {
         this->name=name;
         this->id=id;
         this->eid=eid;
        this->salary=salary;
         this->num_days_worked=num_days_worked;

    }

    void printemploy()
    {
        cout<<"Employ details<<"<<endl;
        cout<<"\n NAME :"<<name<<"\n id :"<<id<<"\n eid :"<<eid<<"\n salary :"<<salary<<"\nworking days :"<<num_days_worked<<endl;
    }
};

class ugstudent:public student
{
    string spec;
public:
    ugstudent(string name,int id ,int cid,char grade,string spec):student(name,cid,grade)
    {


         this->spec=spec;

    }

    void printug()
    {
        printstudent();
        cout<<"spec :"<<spec<<endl;
    }
};

int main()
{
    student s("abcd",1,2,'S');
    s.printstudent();
    s.printperson();

   // employ e("xyz",1,2,9999.99,30);
    //e.printemploy();
    ugstudent u1("rrr",1,2,'S',"AI");
    u1.printug();
}


