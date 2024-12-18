#include <bits/stdc++.h>
using namespace std;

// The Builder design pattern is a creational design pattern that allows for the step-by-step construction of complex objects. 
// It separates the construction of a complex object from its representation, allowing the same construction process to create different representations. 
// This pattern is especially useful when an object needs to be created with many optional parts or configurations.

// The Builder design pattern helps in creating complex objects by encapsulating the construction process, making it easy to manage and extend.

// The Decorator design pattern is a structural design pattern that allows for the dynamic addition of behavior to an object at runtime, 
// which is useful for adding new functionalities without altering the object itself. 

// Class declarations for the Student and StudentBuilder
class Student;  // Forward declaration of Student class to be used by the builder

// Abstract Builder class for constructing a Student object step by step.
class StudentBuilder{
    public:
    int rollNumber;      // Holds the roll number of the student
    int age;             // Holds the age of the student
    string name;         // Holds the name of the student
    vector<string>subjects; // Holds the list of subjects the student is enrolled in
    
    public:
    // Set the roll number for the student.
    // Returns a pointer to the current StudentBuilder instance to allow method chaining.
    StudentBuilder* setRollNumber(int rn){
        this->rollNumber = rn;
        return this; // Returns the current instance for method chaining.
    }
    
    // Set the age for the student.
    // Returns a pointer to the current StudentBuilder instance to allow method chaining.
    StudentBuilder* setAge(int ag){
        this->age = ag;
        return this; // Returns the current instance for method chaining.
    }
    
    // Set the name for the student.
    // Returns a pointer to the current StudentBuilder instance to allow method chaining.
    StudentBuilder* setName(string nm){
        this->name = nm;
        return this; // Returns the current instance for method chaining.
    }
    
    // Abstract method that will be implemented by concrete builder classes to set the student's subjects.
    virtual StudentBuilder* setSubjects() = 0;
    
    // Method to construct the final Student object using the values set so far.
    // Returns a pointer to a newly constructed Student object.
    Student *buildStudent();
};

// Class representing the Student object.
class Student{
    private:
    int rollNumber;      // Student's roll number
    int age;             // Student's age
    string name;         // Student's name
    vector<string>subjects; // Subjects that the student is enrolled in
    
    public:
    // Constructor that initializes the Student object using the values set in the StudentBuilder.
    Student(StudentBuilder *studentBuilder){
        this->rollNumber = studentBuilder->rollNumber;
        this->age = studentBuilder->age;
        this->name = studentBuilder->name;
        this->subjects = studentBuilder->subjects;
    }
    
    // Method to print the details of the student.
    void printStudentDetails(){
        cout<<"---------------------------------"<<endl;
        cout<<"RollNumber = "<<rollNumber<<endl;
        cout<<"Age = "<<age<<endl;
        cout<<"Name is "<<name<<endl;
        cout<<"Subjects taken are: "<<endl;
        
        // Loop through the list of subjects and print each subject.
        for(auto sub : subjects){
            cout << sub << endl;
        }
        cout<<"---------------------------------"<<endl;
    }
};

// Implementation of the buildStudent method in the abstract StudentBuilder class.
// This method returns a new Student object constructed using the values set in the builder.
Student *StudentBuilder::buildStudent(){
    return new Student(this); // Creates and returns a new Student object.
}

// Concrete builder for Engineering students, sets specific subjects for Engineering students.
class EngineeringStudentBuilder : public StudentBuilder{
    public:
    // Implementation of setSubjects method for Engineering students.
    // Adds subjects that are typically taken by engineering students.
    StudentBuilder* setSubjects(){
        this->subjects.push_back("DSA");           // Data Structures and Algorithms
        this->subjects.push_back("Computer Networks"); // Computer Networks
        return this; // Returns the current instance for method chaining.
    }
};

// Concrete builder for MBA students, sets specific subjects for MBA students.
class MBAStudentBuilder : public StudentBuilder{
    public:
    // Implementation of setSubjects method for MBA students.
    // Adds subjects that are typically taken by MBA students.
    StudentBuilder* setSubjects(){
        this->subjects.push_back("Finance"); // Finance
        this->subjects.push_back("Banking"); // Banking
        return this; // Returns the current instance for method chaining.
    }
};

// Main function to demonstrate the Builder design pattern.
int main() {
    // Creating an EngineeringStudentBuilder object for an Engineering student.
    StudentBuilder *studentBuilder1 = new EngineeringStudentBuilder();
    
    // Setting the details for the first student (Engineering student) using method chaining.
    // Then building the final student object and printing the student details.
    Student *student = studentBuilder1->setRollNumber(94)
                                      ->setAge(22)
                                      ->setName("Samyak")
                                      ->setSubjects() // Setting subjects specific to Engineering students.
                                      ->buildStudent();
    student->printStudentDetails(); // Printing the details of the Engineering student.
    
    // Creating an MBAStudentBuilder object for an MBA student.
    StudentBuilder *studentBuilder2 = new MBAStudentBuilder();
    
    // Setting the details for the second student (MBA student) using method chaining.
    // Then building the final student object and printing the student details.
    student = studentBuilder2->setRollNumber(95)
                             ->setAge(22)
                             ->setName("Shreya")
                             ->setSubjects() // Setting subjects specific to MBA students.
                             ->buildStudent();
    student->printStudentDetails(); // Printing the details of the MBA student.
}
