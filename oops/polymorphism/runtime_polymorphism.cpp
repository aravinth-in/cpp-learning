#include <iostream>
#include <memory>
#include <string>
using namespace std;


class Vehicle {
public:
    Vehicle() {
        cout << "Vehicle created" << endl;
    }

    virtual void start() {
        cout << "Starting a generic vehicle" << endl;
    }

    virtual void stop() {
        cout << "Stopping a generic vehicle" << endl;
    }

    virtual ~Vehicle() {
        cout << "Vehicle destroyed" << endl;
    }
};


class Car : public Vehicle {
public:
    Car() {
        cout << "Car created" << endl;
    }

    void start() override {
        cout << "Starting a car" << endl;
    }

    void stop() override {
        cout << "Stopping a car" << endl;
    }

    ~Car() {
        cout << "Car destroyed" << endl;
    }
};


class Motorcycle : public Vehicle {
public:
    Motorcycle() {
        cout << "Motorcycle created" << endl;
    }

    void start() override {
        cout << "Starting a motorcycle" << endl;
    }

    void stop() override {
        cout << "Stopping a motorcycle" << endl;
    }

    ~Motorcycle() {
        cout << "Motorcycle destroyed" << endl;
    }
};

int main() {
    Vehicle* vehicle;
    Car car;
    vehicle = &car; // Base class pointer to point to derived class objects
    
    vehicle->start();
    vehicle->stop();

    Motorcycle motorCycle;
    vehicle = &motorCycle;
    
    vehicle->start();
    vehicle->stop();

    return 0;
}


/*
OUTPUT
Vehicle created
Car created
Starting a car
Stopping a car
Vehicle created
Motorcycle created
Starting a motorcycle
Stopping a motorcycle
Motorcycle destroyed
Vehicle destroyed
Car destroyed
Vehicle destroyed
*/