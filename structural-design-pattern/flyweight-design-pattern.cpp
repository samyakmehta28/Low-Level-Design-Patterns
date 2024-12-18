#include <bits/stdc++.h>
using namespace std;

// FlyWeight Design Pattern:
// The Flyweight design pattern is a structural design pattern aimed at reducing memory usage by sharing as much data as possible with similar objects.
// It reuses existing instances instead of creating new ones for every instance, which minimizes memory footprint.

// Abstract interface for a letter.
// This interface enforces a contract for all letter types to implement the `display` method.
class ILetter {
    public:
    /**
     * @brief Displays the letter at the given coordinates.
     * 
     * @param x The x-coordinate where the letter will be displayed.
     * @param y The y-coordinate where the letter will be displayed.
     */
    virtual void display(int x, int y) = 0;
};

// Concrete implementation of the ILetter interface.
// This class represents a specific letter with properties like font type and size.
class DocumentCharacter : public ILetter {
    private:
    char character;     // The character to be displayed.
    string fontType;    // Font type of the character.
    int fontSize;       // Font size of the character.

    public:
    /**
     * @brief Constructor to initialize a DocumentCharacter.
     * 
     * @param c The character to create.
     * @param ft The font type of the character.
     * @param fs The font size of the character.
     */
    DocumentCharacter(char c, string ft, int fs) : character(c), fontType(ft), fontSize(fs) {}

    /**
     * @brief Displays the character at the given coordinates.
     * 
     * Prints the character and its position.
     * @param x The x-coordinate where the character is displayed.
     * @param y The y-coordinate where the character is displayed.
     */
    void display(int x, int y) {
        cout << character << " at " << x << ' ' << y << endl;
    }
};

// Factory class to manage creation and reuse of letter objects.
// Uses a static `cache` to store already created letters and ensures reuse.
class LetterFactory {
    private:
    static map<char, ILetter*> cache; // Cache to store created letters.

    public:
    /**
     * @brief Creates or retrieves a letter object.
     * 
     * Checks the cache to see if the requested letter already exists.
     * If not, creates a new letter, stores it in the cache, and returns it.
     * @param character The character to create or retrieve.
     * @param fontType The font type of the character.
     * @param fontSize The font size of the character.
     * @return A pointer to the letter object.
     */
    static ILetter* createLetter(char character, string fontType, int fontSize) {
        // Check if the character already exists in the cache.
        if (cache.find(character) == cache.end()) {
            cout << "Creating new Letter " << character << endl;
            ILetter* iLetter = new DocumentCharacter(character, fontType, fontSize);
            cache[character] = iLetter; // Store the new letter in the cache.
        }
        return cache[character]; // Return the cached letter.
    }
};

// Initialize the static cache.
map<char, ILetter*> LetterFactory::cache = {};

/**
 * @brief Main function demonstrating the Flyweight Design Pattern.
 * 
 * Creates and reuses letter objects using the LetterFactory. The Flyweight pattern ensures that
 * letters with the same character are created only once and reused, showcasing memory efficiency.
 */
int main() {
    // Create and display letters using the LetterFactory.
    ILetter* letter1 = LetterFactory::createLetter('t', "sans", 16);
    letter1->display(0, 0);

    ILetter* letter2 = LetterFactory::createLetter('h', "sans", 16);
    letter2->display(0, 1);

    ILetter* letter3 = LetterFactory::createLetter('a', "sans", 16);
    letter3->display(0, 2);

    // Reuse the previously created letter 't'.
    ILetter* letter4 = LetterFactory::createLetter('t', "sans", 16);
    letter4->display(0, 3);

    return 0;
}
