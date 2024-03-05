task 1: In the driver file (main.cpp), perform the following sub-tasks.
1. Create two objects of this class, one with no constructor argument and one with the argument 5.
2. Take five input values from the user and store them in the array inside the second object using the set method.
3. For the second object, print all the values you just stored.
Note that, you cannot assign anything in the first object since the array inside it has size 0. Neither can you change 
the size of this array to some other size.
// dynarr.h
#ifndef DYNARR_H_INCLUDED
#define DYNARR_H_INCLUDED

// Class declaration for dynamic array
class dynArr {
private:
    int *data;  // Pointer to dynamically allocated array
    int size;   // Size of the array

public:
    // Constructors and Destructor
    dynArr();         // Default constructor
    dynArr(int s);    // Parameterized constructor
    ~dynArr();        // Destructor

    // Member functions
    void setValue(int index, int value);  // Set value at a specific index
    int getValue(int index);              // Get value at a specific index
};

#endif // DYNARR_H_INCLUDED

// dynarr.cpp
#include "dynarr.h"
#include <iostream>

using namespace std;

// Default constructor
dynArr::dynArr() {
    data = nullptr;  // Initialize pointer to null
    size = 0;        // Initialize size to zero
}

// Parameterized constructor
dynArr::dynArr(int s) {
    data = new int[s];  // Dynamically allocate memory for the array
    size = s;           // Set the size of the array
}

// Destructor
dynArr::~dynArr() {
    delete[] data;  // Deallocate the dynamically allocated memory
}

// Get value at a specific index
int dynArr::getValue(int index) {
    return data[index];
}

// Set value at a specific index
void dynArr::setValue(int index, int value) {
    data[index] = value;
}

// main.cpp
#include <iostream>
#include "dynarr.h"

using namespace std;

int main() {
    // Task 1: Create Objects
    dynArr obj1;          // Object with no constructor argument
    dynArr obj2(5);       // Object with the argument 5

    // Task 1: Take User Input
    int input;
    for (int i = 0; i < 5; ++i) {
        cout << "Enter value " << (i + 1) << ": ";
        cin >> input;
        obj2.setValue(i, input);
    }

    // Task 1: Print Stored Values
    cout << "Values stored in the second object: ";
    for (int i = 0; i < obj2.getValue(i); ++i) {
        cout << obj2.getValue(i) << " ";
    }
    cout << endl;

    return 0;
}
task 2: Modify the header and the source files. Add a member function void allocate(int s) which allows
you to change the size of the array. Make sure that memory is not leaked
// dynarr.h
#ifndef DYNARR_H_INCLUDED
#define DYNARR_H_INCLUDED

class dynArr {
private:
    int *data;
    int size;

public:
    dynArr();
    dynArr(int);
    ~dynArr();
    void setValue(int, int);
    int getValue(int);
    void allocate(int);  // New member function to change the size of the array
};

#endif // DYNARR_H_INCLUDED
// dynarr.cpp
#include "dynarr.h"
#include <iostream>

using namespace std;

dynArr::dynArr() {
    //data = nullptr;
    size = 0;
}

dynArr::dynArr(int s) : size(s) {
    data = new int[size];
}

dynArr::~dynArr() {
    delete[] data;
}

void dynArr::setValue(int index, int value) {
    if (index >= 0 && index < size) {
        data[index] = value;
    }
}

int dynArr::getValue(int index) {
    if (index >= 0 && index < size) {
        return data[index];
    }
    return -1; // or handle the out-of-bounds case accordingly
}

void dynArr::allocate(int s) {
    // Deallocate existing memory
    delete[] data;

    // Allocate new memory with the specified size
    size = s;
    data = new int[size];
}

#include <iostream>
#include "dynarr.h"

using namespace std;

int main() {
    // Task 1: Create Objects
    dynArr obj1;          // Object with no constructor argument
    dynArr obj2(5);       // Object with the argument 5

    // Task 1: Take User Input
    int input;
    for (int i = 0; i < 5; ++i) {
        cout << "Enter value " << (i + 1) << ": ";
        cin >> input;
        obj2.setValue(i, input);
    }

    // Task 1: Print Stored Values
    cout << "Values stored in the second object: ";
    for (int i = 0; i < obj2.getValue(i); ++i) {
        cout << obj2.getValue(i) << " ";
    }
    cout << endl;

    // Task 2: Change the Size of the Array
    int newSize;
    cout << "Enter the new size of the array: ";
    cin >> newSize;
    obj2.allocate(newSize);

    // Task 2: Print Stored Values after Resizing
    cout << "Values stored in the second object after resizing: ";
    for (int i = 0; i < obj2.getValue(i); ++i) {
        cout << obj2.getValue(i) << " ";
    }
    cout << endl;

    return 0;
}
task 3 - Modify the header file and the source files again, so that it works for two dimensional array where all the 
rows are the same size. The user will specify the number of rows and columns as well as the content of the array, 
which you will take as input from user in the main function
// dynarr.h
#ifndef DYNARR_H_INCLUDED
#define DYNARR_H_INCLUDED

class dynArr {
private:
    int **data;  // Pointer to a pointer for a two-dimensional array
    int rows;
    int cols;

public:
    dynArr();
    dynArr(int r, int c);
    ~dynArr();
    void setValue(int row, int col, int value);
    int getValue(int row, int col);
    void allocate(int r, int c);
};

#endif // DYNARR_H_INCLUDED
// dynarr.cpp
#include "dynarr.h"
#include <iostream>

using namespace std;

dynArr::dynArr() : data(nullptr),rows(0), cols(0) {}

dynArr::dynArr(int r, int c) : rows(r), cols(c) {
    data = new int*[rows];  // Allocate an array of row pointers

    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];  // Allocate each row separately
    }
}

dynArr::~dynArr() {
    // Deallocate memory for each row
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }

    // Deallocate memory for the array of row pointers
    delete[] data;
}

void dynArr::setValue(int row, int col, int value) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        data[row][col] = value;
    }
}

int dynArr::getValue(int row, int col) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        return data[row][col];
    }
    return -1; // or handle the out-of-bounds case accordingly
}

void dynArr::allocate(int r, int c) {
    // Deallocate existing memory
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;

    // Allocate new memory for the specified number of rows and columns
    rows = r;
    cols = c;

    data = new int*[rows];  // Allocate an array of row pointers

    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];  // Allocate each row separately
    }
}
// main.cpp
#include <iostream>
#include "dynarr.h"

using namespace std;

int main() {
    // Task 1: Create Object
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    dynArr obj(rows, cols);

    // Task 2: Take User Input
    int input;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter value at row " << (i + 1) << ", column " << (j + 1) << ": ";
            cin >> input;
            obj.setValue(i, j, input);
        }
    }

    // Task 3: Print Stored Values
    cout << "Values stored in the object: \n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << obj.getValue(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}

