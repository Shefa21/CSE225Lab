//Task 1: Recall the class we used in the previous lab to allocate memory dynamically. Modify the header file 
//and the source file given below so that they now work as template class (the array elements in the 
//dynamically allocated memory can be any type as the user defines).
#ifndef DYNARR_H_INCLUDED
#define DYNARR_H_INCLUDED
template <class anything>
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







//Task 2: Recall the complex number class we discussed in our lectures. Modify the class and overload the *
(multiplication) and the != (not equal) operators for the class given below
