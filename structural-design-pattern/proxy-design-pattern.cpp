#include <bits/stdc++.h>
using namespace std;

// The Proxy Design Pattern is a structural design pattern that provides a surrogate or placeholder
// for another object to control access to it. This pattern is useful for access restriction, caching,
// pre- or post-processing, and other scenarios where direct access to an object is expensive or unsafe.

// Class representing an Employee with an ID and name.
class Employee {
    public:
    int employeeId;      // Employee ID.
    string employeeName; // Employee Name.

    // Default constructor.
    Employee() = default;

    // Parameterized constructor to initialize an employee object.
    Employee(int eid, string eName) : employeeId(eid), employeeName(eName) {}
};

// Abstract class defining the Employee Database interface.
// This serves as the base class for both the concrete implementation and the proxy.
class EmployeeDB {
    public:
    /**
     * @brief Create a new employee record.
     * @param client The client attempting the operation.
     * @param employee The employee object to be added.
     */
    virtual void create(string client, Employee employee) = 0;

    /**
     * @brief Retrieve an employee's name by ID.
     * @param client The client attempting the operation.
     * @param employeeId The ID of the employee to retrieve.
     * @return The name of the employee.
     */
    virtual string get(string client, int employeeId) = 0;
};

// Concrete implementation of the Employee Database interface.
// Stores employee records in a map for efficient retrieval.
class EmployeeDBImpl : public EmployeeDB {
    private:
    map<int, Employee> db; // Map storing Employee objects indexed by employeeId.

    public:
    // Constructor initializes the database.
    EmployeeDBImpl() {
        db.clear();
    }

    // Adds a new employee to the database.
    void create(string client, Employee employee) override {
        db[employee.employeeId] = employee;
    }

    // Retrieves an employee's name by their ID.
    string get(string client, int employeeId) override {
        if (db.find(employeeId) == db.end()) {
            throw runtime_error("No user found"); // Handle case where employeeId is not in the database.
        }
        return db[employeeId].employeeName;
    }
};

// Proxy class for the Employee Database.
// Controls access to the actual `EmployeeDBImpl` by checking client permissions.
class EmployeeDBProxy : public EmployeeDB {
    private:
    EmployeeDB* employeeDBImpl; // The real EmployeeDB implementation.

    public:
    // Constructor initializes the proxy with an instance of the real database implementation.
    EmployeeDBProxy() : employeeDBImpl(new EmployeeDBImpl()) {}

    // Destructor to clean up dynamically allocated memory.
    ~EmployeeDBProxy() {
        delete employeeDBImpl;
    }

    // Adds a new employee record if the client is "ADMIN".
    void create(string client, Employee employee) override {
        if (client == "ADMIN") {
            employeeDBImpl->create(client, employee);
            return;
        }
        throw runtime_error("Access denied"); // Non-admin clients cannot create records.
    }

    // Retrieves an employee's name if the client is "ADMIN" or "USER".
    string get(string client, int employeeId) override {
        if (client == "ADMIN" || client == "USER") {
            return employeeDBImpl->get(client, employeeId);
        }
        throw runtime_error("Access denied"); // Other clients cannot retrieve records.
    }
};

int main() {
    // Create a proxy for the Employee Database.
    EmployeeDB* employeeDBProxy = new EmployeeDBProxy();

    // Create an employee object.
    Employee employee1(1, "Samyak");

    try {
        // Admin creates a new employee record.
        employeeDBProxy->create("ADMIN", employee1);

        // User retrieves the employee record.
        cout << employeeDBProxy->get("USER", 1) << endl;

    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << endl; // Handle exceptions gracefully.
    }

    // Clean up dynamically allocated memory.
    delete employeeDBProxy;

    return 0;
}
