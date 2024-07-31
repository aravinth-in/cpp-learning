#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
    Vehicle(const std::string& _name) : name(_name) {
        std::cout << "Vehicle constructor called for " << name << std::endl;
    }
    virtual void displayType() const = 0;
    virtual ~Vehicle() {
        std::cout << "Vehicle destructor called for " << name << std::endl;
    }

protected:
    std::string name;
};

class LandVehicle : public Vehicle {
public:
    LandVehicle(const std::string& _name) : Vehicle(_name) {
        std::cout << "LandVehicle constructor called for " << name << std::endl;
    }

    void displayType() const override {
        std::cout << name << " is a type of Land Vehicle" << std::endl;
    }

    virtual ~LandVehicle() {
        std::cout << "LandVehicle destructor called for " << name << std::endl;
    }
};

class WaterVehicle : public Vehicle {
public:
    WaterVehicle(const std::string& _name) : Vehicle(_name) {
        std::cout << "WaterVehicle constructor called for " << name << std::endl;
    }

    void displayType() const override {
        std::cout << name << " is a type of Water Vehicle" << std::endl;
    }

    virtual ~WaterVehicle() {
        std::cout << "WaterVehicle destructor called for " << name << std::endl;
    }
};

class Car : public LandVehicle {
public:
    Car(const std::string& _name, const int _numberOfDoors) : LandVehicle(_name), numberOfDoors(_numberOfDoors) {
        std::cout << "Car constructor called for " << name << std::endl;
    }

    void displayType() const override {
        std::cout << name << " is a Car with " << numberOfDoors << " doors" << std::endl;
    }

    virtual ~Car() {
        std::cout << "Car destructor called for " << name << std::endl;
    }

private:
    int numberOfDoors;
};

class Truck final : public LandVehicle {
public:
    Truck(const std::string& _name, double _payloadCapacity) : LandVehicle(_name), payloadCapacity(_payloadCapacity) {
        std::cout << "Truck constructor called for " << name << std::endl;
    }

    void displayType() const override {
        std::cout << name << " is a Truck with a payload capacity of " << payloadCapacity << " tons" << std::endl;
    }

    virtual ~Truck() {
        std::cout << "Truck destructor called for " << name << std::endl;
    }

private:
    double payloadCapacity;
};

class Ship : public WaterVehicle {
public:
    Ship(const std::string& _name, double _length) : WaterVehicle(_name), length(_length) {
        std::cout << "Ship constructor called for " << name << std::endl;
    }

    void displayType() const override {
        std::cout << name << " is a Ship with a length of " << length << " meters" << std::endl;
    }

    virtual ~Ship() {
        std::cout << "Ship destructor called for " << name << std::endl;
    }

private:
    double length;
};

class Boat final : public WaterVehicle {
public:
    Boat(const std::string& _name, double _tonnage) : WaterVehicle(_name), tonnage(_tonnage) {
        std::cout << "Boat constructor called for " << name << std::endl;
    }

    void displayType() const override {
        std::cout << name << " is a Boat with a tonnage of " << tonnage << " tons" << std::endl;
    }

    virtual ~Boat() {
        std::cout << "Boat destructor called for " << name << std::endl;
    }

private:
    double tonnage;
};

int main() {
    Car car("Tesla Model S", 4);
    Truck truck("Volvo FH16", 25);
    Boat boat("Speedster", 10);
    Ship ship("Titanic", 46000);

    car.displayType();
    truck.displayType();
    boat.displayType();
    ship.displayType();

    return 0;
}

/*
OUTPUT
Vehicle constructor called for Tesla Model S
LandVehicle constructor called for Tesla Model S
Car constructor called for Tesla Model S
Vehicle constructor called for Volvo FH16
LandVehicle constructor called for Volvo FH16
Truck constructor called for Volvo FH16
Vehicle constructor called for Speedster
WaterVehicle constructor called for Speedster
Boat constructor called for Speedster
Vehicle constructor called for Titanic
WaterVehicle constructor called for Titanic
Ship constructor called for Titanic
Tesla Model S is a Car with 4 doors
Volvo FH16 is a Truck with a payload capacity of 25 tons
Speedster is a Boat with a tonnage of 10 tons
Titanic is a Ship with a length of 46000 meters
Ship destructor called for Titanic
WaterVehicle destructor called for Titanic
Vehicle destructor called for Titanic
Boat destructor called for Speedster
WaterVehicle destructor called for Speedster
Vehicle destructor called for Speedster
Truck destructor called for Volvo FH16
LandVehicle destructor called for Volvo FH16
Vehicle destructor called for Volvo FH16
Car destructor called for Tesla Model S
LandVehicle destructor called for Tesla Model S
Vehicle destructor called for Tesla Model S
*/