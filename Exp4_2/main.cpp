#include <iostream>
using namespace std;

class Vehicle {
protected:
    int id;

public:
    Vehicle(int id) : id(id) {};
};

class Car : virtual public Vehicle {
protected:
    int persons;

public:
    Car(int id, int persons) : Vehicle(id), persons(persons) {};
};

class Truck : virtual public Vehicle {
protected:
    int capacity;

public:
    Truck(int id, int capacity) : Vehicle(id), capacity(capacity) {};
};

class Pickup : public Car, public Truck {
public:
    Pickup(int id, int persons, int capacity) : Vehicle(id), Car(id, persons), Truck(id, capacity) {};
    void show_info();
};

void Pickup::show_info() {
    cout << "ID: " << id << endl;
    cout << "Persons: " << persons << endl;
    cout << "Capacity: " << capacity << endl;
}

int main() {
    Pickup p(1, 5, 1000);
    p.show_info();
}
