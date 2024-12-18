#include <bits/stdc++.h>
using namespace std;

// Template Method Design Pattern: The base class (IPayment) defines the structure
// of the algorithm (sending money), while subclasses define specific steps (how to 
// validate requests, calculate fees, debit, and credit amounts for different payment types).

// Abstract Base Class defining the template method
class IPayment {
public:
    // Template method defining the skeleton of the algorithm
    // The 'sendMoney' method is final, ensuring it can't be overridden by subclasses.
    // It calls the common steps in a fixed order.
    virtual void sendMoney() final {
        validateRequest(); // Step 1
        calculateFees();   // Step 2
        debitAmount();     // Step 3
        creditAmount();    // Step 4
    }
    
    // These are the abstract methods that must be implemented by subclasses
    virtual void validateRequest() = 0;
    virtual void calculateFees() = 0;
    virtual void debitAmount() = 0;
    virtual void creditAmount() = 0;
};

// Subclass for sending money to a friend
class PayToFriend : public IPayment {
public:
    void validateRequest() override {
        cout << "Validate Request for Pay to friend" << endl;
    }
    
    void calculateFees() override {
        cout << "Calculate fees for Pay to friend" << endl;
    }
    
    void debitAmount() override {
        cout << "Debit amount for Pay to friend" << endl;
    }
    
    void creditAmount() override {
        cout << "Credit amount for Pay to friend" << endl;
    }
};

// Subclass for sending money to a merchant
class PayToMerch : public IPayment {
public:
    void validateRequest() override {
        cout << "Validate Request for Pay to Merch" << endl;
    }
    
    void calculateFees() override {
        cout << "Calculate fees for Pay to Merch" << endl;
    }
    
    void debitAmount() override {
        cout << "Debit amount for Pay to Merch" << endl;
    }
    
    void creditAmount() override {
        cout << "Credit amount for Pay to Merch" << endl;
    }
};

int main() {
    // Create an instance of PayToFriend
    IPayment* payToFriend = new PayToFriend();
    // Calling the template method to execute the payment process
    payToFriend->sendMoney();
    
    cout << "----------------------" << endl;
    
    // Create an instance of PayToMerch
    IPayment* payToMerch = new PayToMerch();
    // Calling the template method to execute the payment process
    payToMerch->sendMoney();
}
