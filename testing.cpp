#include <iostream>
using namespace std;

class Employee
{
protected:
    int age;
    string name;

public:
    Employee(string ename, int eage)
    {
        name = ename;
        age = eage;
    }

    virtual void work() // virtual function
    {
        cout << name << " is working.\n";
    }

    void setAge(int newAge) // set method --> encapsulation CANNOT ACCESS age OUTISDE OF CLASS
    {
        age = newAge;
        cout << name << " is now " << age << " years old.\n";
    }
};

class Secretary : public Employee // inheritance
{
protected:
    int code;
    int startDate;
    string activity;
    int wage;
    int lastPromotion;

public:
    Secretary(string ename, int eage, int ecode, int estartDate, string eactivity, int ewage, int elastPromotion = NULL) : Employee(ename, eage)
    {
        name = ename;
        age = eage;
        code = ecode;
        activity = eactivity;
        startDate = estartDate;
        wage = ewage;
        lastPromotion = elastPromotion;
    }

    void work()
    {
        cout << "Secretary " << name << " is doing " << activity << ".\n"; // Polymorphism --> WORK FUNCTION IS DIFFERENT FOR EACH CLASS
    }

    void askForPromotion() // abstraction
    {
        int currentYear = 2022;
        if (currentYear - startDate >= 10 && currentYear - lastPromotion > 2)
        {
            wage += 500;
            cout << name << " now has a wage of: " << wage << "RON.\n";
            lastPromotion = currentYear;
        }
        else
            cout << name << " is not eligible for promotion.\n";
    }
};

class Programmer : public Employee // inheritance
{
private:
    int code;
    int startDate;
    int wage;
    int lastPromotion;
    int numOfTasks;

public:
    Programmer(string ename, int eage, int ecode, int estartDate, int enumOfTasks, int ewage, int elastPromotion = NULL) : Employee(ename, eage)
    {
        name = ename;
        age = eage;
        code = ecode;
        startDate = estartDate;
        numOfTasks = enumOfTasks;
        wage = ewage;
        lastPromotion = elastPromotion;
    }
    void work()
    {
        cout << name << " has to complete " << numOfTasks << " tasks.\n";
    }
};

int main()
{

    Employee e = Employee("Andrei", 20);
    Secretary s = Secretary("Ana", 30, 123, 2010, "filing", 2000);
    Programmer p = Programmer("Radu", 22, 111, 2009, 7, 4000, 2018);
    e.work();
    s.work();
    s.setAge(40);
    s.askForPromotion();
    s.askForPromotion();
    p.work();
    // p.as
    return 0;
}