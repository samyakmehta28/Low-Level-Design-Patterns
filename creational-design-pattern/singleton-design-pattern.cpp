#include <bits/stdc++.h>
using namespace std;

// Singleton Design Pattern: ensures only one instance of a class is created and provides a global access point to that instance.

// Eager Initialization
class EagerDBConnect {
private:
    EagerDBConnect() {};  // Private constructor to prevent instantiation.
    static EagerDBConnect* eagerDBConnect;  // Static instance, eagerly created when the program starts.

public:
    // Static method to get the instance of EagerDBConnect.
    static EagerDBConnect* getDBConnection() {
        return eagerDBConnect;  // Return the already created instance.
    }

    // Method to print a message indicating eager initialization.
    void print() {
        cout << "Eager Initialization" << endl;
    }
};

// Static initialization outside the class.
EagerDBConnect* EagerDBConnect::eagerDBConnect = new EagerDBConnect();

// Lazy Initialization
class LazyDBConnect {
private:
    LazyDBConnect() {};  // Private constructor to prevent instantiation.
    static LazyDBConnect* lazyDBConnect;  // Static pointer that will be initialized when first needed.

public:
    // Static method to get the instance of LazyDBConnect.
    static LazyDBConnect* getDBConnection() {
        if (lazyDBConnect == NULL) {
            lazyDBConnect = new LazyDBConnect();  // Instance created only when needed (lazily).
        }
        return lazyDBConnect;  // Return the instance.
    }

    // Method to print a message indicating lazy initialization.
    void print() {
        cout << "Lazy Initialization" << endl;
    }
};

// Static initialization outside the class.
LazyDBConnect* LazyDBConnect::lazyDBConnect = NULL;

// Double-Checked Locking Singleton (Thread-Safe)
mutex mtx;  // Mutex for thread synchronization, ensuring only one thread can create the instance at a time.

class DoubleLockingDBConnect {
private:
    DoubleLockingDBConnect() {};  // Private constructor to prevent instantiation.
    static DoubleLockingDBConnect* doubleLockingDBConnect;  // Static pointer to hold the single instance.

public:
    // Static method to get the instance of DoubleLockingDBConnect.
    static DoubleLockingDBConnect* getDBConnection() {
        if (doubleLockingDBConnect == NULL) {  // First check if the instance is not created yet.
            mtx.lock();  // Lock to ensure only one thread enters the critical section.
            if (doubleLockingDBConnect == NULL) {  // Double check to prevent race condition.
                doubleLockingDBConnect = new DoubleLockingDBConnect();  // Create the instance.
            }
            mtx.unlock();  // Unlock after instance creation.
        }
        return doubleLockingDBConnect;  // Return the instance.
    }

    // Method to print a message indicating double-checked locking initialization.
    void print() {
        cout << "Double Locking Initialization" << endl;
    }
};

// Static initialization outside the class.
DoubleLockingDBConnect* DoubleLockingDBConnect::doubleLockingDBConnect = NULL;

int main() {
    // Creating and testing the EagerDBConnect singleton.
    EagerDBConnect* eagerdbConnection = EagerDBConnect::getDBConnection();
    eagerdbConnection->print();  // Print message for eager initialization.

    // Creating and testing the LazyDBConnect singleton.
    LazyDBConnect* lazyDBConnect = LazyDBConnect::getDBConnection();
    lazyDBConnect->print();  // Print message for lazy initialization.

    // Creating and testing the DoubleLockingDBConnect singleton.
    DoubleLockingDBConnect* doubleLockingDBConnect = DoubleLockingDBConnect::getDBConnection();
    doubleLockingDBConnect->print();  // Print message for double-locking initialization.
}

