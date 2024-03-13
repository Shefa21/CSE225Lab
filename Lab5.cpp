//Task 1: Recall the class we used in the previous lab to allocate memory dynamically. Modify the header file 
//and the source file given below so that they now work as template class (the array elements in the 
//dynamically allocated memory can be any type as the user defines).
#ifndef DYNARR_H_INCLUDED
#define DYNARR_H_INCLUDED
template <class anything>
//template <class or typename T>
//class or typename declares a type parameter 
class dynArr
{
private:
    anything *data;
    int size;
public:
    dynArr(int);
    ~dynArr();
    void setValue(int, anything);
    anything getValue(int);

};
#endif // DYNARR_H_INCLUDED
//Here, a template class dynArr is defined. It has private data members data (a pointer to anything) and size (an integer). The class also declares a constructor, destructor, and member functions to set and get values.




#include "dynarr.h"
#include <iostream>
using namespace std;
template <class anything>
dynArr<anything>::dynArr(int s)
{
    data = new anything[s];
    size = s;
}
//This is the constructor definition for the dynArr class. It dynamically allocates an array of type anything with size s and sets the size accordingly.
template <class anything>
dynArr<anything>::~dynArr()//The destructor definition. It deallocates the dynamically allocated memory when the object goes out of scope. i.e when its block or function in which it is declared ends
{
    delete [] data;
}
template <class anything>
anything dynArr<anything>::getValue(int index)//Definition of the member function getValue, which retrieves the value at the specified index in the array.
{
    return data[index];
}
template <class anything>
void dynArr<anything>::setValue(int index, anything value)//Definition of the member function setValue, which sets the value at the specified index in the array.
{
    data[index] = value;
}




#include <iostream>
#include "dynarr.h"
#include "dynarr.cpp"
using namespace std;
int main()
{

    dynArr<int> da1(5);//an instance da1 of the template class dynArr is created with the template parameter int with size 5
    cout<<"enter index and value"<<endl;
    int i, v;
    cin>>i;
    cin>> v;
    da1.setValue(i,v);
    cout<<da1.getValue(0)<<endl;//this will print garbage value since we have not yet set value at index 0
    dynArr<double> da2(5);//an instance da1 of the template class dynArr is created with the template parameter double with size 5
    da2.setValue(0,4.67);
    cout<<da2.getValue(0)<<endl;//4.67
    cout<<da1.getValue(i)<<endl;//value entered by user at the index i but if index is chosen more than 5 garbage value will be printed
    return 0;
}
//complex number
//complex.h
#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
class Complex
{
public:
    Complex();
    Complex(double, double);
    Complex operator+(Complex);
    void Print();
private:
    double Real, Imaginary;
};
#endif // COMPLEX_H_INCLUDED


//complex.cpp
#include "complex.h"
#include <iostream>
using namespace std;
Complex::Complex()
{
    Real = 0;
    Imaginary = 0;
}
Complex::Complex(double r, double i)
{
    Real = r;
    Imaginary = i;
}
Complex Complex::operator+(Complex a)
{
    Complex t;
    t.Real = Real + a.Real;
    t.Imaginary = Imaginary + a.Imaginary;
    return t;
}
void Complex::Print()
{
    cout << Real << endl;
    cout << Imaginary << endl;
}
// main.cpp

#include "complex.h"
#include <iostream>

int main() {
    // Code using Complex class
    Complex complex1(3.0, 4.0);
    Complex complex2(1.5, 2.5);
    Complex result = complex1 + complex2;
    result.Print();

    return 0;
}






//Task 2: Recall the complex number class we discussed in our lectures. Modify the class and overload the *
//(multiplication) and the != (not equal) operators for the class given below
// complex.h

#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

class Complex {
public:
    Complex();
    Complex(double, double);
    Complex operator+(const Complex&) const;  // Overloaded +
    Complex operator*(const Complex&) const;  // Overloaded *
    bool operator!=(const Complex&) const;    // Overloaded !=
    void Print() const;

private:
    double Real, Imaginary;
};

#endif // COMPLEX_H_INCLUDED


// complex.cpp

#include "complex.h"
#include <iostream>

Complex::Complex() {
    Real = 0;
    Imaginary = 0;
}

Complex::Complex(double r, double i) {
    Real = r;
    Imaginary = i;
}

Complex Complex::operator+(const Complex& a) const {
    Complex t;
    t.Real = Real + a.Real;
    t.Imaginary = Imaginary + a.Imaginary;
    return t;
}

Complex Complex::operator*(const Complex& a) const {
    Complex t;
    t.Real = (Real * a.Real) - (Imaginary * a.Imaginary);
    t.Imaginary = (Real * a.Imaginary) + (Imaginary * a.Real);
    return t;
}

bool Complex::operator!=(const Complex& a) const {
    return (Real != a.Real) || (Imaginary != a.Imaginary);
}

void Complex::Print() const {
    std::cout << "Real: " << Real << std::endl;
    std::cout << "Imaginary: " << Imaginary << std::endl;
}


// main.cpp

#include "complex.h"
#include <iostream>

int main() {
    // Create two Complex objects
    Complex complex1(3.0, 4.0);
    Complex complex2(1.5, 2.5);

    // Use the overloaded + operator to add the two complex numbers
    Complex resultAddition = complex1 + complex2;

    // Use the overloaded * operator to multiply the two complex numbers
    Complex resultMultiplication = complex1 * complex2;

    // Print the results
    std::cout << "Result of addition:" << std::endl;
    resultAddition.Print();

    std::cout << "\nResult of multiplication:" << std::endl;
    resultMultiplication.Print();

    // Use the overloaded != operator to check inequality
    if (complex1 != complex2) {
        std::cout << "\nComplex numbers are not equal." << std::endl;
    } else {
        std::cout << "\nComplex numbers are equal." << std::endl;
    }

    return 0;
}

