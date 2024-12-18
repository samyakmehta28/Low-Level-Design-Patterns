#include <bits/stdc++.h>
using namespace std;

// The Strategy Design Pattern allows you to encapsulate various driving behaviors 
// and apply them dynamically to different vehicles. The Vehicle class uses a reference 
// to a DriveStrategy object, allowing it to perform different driving actions based on 
// the strategy assigned. This design promotes flexibility and scalability, making it 
// easy to add new driving strategies or modify existing ones without changing the 
// Vehicle class.

// Abstract Strategy Class
// This class defines the interface for various driving strategies. Each specific driving 
// strategy (e.g., SportDrive, NormalDrive) will implement the `drive` method.
class DriveStrategy {
public:
    // Pure virtual function, which will be implemented by concrete strategies.
    virtual void drive() = 0; 
    virtual ~DriveStrategy() = default; // Virtual destructor for proper cleanup of derived classes.
};

// Concrete Strategy for Sports vehicles
// This strategy implements the `drive` function for driving in sport mode, emphasizing 
// high speed and sharp handling.
class SportDrive : public DriveStrategy {
public:
    // Implements the drive function for SportDrive strategy.
    void drive() override {
        cout << "Driving in Sport mode: High speed, sharp handling!" << endl;
    }
};

// Concrete Strategy for Normal vehicles
// This strategy implements the `drive` function for driving in a normal mode, offering 
// a balanced speed and comfort.
class NormalDrive : public DriveStrategy {
public:
    // Implements the drive function for NormalDrive strategy.
    void drive() override {
        cout << "Driving in Normal mode: Balanced speed and comfort." << endl;
    }
};

// Concrete Strategy for Passenger vehicles
// This strategy implements the `drive` function for driving in passenger mode, focusing 
// on a smooth and comfortable ride.
class PassengerDrive : public DriveStrategy {
public:
    // Implements the drive function for PassengerDrive strategy.
    void drive() override {
        cout << "Driving in Passenger mode: Smooth and comfortable ride." << endl;
    }
};

// Vehicle class
// This class represents a vehicle that can change its driving strategy dynamically. 
// It holds a reference to a DriveStrategy and delegates the driving behavior to the strategy.
class Vehicle {
protected:
    DriveStrategy* driveStrategy; // Pointer to the current driving strategy

public:
    // Constructor that initializes the vehicle with a specific driving strategy.
    Vehicle(DriveStrategy* strategy) : driveStrategy(strategy) {}

    // Method to change the current driving strategy dynamically.
    void setDriveStrategy(DriveStrategy* strategy) {
        driveStrategy = strategy;
    }

    // Method to perform the drive operation, delegating to the current strategy.
    void performDrive() {
        driveStrategy->drive();
    }

    // Destructor to clean up the strategy object to prevent memory leaks.
    virtual ~Vehicle() {
        delete driveStrategy; // Cleanup the strategy object when the Vehicle is destroyed.
    }
};

// SportsVehicle class
// This class represents a specific type of vehicle, the sports car. It initializes 
// the vehicle with the SportDrive strategy by default.
class SportsVehicle : public Vehicle {
public:
    // Constructor for SportsVehicle, initializes with the SportDrive strategy.
    SportsVehicle() : Vehicle(new SportDrive()) {}
};

// Main function
int main() {
    // Create a sports vehicle (car) with the SportDrive strategy.
    Vehicle* sportCar = new SportsVehicle();

    // Perform the drive action, which delegates the behavior to the current strategy.
    sportCar->performDrive(); // Output: "Driving in Sport mode: High speed, sharp handling!"

    // Optionally, you can change the driving strategy dynamically.
    // sportCar->setDriveStrategy(new NormalDrive());
    // sportCar->performDrive(); // Output: "Driving in Normal mode: Balanced speed and comfort."
    
    // Clean up allocated memory.
    delete sportCar;
}
