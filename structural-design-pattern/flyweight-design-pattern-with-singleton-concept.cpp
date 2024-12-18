#include <bits/stdc++.h>
using namespace std;

// FlyWeight Design Pattern:
// The Flyweight design pattern is a structural design pattern aimed at reducing memory usage by sharing as much data as possible with similar objects.
// This pattern is particularly useful when you need to create a large number of similar objects. 
// Instead of creating new objects for every instance, the Flyweight pattern reuses existing instances, minimizing memory footprint.

// Abstract base class for letters.
// This class provides a common interface for all letter objects. 
// The display method is a pure virtual function that derived classes must implement.
class ILetter {
    public:
    /**
     * @brief Displays the letter at the given position.
     * 
     * This method is a pure virtual function that will be implemented by derived classes.
     * @param x The x-coordinate where the letter will be displayed.
     * @param y The y-coordinate where the letter will be displayed.
     */
    virtual void display(int x, int y) = 0;
};

// Concrete implementation of the ILetter interface.
// This class represents a document character with properties like character, font type, and font size.
class DocumentCharacter : public ILetter {
    private:
    char character;     // The character to be displayed.
    string fontType;    // The font type of the character.
    int fontSize;       // The font size of the character.

    public:
    /**
     * @brief Constructor for DocumentCharacter.
     * 
     * Initializes a character with the given font type and size.
     * @param c The character to be created.
     * @param ft The font type of the character.
     * @param fs The font size of the character.
     */
    DocumentCharacter(char c, string ft, int fs) : character(c), fontType(ft), fontSize(fs) {}

    /**
     * @brief Displays the character at the specified position.
     * 
     * Prints the character and its position on the console.
     * @param x The x-coordinate where the character is displayed.
     * @param y The y-coordinate where the character is displayed.
     */
    void display(int x, int y) {
        cout << character << " at " << x << ' ' << y << endl;
    }
};

// Singleton Factory class for creating and managing letter objects.
// This class ensures that only one instance of itself exists and reuses existing letter objects to minimize memory usage.
class LetterFactory {
    private:
    static LetterFactory *letterFactory;   // Singleton instance of LetterFactory.
    map<char, ILetter*> cache;            // Cache to store already created letter objects.

    /**
     * @brief Private constructor for LetterFactory.
     * 
     * Ensures that no objects of LetterFactory can be created directly.
     */
    LetterFactory() {}

    public:
    /**
     * @brief Retrieves the singleton instance of LetterFactory.
     * 
     * @return The singleton instance of LetterFactory.
     */
    static LetterFactory *getLetterFactory() {
        return letterFactory;
    }

    /**
     * @brief Creates or retrieves a letter object.
     * 
     * If the requested letter already exists in the cache, it is returned.
     * Otherwise, a new letter object is created, added to the cache, and returned.
     * @param character The character for which a letter object is requested.
     * @param fontType The font type of the letter.
     * @param fontSize The font size of the letter.
     * @return A pointer to the letter object.
     */
    ILetter *createLetter(char character, string fontType, int fontSize) {
        // Check if the letter already exists in the cache.
        if (cache.find(character) == cache.end()) {
            cout << "Creating new Letter " << character << endl;
            ILetter *iLetter = new DocumentCharacter(character, fontType, fontSize);
            cache[character] = iLetter; // Store the newly created letter in the cache.
        }
        return cache[character]; // Return the cached letter.
    }
};

// Initialize the static singleton instance.
LetterFactory* LetterFactory::letterFactory = new LetterFactory();

/**
 * @brief Main function to demonstrate the Flyweight Design Pattern.
 * 
 * This function uses the LetterFactory to create and reuse letter objects.
 * Letters with the same character are created only once and reused multiple times, showcasing the memory efficiency of the Flyweight pattern.
 */
int main() {
    // Get the singleton instance of LetterFactory.
    LetterFactory *letterFactory1 = LetterFactory::getLetterFactory();

    // Create and display letters using the first instance of LetterFactory.
    ILetter *letter1 = letterFactory1->createLetter('t', "sans", 16);
    letter1->display(0, 0);
    ILetter *letter2 = letterFactory1->createLetter('h', "sans", 16);
    letter2->display(0, 1);
    ILetter *letter3 = letterFactory1->createLetter('a', "sans", 16);
    letter3->display(0, 2);
    ILetter *letter4 = letterFactory1->createLetter('t', "sans", 16);
    letter4->display(0, 3);

    cout << "---------------------------------" << endl;

    // Get the singleton instance of LetterFactory again to demonstrate reuse.
    LetterFactory *letterFactory2 = LetterFactory::getLetterFactory();

    // Create and display letters using the second instance of LetterFactory.
    ILetter *letter5 = letterFactory2->createLetter('t', "sans", 16);
    letter5->display(0, 0);
    ILetter *letter6 = letterFactory2->createLetter('h', "sans", 16);
    letter6->display(0, 1);
    ILetter *letter7 = letterFactory2->createLetter('i', "sans", 16);
    letter7->display(0, 2);
    ILetter *letter8 = letterFactory2->createLetter('s', "sans", 16);
    letter8->display(0, 3);
}
