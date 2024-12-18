#include <bits/stdc++.h>
using namespace std;

// Memento Design Pattern: 
// The Memento Design Pattern is a behavioral design pattern that provides the ability to 
// restore an object to a previous state without revealing the details of the object’s 
// implementation. It is typically used to implement undo/redo mechanisms.

// Memento Class
// This class represents a snapshot of an object's state. It stores the height and width 
// values of the Originator and provides access to these values.
class Momento {
    private:
    int height; // The height value to be stored.
    int width;  // The width value to be stored.
    
    public:
    // Constructor to initialize the height and width values.
    Momento(int h, int w): height(h), width(w) {}

    /**
     * @brief Gets the stored height value.
     * @return The stored height.
     */
    int getHeight() {
        return height;
    }

    /**
     * @brief Gets the stored width value.
     * @return The stored width.
     */
    int getWidth() {
        return width;
    }
};

// Originator Class
// This class represents the object whose state needs to be saved and restored.
// It provides methods to create a Memento (snapshot of its current state) and restore 
// its state from a Memento.
class Originator {
    private:
    int height; // Current height value.
    int width;  // Current width value.
    
    public:
    // Constructor to initialize the height and width values.
    Originator(int h, int w): height(h), width(w) {}

    /**
     * @brief Sets the height value.
     * @param h The new height to set.
     */
    void setHeight(int h) {
        height = h;
    }

    /**
     * @brief Sets the width value.
     * @param w The new width to set.
     */
    void setWidth(int w) {
        width = w;
    }

    /**
     * @brief Gets the current height value.
     * @return The current height.
     */
    int getHeight() {
        return height;
    }

    /**
     * @brief Gets the current width value.
     * @return The current width.
     */
    int getWidth() {
        return width;
    }

    /**
     * @brief Creates a Memento containing the current state.
     * @return A pointer to the created Memento.
     */
    Momento* createMomento() {
        return new Momento(height, width);
    }

    /**
     * @brief Restores the state from a given Memento.
     * @param momento The Memento to restore the state from.
     */
    void restoreMomento(Momento *momento) {
        height = momento->getHeight();
        width = momento->getWidth();
    }
};

// Caretaker Class
// This class is responsible for storing and managing Mementos. It provides methods 
// to add a Memento to the history and undo the last state by retrieving a Memento.
class CareTaker {
    private:
    stack<Momento*> history; // Stack to maintain the history of Mementos.

    public:
    // Constructor to initialize the CareTaker.
    CareTaker() {
        while (!history.empty()) {
            history.pop();
        }
    }

    /**
     * @brief Adds a Memento to the history stack.
     * @param momento The Memento to add.
     */
    void addMomento(Momento *momento) {
        history.push(momento);
    }

    /**
     * @brief Retrieves and removes the last Memento from the history stack.
     * @return The last Memento, or NULL if the stack is empty.
     */
    Momento* undo() {
        if (history.empty()) {
            return NULL;
        }
        Momento *momento = history.top();
        history.pop();
        return momento;
    }
};

// Main function
// Demonstrates the use of the Memento Design Pattern. The Originator's state is saved 
// as Mementos and restored using the CareTaker.
int main() {
    // Create a CareTaker and an Originator with initial dimensions.
    CareTaker *careTaker = new CareTaker();
    Originator *originator = new Originator(25, 15);

    // Display the initial state.
    cout << "Height is " << originator->getHeight() << " and Width is " << originator->getWidth() << endl;

    // Save the initial state as a snapshot.
    Momento *snapshot1 = originator->createMomento();
    careTaker->addMomento(snapshot1);

    // Change the state of the Originator.
    originator->setHeight(15);
    originator->setWidth(25);
    cout << "Height is " << originator->getHeight() << " and Width is " << originator->getWidth() << endl;

    // Save the new state as another snapshot.
    Momento *snapshot2 = originator->createMomento();
    careTaker->addMomento(snapshot2);

    // Change the state of the Originator again.
    originator->setHeight(50);
    originator->setWidth(50);
    cout << "Height is " << originator->getHeight() << " and Width is " << originator->getWidth() << endl;

    // Undo to the previous state using the last saved snapshot.
    Momento *restoreStateMomento1 = careTaker->undo();
    originator->restoreMomento(restoreStateMomento1);
    cout << "Height is " << originator->getHeight() << " and Width is " << originator->getWidth() << endl;

    // Undo to the initial state using the first saved snapshot.
    Momento *restoreStateMomento2 = careTaker->undo();
    originator->restoreMomento(restoreStateMomento2);
    cout << "Height is " << originator->getHeight() << " and Width is " << originator->getWidth() << endl;
}
