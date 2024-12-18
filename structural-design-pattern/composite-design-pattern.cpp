// The Composite Design Pattern is a structural design pattern that allows you to compose objects 
// into tree-like structures to represent part-whole hierarchies. It lets clients treat individual 
// objects and compositions of objects uniformly. This is particularly useful when you want to 
// represent a hierarchy of objects where individual objects and their containers are treated the same way.

#include <bits/stdc++.h>
using namespace std;

// Abstract Base Class: Represents the common interface for both individual objects (Files) 
// and composite objects (Directories).
class FileSystem {
    public:
    /**
     * @brief Lists the contents of the file system.
     */
    virtual void ls() = 0;

    /**
     * @brief Adds a file system component to the current object.
     * 
     * For files, this operation is not supported.
     * For directories, this operation allows adding files or subdirectories.
     */
    virtual void add(FileSystem* fs) = 0;

    // Virtual destructor to ensure proper cleanup of derived objects.
    virtual ~FileSystem() {}
};

// Leaf Class: Represents individual objects (Files) in the hierarchy.
class File : public FileSystem {
    private:
    string name; // Name of the file.

    public:
    /**
     * @brief Constructor for File.
     * 
     * @param nm Name of the file.
     */
    File(string nm) : name(nm) {}

    /**
     * @brief Lists the file name.
     */
    void ls() {
        cout << "File: " << name << endl;
    }

    /**
     * @brief Throws an exception as adding components to a file is not allowed.
     * 
     * @param fs Pointer to a file system component.
     */
    void add(FileSystem* fs) {
        throw runtime_error("Cannot add to a file");
    }
};

// Composite Class: Represents composite objects (Directories) that can contain Files or other Directories.
class Directory : public FileSystem {
    private:
    string name;                       // Name of the directory.
    vector<FileSystem*> content;       // Vector to store child components (Files and Directories).

    public:
    /**
     * @brief Constructor for Directory.
     * 
     * @param nm Name of the directory.
     */
    Directory(string nm) : name(nm) {}

    /**
     * @brief Adds a file system component (File or Directory) to the directory.
     * 
     * @param fileSystem Pointer to a file system component.
     */
    void add(FileSystem* fileSystem) {
        content.push_back(fileSystem);
    }

    /**
     * @brief Lists the directory name and its contents.
     */
    void ls() {
        cout << "Directory: " << name << endl;
        for (auto fileSystem : content) {
            fileSystem->ls();
        }
    }

    /**
     * @brief Destructor to clean up dynamically allocated child components.
     */
    ~Directory() {
        for (auto fileSystem : content) {
            delete fileSystem;
        }
    }
};

// Main function demonstrating the Composite Design Pattern.
// It shows how a directory can contain files and subdirectories in a tree-like structure.
int main() {
    // Create a root directory.
    FileSystem* root = new Directory("root");

    // Create a file and add it to the root directory.
    FileSystem* mainFile = new File("main.ts");
    root->add(mainFile);

    // Create a subdirectory named "src".
    FileSystem* src = new Directory("src");

    // Create a file and add it to the "src" directory.
    FileSystem* appFile = new File("app.ts");
    src->add(appFile);

    // Add the "src" directory to the root directory.
    root->add(src);

    // List the contents of the root directory.
    root->ls();

    // Clean up dynamically allocated objects.
    delete root;

    return 0;
}



