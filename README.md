<p align="center">
    <img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" align="center" width="30%">
</p>
<p align="center"><h1 align="center">LOW-LEVEL-DESIGN-PATTERNS</h1></p>
<p align="center">
    <em>Crafting brilliance through low-level design mastery.</em>
</p>
<p align="center">
    <img src="https://img.shields.io/github/license/samyakmehta28/Low-Level-Design-Patterns?style=default&logo=opensourceinitiative&logoColor=white&color=0080ff" alt="license">
    <img src="https://img.shields.io/github/last-commit/samyakmehta28/Low-Level-Design-Patterns?style=default&logo=git&logoColor=white&color=0080ff" alt="last-commit">
    <img src="https://img.shields.io/github/languages/top/samyakmehta28/Low-Level-Design-Patterns?style=default&color=0080ff" alt="repo-top-language">
    <img src="https://img.shields.io/github/languages/count/samyakmehta28/Low-Level-Design-Patterns?style=default&color=0080ff" alt="repo-language-count">
</p>
<p align="center"><!-- default option, no dependency badges. -->
</p>
<p align="center">
    <!-- default option, no dependency badges. -->
</p>
<br>

## Table of Contents

- [ Overview](#-overview)
- [ Features](#-features)
- [ Project Structure](#-project-structure)
  - [ Project Index](#-project-index)
- [ Getting Started](#-getting-started)
  - [ Prerequisites](#-prerequisites)
  - [ Installation](#-installation)
- [ Contributing](#-contributing)
- [ License](#-license)
- [ Acknowledgments](#-acknowledgments)

---

## Overview

The Low-Level-Design-Patterns project offers a collection of practical code examples showcasing various design patterns like Builder, Singleton, and Factory. It simplifies creating complex objects, managing database connections efficiently, and enabling dynamic behaviors in software systems. Ideal for developers seeking hands-on guidance in designing robust and scalable applications.

---

## Features

|     |         Folder          | Summary                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| :-- | :---------------------: | :--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| ⚙️  | **Creational Patterns** | <ul><li>**Builder**: Separates the construction of a complex object from its representation.</li><li>**Singleton**: Ensures a class has only one instance and provides a global point of access to it.</li><li>**Factory**: Defines an interface for creating an object, but lets subclasses alter the type of objects that will be created.</li></ul>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| 🔩  | **Structural Patterns** | <ul><li>**Adapter**: Allows incompatible interfaces to work together.</li><li>**Bridge**: Decouples an abstraction from its implementation so that the two can vary independently.</li><li>**Composite**: Composes objects into tree structures to represent part-whole hierarchies.</li><li>**Decorator**: Adds additional responsibilities to an object dynamically.</li><li>**Facade**: Provides a simplified interface to a complex subsystem.</li><li>**Flyweight**: Reduces the cost of creating and manipulating a large number of similar objects.</li><li>**Proxy**: Provides a surrogate or placeholder for another object to control access to it.</li></ul>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    |
| 📄  | **Behavioral Patterns** | <ul><li>**Chain of Responsibility**: Passes a request along a chain of handlers.</li><li>**Command**: Encapsulates a request as an object, thereby allowing for parameterization and queuing of requests.</li><li>**Interpreter**: Defines a grammatical representation for a language and an interpreter to interpret the grammar.</li><li>**Iterator**: Provides a way to access the elements of an aggregate object sequentially without exposing its underlying representation.</li><li>**Mediator**: Defines an object that encapsulates how a set of objects interact.</li><li>**Memento**: Captures and externalizes an object's internal state without violating encapsulation.</li><li>**Observer**: Defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.</li><li>**State**: Allows an object to alter its behavior when its internal state changes.</li><li>**Strategy**: Defines a family of algorithms, encapsulates each one, and makes them interchangeable.</li><li>**Template Method**: Defines the skeleton of an algorithm in a method, deferring some steps to subclasses.</li><li>**Visitor**: Represents an operation to be performed on the elements of an object structure.</li></ul> |

---

## Project Structure

```sh
└── Low-Level-Design-Patterns/
    ├── README.md
    ├── behavioral-design-pattern
    │   ├── chain-of-responsibility-design-pattern.cpp
    │   ├── command-design-pattern.cpp
    │   ├── interpreter-design-pattern.cpp
    │   ├── iterator-design-pattern.cpp
    │   ├── mediator-design-pattern.cpp
    │   ├── momento-design-pattern.cpp
    │   ├── observer-design-pattern.cpp
    │   ├── state-design-pattern.png
    │   ├── strategy-design-pattern.cpp
    │   ├── template-design-pattern.cpp
    │   └── visitor-design-pattern.cpp
    ├── creational-design-pattern
    │   ├── builder-design-pattern.cpp
    │   ├── factory-design-pattern.cpp
    │   └── singleton-design-pattern.cpp
    └── structural-design-pattern
        ├── adapter-design-pattern.cpp
        ├── bridge-design-pattern.cpp
        ├── composite-design-pattern.cpp
        ├── decorator-design-pattern.cpp
        ├── facade-design-pattern.png
        ├── flyweight-design-pattern-with-singleton-concept.cpp
        ├── flyweight-design-pattern.cpp
        └── proxy-design-pattern.cpp
```

### Project Index

<details open>
    <summary><b><code>LOW-LEVEL-DESIGN-PATTERNS/</code></b></summary>
    <!-- <details> 
        <summary><b>__root__</b></summary>
        <blockquote>
            <table>
            </table>
        </blockquote>
    </details> -->
    <details> <!-- creational-design-pattern Submodule -->
        <summary><b>creational-design-pattern</b></summary>
        <blockquote>
            <table>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/creational-design-pattern/builder-design-pattern.cpp'>builder-design-pattern.cpp</a></b></td>
                <td>- Demonstrates the Builder design pattern for creating complex objects step by step<br>- Encapsulates object construction, enabling easy management and extension<br>- Concrete builders like EngineeringStudentBuilder and MBAStudentBuilder set specific attributes for different types of students<br>- Main function showcases building and printing details of Engineering and MBA students.</td>
            </tr>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/creational-design-pattern/singleton-design-pattern.cpp'>singleton-design-pattern.cpp</a></b></td>
                <td>- Implements singleton design patterns for database connections with eager, lazy, and double-checked locking initialization methods<br>- Provides global access to single instances of classes, ensuring thread safety and efficient resource usage<br>- Demonstrates different strategies for creating and accessing singleton objects in the codebase architecture.</td>
            </tr>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/creational-design-pattern/factory-design-pattern.cpp'>factory-design-pattern.cpp</a></b></td>
                <td>- Implements Factory Pattern to create various shapes like Circle, Square, and Rectangle<br>- Defines Shape superclass with draw method and concrete classes for each shape<br>- ShapeFactory class generates shape objects based on input strings<br>- Demonstrates pattern usage by creating a Rectangle object and calling its draw method.</td>
            </tr>
            </table>
        </blockquote>
    </details>
    <details> <!-- behavioral-design-pattern Submodule -->
        <summary><b>behavioral-design-pattern</b></summary>
        <blockquote>
            <table>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/behavioral-design-pattern/strategy-design-pattern.cpp'>strategy-design-pattern.cpp</a></b></td>
                <td>- Demonstrates the Strategy Design Pattern for dynamic driving behaviors in vehicles<br>- Encapsulates various driving strategies (e.g., Sport, Normal, Passenger) as separate classes<br>- The Vehicle class can change strategies dynamically, promoting flexibility and scalability without modifying the Vehicle class itself.</td>
            </tr>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/behavioral-design-pattern/template-design-pattern.cpp'>template-design-pattern.cpp</a></b></td>
                <td>- Implements a Template Method Design Pattern for payment processing<br>- Defines a base class with common steps and abstract methods for subclasses to implement specific payment types<br>- Demonstrates sending money to a friend and a merchant by overriding the template methods<br>- Executed through instances of PayToFriend and PayToMerch classes.</td>
            </tr>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/behavioral-design-pattern/observer-design-pattern.cpp'>observer-design-pattern.cpp</a></b></td>
                <td>- Implements observer design pattern for stock updates<br>- Defines observables for iPhone and Samsung stocks, with mobile and email alert observers<br>- Demonstrates notifications to observers based on stock count changes.</td>
            </tr>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/behavioral-design-pattern/chain-of-responsibility-design-pattern.cpp'>chain-of-responsibility-design-pattern.cpp</a></b></td>
                <td>- Implements a Chain of Responsibility design pattern for logging messages based on their severity levels<br>- The code defines different log processors for handling INFO, DEBUG, and ERROR messages in a chain<br>- By passing messages through the chain, it ensures that each message is processed by the appropriate log processor without the sender needing to know the specific handler.</td>
            </tr>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/behavioral-design-pattern/mediator-design-pattern.cpp'>mediator-design-pattern.cpp</a></b></td>
                <td>- Demonstrates the Mediator Design Pattern, fostering loose coupling between objects by centralizing communication through a mediator<br>- Objects interact indirectly via the mediator, enhancing system maintainability and flexibility<br>- The code showcases how bidders in an auction place bids and receive notifications through the mediator, streamlining communication and reducing dependencies.</td>
            </tr>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/behavioral-design-pattern/interpreter-design-pattern.cpp'>interpreter-design-pattern.cpp</a></b></td>
                <td>- Demonstrates the Interpreter Design Pattern by evaluating complex mathematical expressions using terminal and non-terminal expressions within a defined context<br>- The code creates a context to store variable values, constructs expressions for multiplication and addition, and outputs the result of the expression evaluation.</td>
            </tr>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/behavioral-design-pattern/command-design-pattern.cpp'>command-design-pattern.cpp</a></b></td>
                <td>- Implements the Command Design Pattern to decouple command execution from command producers<br>- Defines commands for an Air Conditioner, allowing operations like turning on/off and setting temperature<br>- Utilizes an invoker class to manage and execute commands, showcasing features like undo/redo functionality.</td>
            </tr>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/behavioral-design-pattern/visitor-design-pattern.cpp'>visitor-design-pattern.cpp</a></b></td>
                <td>- Implements Visitor Design Pattern to separate operations (pricing, maintenance) from room classes<br>- Defines visitors for different room types to perform specific operations without modifying room classes<br>- Main function demonstrates pricing and maintenance operations on single, double, and deluxe rooms using respective visitor instances.</td>
            </tr>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/behavioral-design-pattern/iterator-design-pattern.cpp'>iterator-design-pattern.cpp</a></b></td>
                <td>- Implements the Iterator Design Pattern to enable sequential access to a collection of books without exposing its structure<br>- The code defines classes for books, iterators, and libraries, showcasing how to iterate over and print book names in a library using an iterator.</td>
            </tr>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/behavioral-design-pattern/momento-design-pattern.cpp'>momento-design-pattern.cpp</a></b></td>
                <td>- Demonstrates the Memento Design Pattern by enabling objects to be restored to previous states without revealing implementation details<br>- The code showcases saving and restoring object states using Mementos managed by a CareTaker, facilitating undo/redo functionality within the project's architecture.</td>
            </tr>
            </table>
        </blockquote>
    </details>
    <details> <!-- structural-design-pattern Submodule -->
        <summary><b>structural-design-pattern</b></summary>
        <blockquote>
            <table>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/structural-design-pattern/flyweight-design-pattern.cpp'>flyweight-design-pattern.cpp</a></b></td>
                <td>- Demonstrates the Flyweight Design Pattern to optimize memory usage by sharing common data among similar objects<br>- The code defines interfaces for letters, concrete letter implementations, and a factory to manage object creation and reuse<br>- By creating and displaying letters using the factory, it showcases efficient memory utilization through object sharing.</td>
            </tr>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/structural-design-pattern/bridge-design-pattern.cpp'>bridge-design-pattern.cpp</a></b></td>
                <td>- Demonstrates the Bridge Design Pattern by decoupling abstractions from implementations, allowing independent variation<br>- Defines breathing processes for land and water entities, showcasing how Dogs and Fish can use different implementors<br>- This promotes extensibility and flexibility in managing diverse living things.</td>
            </tr>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/structural-design-pattern/flyweight-design-pattern-with-singleton-concept.cpp'>flyweight-design-pattern-with-singleton-concept.cpp</a></b></td>
                <td>- Demonstrates the Flyweight Design Pattern by efficiently managing memory usage through object sharing<br>- The code showcases the creation and reuse of letter objects using a Singleton Factory, emphasizing memory optimization for large quantities of similar objects.</td>
            </tr>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/structural-design-pattern/decorator-design-pattern.cpp'>decorator-design-pattern.cpp</a></b></td>
                <td>- Implements the Decorator Design Pattern for pizzas, allowing dynamic addition of toppings to base pizza objects<br>- Demonstrates how to enhance pizza objects with Mushroom and Cheese toppings while maintaining scalability and reusability in the codebase architecture.</td>
            </tr>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/structural-design-pattern/adapter-design-pattern.cpp'>adapter-design-pattern.cpp</a></b></td>
                <td>- Implements the Adapter Design Pattern to bridge incompatible interfaces, converting weight from pounds to kilograms<br>- The code creates classes for weighing machines in pounds and kilograms, demonstrating adaptation between the two units.</td>
            </tr>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/structural-design-pattern/proxy-design-pattern.cpp'>proxy-design-pattern.cpp</a></b></td>
                <td>- Implements a Proxy Design Pattern to control access to an Employee Database<br>- The code defines classes for Employee, EmployeeDB, EmployeeDBImpl, and EmployeeDBProxy<br>- The proxy restricts access based on client permissions, allowing creation and retrieval of employee records<br>- The main function demonstrates creating an employee record and retrieving it based on client roles.</td>
            </tr>
            <tr>
                <td><b><a href='https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/master/structural-design-pattern/composite-design-pattern.cpp'>composite-design-pattern.cpp</a></b></td>
                <td>- Demonstrates the Composite Design Pattern by creating a hierarchical structure of directories and files<br>- Allows uniform treatment of individual objects and compositions<br>- Enables representing part-whole hierarchies where files and directories are handled uniformly<br>- The code showcases how directories can contain files and subdirectories in a tree-like manner.</td>
            </tr>
            </table>
        </blockquote>
    </details>
</details>

---

## Getting Started

### Prerequisites

Before getting started with Low-Level-Design-Patterns, ensure your runtime environment meets the following requirements:

- **Programming Language:** CPP

### Installation

Install Low-Level-Design-Patterns using one of the following methods:

**Build from source:**

1. Clone the Low-Level-Design-Patterns repository:

```sh
❯ git clone https://github.com/samyakmehta28/Low-Level-Design-Patterns
```

2. Navigate to the project directory:

```sh
❯ cd Low-Level-Design-Patterns
```

---

## Contributing

- **💬 [Join the Discussions](https://github.com/samyakmehta28/Low-Level-Design-Patterns/discussions)**: Share your insights, provide feedback, or ask questions.
- **🐛 [Report Issues](https://github.com/samyakmehta28/Low-Level-Design-Patterns/issues)**: Submit bugs found or log feature requests for the `Low-Level-Design-Patterns` project.
- **💡 [Submit Pull Requests](https://github.com/samyakmehta28/Low-Level-Design-Patterns/blob/main/CONTRIBUTING.md)**: Review open PRs, and submit your own PRs.

<details closed>
<summary>Contributing Guidelines</summary>

1. **Fork the Repository**: Start by forking the project repository to your github account.
2. **Clone Locally**: Clone the forked repository to your local machine using a git client.
   ```sh
   git clone https://github.com/samyakmehta28/Low-Level-Design-Patterns
   ```
3. **Create a New Branch**: Always work on a new branch, giving it a descriptive name.
   ```sh
   git checkout -b new-feature-x
   ```
4. **Make Your Changes**: Develop and test your changes locally.
5. **Commit Your Changes**: Commit with a clear message describing your updates.
   ```sh
   git commit -m 'Implemented new feature x.'
   ```
6. **Push to github**: Push the changes to your forked repository.
   ```sh
   git push origin new-feature-x
   ```
7. **Submit a Pull Request**: Create a PR against the original project repository. Clearly describe the changes and their motivations.
8. **Review**: Once your PR is reviewed and approved, it will be merged into the main branch. Congratulations on your contribution!
</details>

<details closed>
<summary>Contributor Graph</summary>
<br>
<p align="left">
   <a href="https://github.com{/samyakmehta28/Low-Level-Design-Patterns/}graphs/contributors">
      <img src="https://contrib.rocks/image?repo=samyakmehta28/Low-Level-Design-Patterns">
   </a>
</p>
</details>

---

## License

This project is protected under the [SELECT-A-LICENSE](https://choosealicense.com/licenses) License. For more details, refer to the [LICENSE](https://choosealicense.com/licenses/) file.

---

## Acknowledgments

- I would like to express my sincere gratitude to Shreyansh Jain for his invaluable contributions through his YouTube playlist on Low-Level System Design. This collection of C++ implementations of various design patterns was primarily inspired by the examples presented in his videos. While I have closely followed the examples provided in his content, I have adapted and implemented them in C++.

- You can find Shreyansh Jain's YouTube playlist here: [Low-Level System Design Playlist](https://www.youtube.com/playlist?list=PL6W8uoQQ2c61X_9e6Net0WdYZidm7zooW).

---
