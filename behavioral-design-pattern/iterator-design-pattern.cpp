#include <bits/stdc++.h>
using namespace std;

// Iterator Design Pattern:
// The Iterator Design Pattern is a behavioral design pattern that provides a way to access 
// elements of a collection (such as a list, set, or array) sequentially without exposing 
// the underlying representation. It standardizes iteration over elements regardless of the collection's structure.

// Book class
// Represents a book with a name and cost.
class Book {
private:
    string bookName; // Name of the book
    int bookCost;    // Cost of the book

public:
    /**
     * @brief Constructs a new Book object.
     * 
     * @param bn The name of the book.
     * @param bc The cost of the book.
     */
    Book(string bn, int bc) : bookName(bn), bookCost(bc) {}

    /**
     * @brief Gets the name of the book.
     * 
     * @return The book name as a string.
     */
    string getBookName() {
        return bookName;
    }

    /**
     * @brief Gets the cost of the book.
     * 
     * @return The book cost as an integer.
     */
    int getBookCost() {
        return bookCost;
    }
};

// Iterator class (Abstract Template)
// Defines an interface for iterating over a collection.
template<typename T>
class Iterator {
public:
    /**
     * @brief Checks if there are more elements to iterate over.
     * 
     * @return True if more elements exist, otherwise false.
     */
    virtual bool hasNext() = 0;

    /**
     * @brief Retrieves the next element in the collection.
     * 
     * @return The next element of type T.
     */
    virtual T next() = 0;
};

// BookIterator class
// Implements the Iterator interface for the Book class.
class BookIterator : public Iterator<Book> {
private:
    vector<Book> books; // Collection of books
    int index;          // Current position in the collection

public:
    /**
     * @brief Constructs a BookIterator object.
     * 
     * @param b A vector of books to iterate over.
     */
    BookIterator(vector<Book> b) {
        books = b;
        index = 0; // Start at the beginning of the collection
    }

    /**
     * @brief Checks if there are more books to iterate over.
     * 
     * @return True if more books exist, otherwise false.
     */
    bool hasNext() {
        return index < books.size();
    }

    /**
     * @brief Retrieves the next book in the collection.
     * 
     * @return The next Book object.
     */
    Book next() {
        Book book = books[index];
        index++;
        return book;
    }
};

// Aggregator class (Abstract Template)
// Defines an interface for creating an iterator for a collection.
template<typename T>
class Aggregator {
public:
    /**
     * @brief Creates and returns an iterator for the collection.
     * 
     * @return A pointer to an Iterator of type T.
     */
    virtual Iterator<T>* createIterator() = 0;
};

// Library class
// Implements the Aggregator interface to manage a collection of books.
class Library : public Aggregator<Book> {
private:
    vector<Book> books; // Collection of books

public:
    /**
     * @brief Constructs a new Library object.
     * 
     * This constructor initializes the books collection as empty.
     */
    Library() {
        books.clear();
    }

    /**
     * @brief Creates and returns an iterator for the books collection.
     * 
     * @return A pointer to a BookIterator object.
     */
    Iterator<Book>* createIterator() {
        return new BookIterator(books);
    }

    /**
     * @brief Adds a book to the library.
     * 
     * @param book The Book object to add.
     */
    void addBook(Book book) {
        books.push_back(book);
    }
};

// Main function
/**
 * @brief Demonstrates the Iterator Design Pattern.
 * 
 * This function creates a Library object, adds books to it, and uses an iterator to 
 * sequentially access and print the names of the books in the library.
 */
int main() {
    // Create a library object
    Library *library = new Library();

    // Add books to the library
    library->addBook(Book("book1", 35));
    library->addBook(Book("book2", 45));
    library->addBook(Book("book3", 55));
    library->addBook(Book("book4", 65));

    // Create an iterator for the library
    Iterator<Book>* iterator = library->createIterator();

    // Use the iterator to traverse and print the book names
    while (iterator->hasNext()) {
        cout << iterator->next().getBookName() << endl;
    }

    // Clean up dynamically allocated memory
    delete iterator;
    delete library;

    return 0;
}
