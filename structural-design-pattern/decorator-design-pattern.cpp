#include <bits/stdc++.h>
using namespace std;

// The Decorator Design Pattern is a structural design pattern that allows behavior 
// to be added to individual objects, either statically or dynamically, without 
// affecting the behavior of other objects from the same class.

/// Abstract Component: Defines the interface for pizzas.
class BasePizza {
public:
    virtual int cost() = 0; // Method to calculate the cost of the pizza.
    virtual ~BasePizza() {} // Virtual destructor for proper cleanup.
};

/// Abstract Decorator: Serves as a base class for all decorators.
class ToppingDecorator : public BasePizza {
    // No additional members. Extends the BasePizza interface.
};

/// Concrete Component: Represents a basic Hand Tossed pizza.
class HandTossed : public BasePizza {
public:
    int cost() override {
        return 100; // Base cost of Hand Tossed pizza.
    }
};

/// Concrete Component: Represents a Thin Crust pizza.
class ThinCrust : public BasePizza {
public:
    int cost() override {
        return 150; // Base cost of Thin Crust pizza.
    }
};

/// Concrete Decorator: Adds Mushroom topping.
class Mushroom : public ToppingDecorator {
private:
    BasePizza* pizza; // The pizza being decorated.
public:
    Mushroom(BasePizza* piz) : pizza(piz) {}
    int cost() override {
        return pizza->cost() + 10; // Add cost of Mushroom topping.
    }
};

/// Concrete Decorator: Adds Cheese topping.
class Cheese : public ToppingDecorator {
private:
    BasePizza* pizza; // The pizza being decorated.
public:
    Cheese(BasePizza* piz) : pizza(piz) {}
    int cost() override {
        return pizza->cost() + 20; // Add cost of Cheese topping.
    }
};

/// Main function demonstrating the Decorator Design Pattern.
int main() {
    // Start with a Thin Crust pizza.
    BasePizza* currPizza = new ThinCrust();
    cout << "Cost of Thin Crust: " << currPizza->cost() << endl;

    // Add Mushroom topping.
    currPizza = new Mushroom(currPizza);
    cout << "Cost after adding Mushroom: " << currPizza->cost() << endl;

    // Add Cheese topping.
    currPizza = new Cheese(currPizza);
    cout << "Cost after adding Cheese: " << currPizza->cost() << endl;

    // Cleanup: Avoid memory leaks.
    delete currPizza;

    return 0;
}
     