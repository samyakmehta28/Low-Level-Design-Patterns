#include <bits/stdc++.h>
using namespace std;

// Mediator Design Pattern:
// The Mediator Design Pattern is a behavioral design pattern that promotes loose coupling between objects by centralizing communication through a mediator object. 
// Instead of objects communicating directly with each other, they send messages to a mediator, which handles the communication and interaction logic. 
// This reduces dependencies between interacting objects, making the system more maintainable and flexible.

// Abstract interface for a bidder in the auction
class IBidder {
public:
    virtual void placeBid(int bidAmount) = 0;                // Places a bid
    virtual void receiveBidNotification(string bidderName, int bidAmount) = 0; // Receives notification of other bids
    virtual string getName() = 0;                           // Returns the name of the bidder
};

// Abstract interface for the mediator
class IAuctionMediator {
public:
    virtual void addBidder(IBidder *bidder) = 0;            // Adds a bidder to the auction
    virtual void placeBid(IBidder *bidder, int bidAmount) = 0; // Handles the bid placement
};

// Concrete implementation of a bidder
class Bidder : public IBidder {
    string name;                   // Name of the bidder
    IAuctionMediator *auctionMediator; // Reference to the mediator

public:
    // Constructor to initialize the bidder and register with the mediator
    Bidder(string nm, IAuctionMediator *am) : name(nm), auctionMediator(am) {
        auctionMediator->addBidder(this); // Register bidder with the mediator
    }

    // Places a bid and notifies the mediator
    void placeBid(int bidAmount) override {
        cout << name << " placed a bid of " << bidAmount << endl;
        auctionMediator->placeBid(this, bidAmount); // Notify mediator of the bid
    }

    // Receives notification of another bidder's action
    void receiveBidNotification(string bidderName, int bidAmount) override {
        cout << name << " received notification that " << bidderName << " placed a bid of " << bidAmount << endl;
    }

    // Returns the name of the bidder
    string getName() override {
        return name;
    }
};

// Concrete implementation of the auction mediator
class AuctionMediator : public IAuctionMediator {
    set<IBidder *> bidders; // Collection of bidders participating in the auction

public:
    // Constructor initializes an empty set of bidders
    AuctionMediator() {
        bidders.clear();
    }

    // Adds a new bidder to the collection
    void addBidder(IBidder *bidder) override {
        bidders.insert(bidder);
    }

    // Handles bid placement and notifies other bidders
    void placeBid(IBidder *bidder, int bidAmount) override {
        for (auto notifyBidder : bidders) {
            if (notifyBidder != bidder) { // Skip the bidder who placed the bid
                notifyBidder->receiveBidNotification(bidder->getName(), bidAmount);
            }
        }
    }
};

// Main function to demonstrate the Mediator Design Pattern
int main() {
    // Create the auction mediator
    IAuctionMediator *auctionMediator = new AuctionMediator();

    // Create bidders and register them with the mediator
    IBidder *bidder1 = new Bidder("samyak", auctionMediator);
    IBidder *bidder2 = new Bidder("shreya", auctionMediator);
    IBidder *bidder3 = new Bidder("aishik", auctionMediator);

    // Place bids
    bidder1->placeBid(100); // Samyak places a bid
    cout << "--------------" << endl;

    bidder2->placeBid(200); // Shreya places a bid
    cout << "--------------" << endl;

    bidder3->placeBid(300); // Aishik places a bid

    // Clean up dynamically allocated memory
    delete bidder1;
    delete bidder2;
    delete bidder3;
    delete auctionMediator;

    return 0;
}


