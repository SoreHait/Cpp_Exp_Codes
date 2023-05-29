#include <iostream>
using namespace std;

class Employee {
private:
    int id;
    char* name;

public:
    Employee(int _id, char* _name);
    virtual float pay() = 0;
    virtual void print();
};

Employee::Employee(int _id, char *_name) {
    id = _id;
    name = _name;
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
    Manager(int _id, char* _name, int _salary, int _comm);
    virtual float pay();
    virtual void print();
};

Manager::Manager(int _id, char *_name, int _salary, int _comm) : Employee::Employee(_id, _name) {
    salary = _salary;
    comm = _comm;
}

float Manager::pay() {
    return salary + comm;
}

void Manager::print() {

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
