#include <bits/stdc++.h>
using namespace std;

// Visitor Design Pattern: The pattern allows separating operations (like pricing or maintenance)
// from the classes (rooms) that the operations are performed on. It provides a way to define new 
// operations without modifying the classes of the elements.

class SingleRoom; // Forward declaration
class DoubleRoom; // Forward declaration
class DeluxRoom;  // Forward declaration

// Abstract Visitor class defining the visit methods for different room types
class RoomVisitor {
public:
    virtual void visit(SingleRoom *singleRoom) = 0; // Visit single room
    virtual void visit(DoubleRoom *doubleRoom) = 0; // Visit double room
    virtual void visit(DeluxRoom *deluxRoom) = 0;   // Visit deluxe room
};

// Abstract Element class with the accept method
class RoomElement {
public:
    virtual void accept(RoomVisitor *visitor) = 0; // Accept visitor
};

// Concrete Element class for a single room
class SingleRoom : public RoomElement {
public:
    int roomPrice = 1000; // Price of a single room
    void accept(RoomVisitor *visitor) override {
        visitor->visit(this); // Accept a visitor and call its visit method
    }
};

// Concrete Element class for a double room
class DoubleRoom : public RoomElement {
public:
    int roomPrice = 2000; // Price of a double room
    void accept(RoomVisitor *visitor) override {
        visitor->visit(this); // Accept a visitor and call its visit method
    }
};

// Concrete Element class for a deluxe room
class DeluxRoom : public RoomElement {
public:
    int roomPrice = 3000; // Price of a deluxe room
    void accept(RoomVisitor *visitor) override {
        visitor->visit(this); // Accept a visitor and call its visit method
    }
};

// Concrete Visitor class for calculating the pricing of rooms
class RoomPricingVisitor : public RoomVisitor {
public:
    /**
     * Prints the price of a single room to the console.
     * @param singleRoom Pointer to a SingleRoom object
     */
    void visit(SingleRoom *singleRoom) override {
        cout << "Price for this single room is " << singleRoom->roomPrice << endl;
    }

    /**
     * Prints the price of a double room to the console.
     * @param doubleRoom Pointer to a DoubleRoom object
     */
    void visit(DoubleRoom *doubleRoom) override {
        cout << "Price for this double room is " << doubleRoom->roomPrice << endl;

    }
    /**
     * Prints the price of a deluxe room to the console.
     * @param deluxRoom Pointer to a DeluxRoom object
     */

    void visit(DeluxRoom *deluxRoom) override {
        cout << "Price for this deluxe room is " << deluxRoom->roomPrice << endl;

    }
};

// Concrete Visitor class for performing maintenance on rooms
class RoomMaintainenceVisitor : public RoomVisitor {
public:
    void visit(SingleRoom *singleRoom) override {
        cout << "Maintenance for this single room" << endl;
    }
    void visit(DoubleRoom *doubleRoom) override {
        cout << "Maintenance for this double room" << endl;
    }
    void visit(DeluxRoom *deluxRoom) override {
        cout << "Maintenance for this deluxe room" << endl;
    }
};

int main() {
    // Create instances of different room types
    SingleRoom *singleRoom = new SingleRoom();
    DoubleRoom *doubleRoom = new DoubleRoom();
    DeluxRoom *deluxRoom = new DeluxRoom();
    
    // Create instances of different visitors (Room Pricing and Room Maintenance)
    RoomVisitor *roomPricingVisitor = new RoomPricingVisitor();
    RoomVisitor *roomMaintainenceVisitor = new RoomMaintainenceVisitor();
    
    // Accept visitors to perform operations
    singleRoom->accept(roomPricingVisitor);  // Pricing for single room
    doubleRoom->accept(roomPricingVisitor);  // Pricing for double room
    deluxRoom->accept(roomPricingVisitor);   // Pricing for deluxe room
    
    cout << "-----------------" << endl;
    
    // Accept maintenance visitor to perform operations
    singleRoom->accept(roomMaintainenceVisitor);  // Maintenance for single room
    doubleRoom->accept(roomMaintainenceVisitor);  // Maintenance for double room
    deluxRoom->accept(roomMaintainenceVisitor);   // Maintenance for deluxe room
    
    return 0;
}


