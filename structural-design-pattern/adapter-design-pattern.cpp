// The Adapter Design Pattern is a structural design pattern that allows objects with incompatible interfaces to work together.
// It acts as a bridge between two incompatible interfaces by converting the interface of a class into another interface that a client expects.

#include <bits/stdc++.h>
using namespace std;

// Abstract class representing the Adaptee interface.
// This class defines the method `getWeightInPounds`, which is expected to be implemented by concrete Adaptee classes.
class WeighingMachineAdaptee {
    public:
    /**
     * @brief Returns the weight in pounds.
     * 
     * This pure virtual function is meant to be overridden by concrete implementations
     * to provide the weight in pounds.
     * @return Weight in pounds.
     */
    virtual int getWeightInPounds() = 0;
};

// Concrete implementation of the Adaptee class.
// This class represents a weighing machine that provides weight in pounds.
class WeighingMachineInPounds: public WeighingMachineAdaptee {
    private:
    int value; // Stores the weight in pounds.
    
    public:
    /**
     * @brief Constructor for WeighingMachineInPounds.
     * 
     * Initializes the weight value in pounds.
     * @param val The weight in pounds.
     */
    WeighingMachineInPounds(int val) : value(val) {};

    /**
     * @brief Returns the weight in pounds.
     * 
     * Implements the Adaptee interface's method.
     * @return Weight in pounds.
     */
    int getWeightInPounds() {
        return value;
    };
};

// Abstract class representing the Adapter interface.
// This class defines the method `getWeightInKilos`, which is expected to be implemented by concrete Adapter classes.
class WeighingMachineAdapter {
    public:
    /**
     * @brief Returns the weight in kilograms.
     * 
     * This pure virtual function is meant to be overridden by concrete implementations
     * to provide the weight in kilograms.
     * @return Weight in kilograms.
     */
    virtual double getWeightInKilos() = 0;
};

// Concrete implementation of the Adapter class.
// This class adapts the WeighingMachineInPounds class to provide weight in kilograms.
class WeighingMachineInKilos: public WeighingMachineAdapter {
    private:
    WeighingMachineAdaptee *weighingMachineInPounds; // Pointer to the Adaptee object.

    public:
    /**
     * @brief Constructor for WeighingMachineInKilos.
     * 
     * Creates an instance of WeighingMachineInPounds with the given weight in pounds.
     * @param val The weight in pounds to be adapted.
     */
    WeighingMachineInKilos(int val) : weighingMachineInPounds(new WeighingMachineInPounds(val)) {};

    /**
     * @brief Returns the weight in kilograms.
     * 
     * Converts the weight from pounds to kilograms using the formula:
     * 1 pound = 0.45 kilograms.
     * @return Weight in kilograms.
     */
    double getWeightInKilos() {
        return weighingMachineInPounds->getWeightInPounds() * 0.45;
    };
};

// Main function demonstrating the Adapter Design Pattern.
// It creates a WeighingMachineInKilos object to adapt the WeighingMachineInPounds class
// and prints the weight in kilograms.
int main() {
    // Create an adapter object to convert weight from pounds to kilograms.
    WeighingMachineInKilos *weighingMachineInKilos = new WeighingMachineInKilos(20);

    // Print the weight in kilograms.
    cout << weighingMachineInKilos->getWeightInKilos() << endl;

    return 0;
}

