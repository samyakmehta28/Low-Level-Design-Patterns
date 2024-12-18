#include <bits/stdc++.h>
using namespace std;

// Forward declaration of StocksObservable class
class StocksObservable;

// Interface for observers that need to be notified
class NotifyAlertObserver {
    public: 
    // Pure virtual function to update observer with changes from the observable
    virtual void update(StocksObservable* observable) = 0;
};

// Interface for observables that notify observers
class StocksObservable {
    public:
        // Pure virtual function to add an observer to the observable's list
        virtual void add(NotifyAlertObserver *observer) = 0;

        // Pure virtual function to remove an observer from the observable's list
        virtual void remove(NotifyAlertObserver *observer) = 0;

        // Pure virtual function to notify all observers of changes
        virtual void notify() = 0;

        // Pure virtual function to set the stock count
        virtual void setStockCount(int stock) = 0;

        // Pure virtual function to get the current stock count
        virtual int getStockCount() = 0;
};

// Concrete implementation of StocksObservable for iPhone stocks
class IphoneStocksObservable: public StocksObservable {
    private:
    set<NotifyAlertObserver*> observerList;  // List of observers to notify
    int stockCount;  // Current stock count

    public:
        // Constructor initializes the observer list and stock count
        IphoneStocksObservable() {
            observerList.clear();
            stockCount = 0;
        }

        // Adds an observer to the list
        void add(NotifyAlertObserver *observer) {
            observerList.insert(observer);
        }

        // Removes an observer from the list
        void remove(NotifyAlertObserver *observer) {
            observerList.erase(observer);
        }

        // Notifies all observers of stock changes
        void notify() {
            for(NotifyAlertObserver* observer: observerList) {
                observer->update(this);
            }
        }

        // Sets the stock count and notifies observers if the previous stock count was zero
        void setStockCount(int stock) {
            if(stockCount == 0) {
                stockCount = stock;
                notify();
            }
            else {
                stockCount = stock;
            }
        }

        // Returns the current stock count
        int getStockCount() {
            return stockCount;
        }
};

// Concrete implementation of StocksObservable for Samsung stocks
class SamsungStocksObservable: public StocksObservable {
    private:
    set<NotifyAlertObserver*> observerList;  // List of observers to notify
    int stockCount;  // Current stock count

    public:
        // Constructor initializes the observer list and stock count
        SamsungStocksObservable() {
            observerList.clear();
            stockCount = 0;
        }

        // Adds an observer to the list
        void add(NotifyAlertObserver *observer) {
            observerList.insert(observer);
        }

        // Removes an observer from the list
        void remove(NotifyAlertObserver *observer) {
            observerList.erase(observer);
        }

        // Notifies all observers of stock changes
        void notify() {
            for(NotifyAlertObserver* observer: observerList) {
                observer->update(this);
            }
        }

        // Sets the stock count and notifies observers if the previous stock count was zero
        void setStockCount(int stock) {
            if(stockCount == 0) {
                stockCount = stock;
                notify();
            }
            else {
                stockCount = stock;
            }
        }

        // Returns the current stock count
        int getStockCount() {
            return stockCount;
        }
};

// Concrete implementation of NotifyAlertObserver for mobile alerts
class MobileAlertObserver: public NotifyAlertObserver {
    private:
    string username;  // User's name for alerting

    public:
    // Constructor initializes the observer with the user's name
    MobileAlertObserver(string un) {
        username = un;
    }


    // Updates the observer with the stock count and sends an alert
    void update(StocksObservable* observable) {
        cout << observable->getStockCount() << " sent to " << username << endl;
    }
};

// Concrete implementation of NotifyAlertObserver for email alerts
class EmailAlertObserver: public NotifyAlertObserver {
    private:
    string email;  // User's email for alerting

    public:
    // Constructor initializes the observer with the user's email
    EmailAlertObserver(string em) {
        email = em;
    }

    // Updates the observer with the stock count and sends an email alert
    void update(StocksObservable* observable) {
        cout << observable->getStockCount() << " sent to " << email << endl;
    }
};

// Main function demonstrating the observer pattern
int main() {
    // Creating observables for iPhone and Samsung stocks
    StocksObservable *iphoneStocksObservable = new IphoneStocksObservable();
    StocksObservable *samsungStocksObservable = new SamsungStocksObservable();

    // Creating observers for mobile and email alerts
    NotifyAlertObserver *observer1 = new MobileAlertObserver("samyak");
    NotifyAlertObserver *observer2 = new MobileAlertObserver("shreya");
    NotifyAlertObserver *observer3 = new EmailAlertObserver("Aishik@gamil.com");

    // Adding observers to observables
    iphoneStocksObservable->add(observer1);
    iphoneStocksObservable->add(observer2);
    iphoneStocksObservable->add(observer3);
    samsungStocksObservable->add(observer3);

    // Setting stock counts which will trigger notifications to observers
    iphoneStocksObservable->setStockCount(10);
    samsungStocksObservable->setStockCount(5);
}
          