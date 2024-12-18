#include <bits/stdc++.h>
using namespace std;

// Interpreter Design Pattern:
// The Interpreter Design Pattern is a behavioral design pattern used to define a grammar 
// for a simple language and an interpreter that uses the grammar to interpret statements 
// in the language. It provides a way to evaluate sentences or expressions in a defined 
// language or format.

// Context class
// The Context class is used to store and retrieve variable values in the form of key-value pairs.
// It serves as the environment for the interpretation process, where variables and their values 
// are maintained.
class Context {
private:
    map<string, int> m; // Stores variable-value pairs

public:
    /**
     * @brief Constructs a new Context object.
     * 
     * This constructor initializes the internal map by clearing any pre-existing values.
     */
    Context() {
        m.clear();
    }

    /**
     * @brief Adds a variable and its value to the context.
     * 
     * @param var The variable name as a string.
     * @param val The value of the variable as an integer.
     */
    void put(string var, int val) {
        m[var] = val;
    }

    /**
     * @brief Retrieves the value of a variable from the context.
     * 
     * @param var The variable name as a string.
     * @return The value of the variable as an integer.
     */
    int get(string var) {
        return m[var];
    }
};

// AbstractExpression class
// The AbstractExpression class is an interface for all expression types. 
// It defines the interpreter method, which must be implemented by all concrete expressions.
class AbstractExpression {
public:
    /**
     * @brief Evaluates the expression using the provided context.
     * 
     * @param context A pointer to the Context object containing variable values.
     * @return The result of the interpretation as an integer.
     */
    virtual int interpreter(Context *context) = 0;
};

// TerminalExpression class
// The TerminalExpression class represents variables in the expression. 
// It evaluates a variable by retrieving its value from the context.
class TerminalExpression : public AbstractExpression {
    string variable; // The variable name

public:
    /**
     * @brief Constructs a TerminalExpression with a variable name.
     * 
     * @param var The variable name as a string.
     */
    TerminalExpression(string var) : variable(var) {}

    /**
     * @brief Evaluates the variable by retrieving its value from the context.
     * 
     * @param context A pointer to the Context object containing variable values.
     * @return The value of the variable as an integer.
     */
    int interpreter(Context *context) {
        return context->get(variable);
    }
};

// MultiplyNonTerminalExpression class
// This class represents a multiplication operation between two expressions.
class MultiplyNonTerminalExpression : public AbstractExpression {
    AbstractExpression *leftExpresion;  // The left-hand operand
    AbstractExpression *rightExpression; // The right-hand operand

public:
    /**
     * @brief Constructs a MultiplyNonTerminalExpression with two operands.
     * 
     * @param l A pointer to the left-hand expression.
     * @param r A pointer to the right-hand expression.
     */
    MultiplyNonTerminalExpression(AbstractExpression *l, AbstractExpression *r)
        : leftExpresion(l), rightExpression(r) {}

    /**
     * @brief Evaluates the multiplication operation.
     * 
     * @param context A pointer to the Context object containing variable values.
     * @return The result of the multiplication as an integer.
     */
    int interpreter(Context *context) {
        return (leftExpresion->interpreter(context) * rightExpression->interpreter(context));
    }
};

// SumNonTerminalExpression class
// This class represents an addition operation between two expressions.
class SumNonTerminalExpression : public AbstractExpression {
    AbstractExpression *leftExpresion;  // The left-hand operand
    AbstractExpression *rightExpression; // The right-hand operand

public:
    /**
     * @brief Constructs a SumNonTerminalExpression with two operands.
     * 
     * @param l A pointer to the left-hand expression.
     * @param r A pointer to the right-hand expression.
     */
    SumNonTerminalExpression(AbstractExpression *l, AbstractExpression *r)
        : leftExpresion(l), rightExpression(r) {}

    /**
     * @brief Evaluates the addition operation.
     * 
     * @param context A pointer to the Context object containing variable values.
     * @return The result of the addition as an integer.
     */
    int interpreter(Context *context) {
        return (leftExpresion->interpreter(context) + rightExpression->interpreter(context));
    }
};

// Main function
/**
 * @brief Demonstrates the Interpreter Design Pattern.
 * 
 * This function creates a context to store variable values and uses terminal 
 * and non-terminal expressions to evaluate a complex mathematical expression.
 * The result of the expression is printed to the console.
 */
int main() {
    // Create a context and populate it with variable values
    Context *context = new Context();
    context->put("num1", 2);
    context->put("num2", 3);
    context->put("num3", 4);
    context->put("num4", 5);

    // Construct expressions
    AbstractExpression *expression1 = new MultiplyNonTerminalExpression(
        new TerminalExpression("num1"), new TerminalExpression("num2"));
    AbstractExpression *expression2 = new MultiplyNonTerminalExpression(
        new TerminalExpression("num3"), new TerminalExpression("num4"));
    AbstractExpression *expression3 = new SumNonTerminalExpression(expression1, expression2);

    // Evaluate the expression and print the result
    cout << "Value of expression is " << expression3->interpreter(context) << endl;

    return 0;
}
