#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Employee {
private:
    int id;
    char* name;

public:
    Employee(int _id, char* _name);
    virtual ~Employee() { free(name); };
    int getID() { return id; }
    char* getName() { return name; }
    virtual double pay() = 0;
    virtual void print();
};

Employee::Employee(int _id, char* _name) {
    id = _id;
    name = (char*)malloc(sizeof(char) * strlen(_name));
    strcpy(name, _name);
}

void Employee::print() {
    cout << "Employee" << " "
         << id << " "
         << name << endl;
}

class Manager : public Employee {
private:
    int salary;
    int comm;

public:
    Manager(int _id, char* _name, int _salary, int _comm) : Employee(_id, _name), salary(_salary), comm(_comm) {};
    double pay() override;
    void print() override;
};

double Manager::pay() {
    return salary + comm;
}

void Manager::print() {
    cout << "Manager" << " "
         << getID() << " "
         << getName() << " "
         << salary << " "
         << comm << endl;
}

class Technician : public Employee {
private:
    int wage;
    int hours;

public:
    Technician(int _id, char* _name, int _wage, int _hours) : Employee(_id, _name), wage(_wage), hours(_hours) {};
    double pay() override;
    void print() override;
};

double Technician::pay() {
    return wage * hours;
}

void Technician::print() {
    cout << "Technician" << " "
         << getID() << " "
         << getName() << " "
         << wage << " "
         << hours << endl;
}

class Saleman : public Employee {
private:
    int salary;
    int profit;

public:
    Saleman(int _id, char* _name, int _salary, int _profit) : Employee(_id, _name), salary(_salary), profit(_profit) {};
    double pay() override;
    void print() override;
};

double Saleman::pay() {
    return salary + profit * 0.1;
}

void Saleman::print() {
    cout << "Saleman" << " "
         << getID() << " "
         << getName() << " "
         << salary << " "
         << profit << endl;
}

int main() {
    char name[] = "John";
    Manager m(1, name, 1000, 100);
    Technician t(2, name, 10, 100);
    Saleman s(3, name, 1000, 100);

    Employee* e;
    e = &m;
    e->print();
    cout << e->pay() << endl;
    e = &t;
    e->print();
    cout << e->pay() << endl;
    e = &s;
    e->print();
    cout << e->pay() << endl;
}
