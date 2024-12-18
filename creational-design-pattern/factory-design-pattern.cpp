#include <bits/stdc++.h>
using namespace std;

// The Factory Pattern is a creational design pattern that provides an interface for creating objects in a superclass, 
// but allows subclasses to alter the type of objects that will be created. Below is an example of how you can implement the Factory Pattern 
// in C++ to create different types of shapes like Circle, Square, and Rectangle.

// Abstract class Shape, representing a generic shape.
class Shape {
public:
    virtual void draw() = 0;  // Pure virtual function to draw the shape, which must be implemented by derived classes.
};

// Concrete class Circle that inherits from Shape and implements the draw method.
class Circle: public Shape {
    public:
    void draw() {
        cout << "circle" << endl;  // Draw the circle by printing "circle".
    }
};

// Concrete class Rectangle that inherits from Shape and implements the draw method.
class Rectangle: public Shape {
    public:
    void draw() {
        cout << "rectangle" << endl;  // Draw the rectangle by printing "rectangle".
    }
};

// Concrete class Square that inherits from Shape and implements the draw method.
class Square: public Shape {
    public:
    void draw() {
        cout << "square" << endl;  // Draw the square by printing "square".
    }
};

// Factory class responsible for creating shapes based on input.
class ShapeFactory {
    public:
    // The getShape method returns a pointer to a Shape object based on the string input.
    Shape *getShape(string shape) {
        Shape* ans;
        if(shape == "CIRCLE") {
            ans = new Circle();  // If input is "CIRCLE", create a Circle object.
        } else if(shape == "RECTANGLE") {
            ans = new Rectangle();  // If input is "RECTANGLE", create a Rectangle object.
        } else {
            ans = new Square();  // If input is anything else, create a Square object.
        }
        return ans;  // Return the created Shape object.
    }
};

int main() {
    // Main function to demonstrate the Factory Pattern.
    
    ShapeFactory *shapeFactory = new ShapeFactory();  // Create a ShapeFactory object.
    
    // Get a Rectangle object by passing "RECTANGLE" as input to the factory.
    Shape* shape = shapeFactory->getShape("RECTANGLE");
    
    // Call the draw method of the created shape (Rectangle in this case).
    shape->draw();  // Output: "rectangle"
    
    return 0;
}
