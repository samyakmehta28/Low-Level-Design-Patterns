// The Bridge design pattern is a structural pattern used to decouple an abstraction from its implementation
// so that the two can vary independently. This pattern is particularly useful when you want to avoid a permanent 
// binding between an abstraction and its implementation, which can help in extending both independently.

#include <bits/stdc++.h>
using namespace std;

// Abstract Implementor: Defines the interface for the breathing process that concrete implementations must follow.
class BreathImplementor {
    public:
    /**
     * @brief Pure virtual function to define the breathing process.
     * 
     * Concrete classes will implement the breathing logic.
     */
    virtual void breathprocess() = 0;
};

// Concrete Implementor: Provides a specific breathing process for land-dwelling entities.
class LandBreathImpl: public BreathImplementor {
    public:
    /**
     * @brief Implements breathing for land-dwelling entities.
     */
    void breathprocess() {
        cout << "Land Breathing" << endl;
    }
};

// Concrete Implementor: Provides a specific breathing process for water-dwelling entities.
class WaterBreathImpl: public BreathImplementor {
    public:
    /**
     * @brief Implements breathing for water-dwelling entities.
     */
    void breathprocess() {
        cout << "Water Breathing" << endl;
    }
};

// Abstraction: Represents a generic living thing that delegates its breathing process to an implementor.
class LivingThing {
    protected:
    BreathImplementor *breathImplementor; // Pointer to a breathing implementor (Bridge).

    public:
    /**
     * @brief Constructor for LivingThing.
     * 
     * Initializes the LivingThing with a specific breathing implementor.
     * @param bi Pointer to a BreathImplementor object.
     */
    LivingThing(BreathImplementor *bi): breathImplementor(bi) {};

    /**
     * @brief Pure virtual function to define the breathing process for a living thing.
     */
    virtual void breathprocess() = 0;
};

// Refined Abstraction: Represents a Dog, which is a land-dwelling living thing.
class Dog: public LivingThing {
    public:
    /**
     * @brief Constructor for Dog.
     * 
     * Initializes the Dog with a specific breathing implementor.
     * @param bi Pointer to a BreathImplementor object.
     */
    Dog(BreathImplementor *bi): LivingThing(bi) {};

    /**
     * @brief Implements the breathing process for a Dog.
     */
    void breathprocess() {
        cout << "Breath process for Dog: " << endl;
        breathImplementor->breathprocess();
    }
};

// Refined Abstraction: Represents a Fish, which is a water-dwelling living thing.
class Fish: public LivingThing {
    public:
    /**
     * @brief Constructor for Fish.
     * 
     * Initializes the Fish with a specific breathing implementor.
     * @param bi Pointer to a BreathImplementor object.
     */
    Fish(BreathImplementor *bi): LivingThing(bi) {};

    /**
     * @brief Implements the breathing process for a Fish.
     */
    void breathprocess() {
        cout << "Breath process for Fish: " << endl;
        breathImplementor->breathprocess();
    }
};

// Main function demonstrating the Bridge Design Pattern.
// It shows how different living things can independently use different breathing implementors.
int main() {
    // Create a Fish object using a WaterBreathImpl.
    LivingThing *fish = new Fish(new WaterBreathImpl());
    fish->breathprocess();

    // Create a Dog object using a LandBreathImpl.
    LivingThing *dog = new Dog(new LandBreathImpl());
    dog->breathprocess();

    return 0;
}
