//unsorted and sorted list array implementation
#ifndef UNSORTEDTYPE_H_INCLUDED
#define UNSORTEDTYPE_H_INCLUDED

const int MAX_ITEMS = 5;

template<class ItemType>
class UnsortedType {
    public :
        UnsortedType();
        void MakeEmpty();
        bool IsFull();
        int LengthIs();
        void InsertItem(ItemType);
        void DeleteItem(ItemType);
        void RetrieveItem(ItemType &, bool &);
        void ResetList();
        void GetNextItem(ItemType &);

    private:
        int length;
        ItemType info[MAX_ITEMS];
        int currentPos;
};

#endif // UNSORTEDTYPE_H_INCLUDED


#include "unsortedtype.h"

template<class ItemType>
UnsortedType<ItemType>::UnsortedType() {
    length = 0;
    currentPos = -1;
}

template<class ItemType>
void UnsortedType<ItemType>::MakeEmpty() {
    length = 0;
}

template<class ItemType>
bool UnsortedType<ItemType>::IsFull() {
    return (length == MAX_ITEMS);
}

template<class ItemType>
int UnsortedType<ItemType>::LengthIs() {
    return length;
}

template<class ItemType>
void UnsortedType<ItemType>::ResetList() {
    currentPos = -1;
}

template<class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType &item) {
    currentPos++;
    item = info[currentPos];
}

template<class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType &item, bool &found) {
    int location = 0;
    bool moreToSearch = (location < length);
    found = false;
    while (moreToSearch && !found) {
        if (item == info[location]) {
            found = true;
            item = info[location];
        } else {
            location++;
            moreToSearch = (location < length);
        }
    }
}

template<class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item) {
    info[length] = item;
    length++;
}

template<class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item) {
    int location = 0;
    while (item != info[location])
        location++;
    info[location] = info[length - 1];
    length--;
}
#ifndef STUDENTINFO_H_INCLUDED
#define STUDENTINFO_H_INCLUDED
using namespace std;

class studentInfo {

    private:
        int id;
        string name;
        double cgpa;

    public:
        studentInfo();
        studentInfo(int);
        studentInfo(int, string, double);
        bool operator==(studentInfo s);
        bool operator!=(studentInfo s);
        friend ostream &operator<<(ostream &, studentInfo &);

};

#endif // STUDENTINFO_H_INCLUDED

#include "studentInfo.h"

studentInfo::studentInfo(int id, string name, double cgpa) {
    this->id = id;
    this->name = name;
    this->cgpa = cgpa;
}

studentInfo::studentInfo() {

}

studentInfo::studentInfo(int id) {
    this->id = id;
}

bool studentInfo::operator==(studentInfo s) {
    if (this->id == s.id)
        return true;
    else
        return false;
}

bool studentInfo::operator!=(studentInfo s) {
    if (this->id != s.id)
        return true;
    else
        return false;
}

ostream &operator<<(ostream &os, studentInfo &student) {
    os << student.id << ", " << student.name << ", " << student.cgpa << endl;
    return os;
}

/*
 Task:
 Generate the driver file (main.cpp) where you perform the following tasks. Note that you cannot make any change to
 the header file or the source file.

 Operations to be performed:
    • Create a list of integers.
    • Insert four items.
    • Print the list.
    • Print the length of the list.
    • Insert one item.
    • Print the list.
    • Retrieve 4 and print whether found or not.
    • Retrieve 5 and print whether found or not.
    • Retrieve 9 and print whether found or not.
    • Retrieve 10 and print whether found or not.
    • Print if the list is full or not.
    • Delete 5.
    • Print if the list is full or not.
    • Delete 1.
    • Print the list.
    • Delete 6.
    • Print the list.

    • Write a class "studentInfo" that represents a student record. It must have variables to store the student ID,
    student’s name and student’s CGPA. It also must have a function to print all the values. You will also need to
    overload a few operators.
        • Create a list of objects of class "studentInfo".
        • Insert 5 student record.
        • Delete the record with ID15467.
        • Retrieve the record with ID 13569 and print whether found or not along with the entire record.
        • Print the list.

 Note:
 Helper functions are created to avoid code duplication. You can use them, or you can write your own.
*/

#include <iostream>
#include "unsortedtype.cpp"
#include "studentInfo.cpp"

using namespace std;

template<class T>
void Print(UnsortedType<T> u) {                  // Helper function to Print the list

    int length = u.LengthIs();
    T value;

    for (int i = 0; i < length; i++) {
        u.GetNextItem(value);
        cout << value << " ";
    }
    cout << endl;
}

template<class T>
void Retrieve(UnsortedType<T> u, T value) {      // Helper function to Retrieve an item
    bool b;
    u.RetrieveItem(value, b);

    if (b)
        cout << "Item is found" << endl;
    else
        cout << "Item is not found" << endl;

}

void checkFull(bool b) {                         // Helper function to check if the list is full
    if (b)
        cout << "List is full" << endl;
    else
        cout << "List is not full" << endl;
}

int main() {

    // First Task
    UnsortedType<int> ut;                        // Creating an object of UnsortedType class and inserting 5, 7, 6 ,9

    ut.InsertItem(5);
    ut.InsertItem(7);
    ut.InsertItem(6);
    ut.InsertItem(9);

    Print(ut);                                   // Print the list

    cout << ut.LengthIs() << endl;               // Print the length of the list
    ut.InsertItem(1);                            // Insert one item in the list
    Print(ut);                                   // Print the list

    Retrieve(ut, 4);                             // Retrieving 4, 5, 9, 10 in the list and print whether the item is
    // found or not
    Retrieve(ut, 5);
    Retrieve(ut, 9);
    Retrieve(ut, 10);

    checkFull(ut.IsFull());                      // Print whether the list is full or not

    ut.DeleteItem(5);                            // Delete 5 from the list

    checkFull(ut.IsFull());                      // Print whether the list is full or not

    ut.DeleteItem(1);                            // Delete 1 from the list

    Print(ut);                                   // Print the list

    ut.DeleteItem(6);                            // Delete 6 from the list

    Print(ut);                                   // Print the list


    // Second Task
    studentInfo s1(15234, "Jon", 2.6),           // Creating objects of studentInfo class with the given information
    s2(13732, "Tyrion", 3.9),
            s3(13569, "Sandor", 1.2),
            s4(15467, "Ramsey2", 3.1),
            s5(16285, "Arya", 3.1);

    UnsortedType<studentInfo> students;          // Creating an object of UnsortedType class and inserting the
    // objects
    students.InsertItem(s1);
    students.InsertItem(s2);
    students.InsertItem(s3);
    students.InsertItem(s4);
    students.InsertItem(s5);

    studentInfo temp = 15467;                    // Creating a temporary object to search for 15467
    students.DeleteItem(temp);                   // Deleting the item from the list

    temp = 13569;                                // Creating a temporary object to search for 13569

    Retrieve(students, temp);                    // Retrieving the item from the list
    cout << temp << endl;                        // Printing the item

    // Printing the list
    for (int i = 0; i < students.LengthIs(); i++) {
        students.GetNextItem(temp);
        cout << temp;
    }

    return 0;
}

//sorted list array implementation
//sortedtype.h
#ifndef SORTEDTYPE_H_INCLUDED
#define SORTEDTYPE_H_INCLUDED
const int MAX_ITEMS = 5;
template <class ItemType>
class SortedType
{
public :
    SortedType();
    void MakeEmpty();
    bool IsFull();
    int LengthIs();
    void InsertItem(ItemType);
    void DeleteItem(ItemType);
    void RetrieveItem(ItemType&,
                      bool&);
    void ResetList();
    void GetNextItem(ItemType&);
private:
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
};
#endif // SORTEDTYPE_H_INCLUDED
sortedtype.cpp
#include "sortedtype.h"
template <class ItemType>
SortedType<ItemType>::SortedType()
{
    length = 0;
    currentPos = - 1;
}
template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
{
    length = 0;
}
template <class ItemType>
bool SortedType<ItemType>::IsFull()
{
    return (length == MAX_ITEMS);
}
template <class ItemType>
int SortedType<ItemType>::LengthIs()
{
    return length;
}
template <class ItemType>
void SortedType<ItemType>::ResetList()
{
    currentPos = - 1;
}
template <class ItemType>
void
SortedType<ItemType>::GetNextItem(ItemType&
                                  item)
{
    currentPos++;
    item = info [currentPos];
}
template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType
                                      item)
{
    int location = 0;
    bool moreToSearch = (location < length);
    while (moreToSearch)
    {
        if(item > info[location])
        {
            location++;
            moreToSearch = (location < length);
        }
        else if(item < info[location])
            moreToSearch = false;
    }
    for (int index = length; index > location;
            index--)
        info[index] = info[index - 1];
    info[location] = item;
    length++;
}
template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType
                                      item)
{
    int location = 0;
    while (item != info[location])
        location++;
    for (int index = location + 1; index < length;
            index++)
        info[index - 1] = info[index];
    length--;
}
template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType&
                                        item, bool& found)
{
    int midPoint, first = 0, last = length - 1;
    bool moreToSearch = (first <= last);
    found = false;
    while (moreToSearch && !found)
    {
        midPoint = (first + last) / 2;
        if(item < info[midPoint])
        {
            last = midPoint - 1;
            moreToSearch = (first <= last);
        }
        else if(item > info[midPoint])
        {
            first = midPoint + 1;
            moreToSearch = (first <= last);
        }
        else
        {
            found = true;
            item = info[midPoint];
        }
    }
}
#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED
using namespace std;

class timeStamp
{

public:
    timeStamp();
    timeStamp(int, int, int);
    bool operator == (timeStamp);
    bool operator != (timeStamp);
    bool operator > (timeStamp);
    bool operator < (timeStamp);
    friend ostream &operator << (ostream &, timeStamp &);
    friend istream &operator >> (istream &, timeStamp &);

private:
    int s, m, h;
};

#endif // TIMESTAMP_H_INCLUDED
#include "timeStamp.h"

timeStamp::timeStamp()
{
    this->s = 0;
    this->m = 0;
    this->h = 0;
}

timeStamp::timeStamp(int s, int m, int h)
{
    this->s = s;
    this->m = m;
    this->h = h;
}

bool timeStamp::operator == (timeStamp t)
{
    if ((s == t.s) && (m == t.m) && (h == t.h))
        return true;
    else
        return false;
}

bool timeStamp::operator != (timeStamp t)
{
    if ((s != t.s) && (m != t.m) && (h != t.h))
        return true;
    else
        return false;
}

bool timeStamp::operator < (timeStamp t)
{
    if ((h < t.h) || ((h == t.h) && (m < t.m)) || ((h == t.h) && (m == t.m) && (s < t.s)))
        return true;
    else
        return false;
}

bool timeStamp::operator > (timeStamp t)
{
    if ((h > t.h) || ((h == t.h) && (m > t.m)) || ((h == t.h) && (m == t.m) && (s > t.s)))
        return true;
    else
        return false;
}

ostream &operator << (ostream &os, timeStamp &t)
{
    os << t.s << ":" << t.m << ":" << t.h;
    return os;
}

istream  &operator >> (istream &is, timeStamp &t)
{
    is >> t.s >> t.m >> t.h;
    return is;
}

/*
 Task:
 Generate the driver file (main.cpp) where you perform the following tasks. Note that you cannot make any change to the
 header file or the source file.

 Operations to be performed:
    • Create a list of integers.
    • Print length of the list.
    • Insert five items.
    • Print the list.
    • Retrieve 6 and print whether found or not.
    • Retrieve 5 and print whether found or not.
    • Print if the list is full or not.
    • Delete 1.
    • Print the list.
    • Print if the list is full or not.

    •  Write a class "timeStamp" that represents a time of the day. It must have variables to store the number of seconds,
     minutes and hours passed. It also must have a function to print all the values. You will also need to overload a few
     operators.
        • Create a list of objects of class "timeStamp".
        • Insert 5 time values in the format ssmmhh.
        • Delete the timestamp "25  36  17".
        • Print the list.


 Note:
 Helper functions are created to avoid code duplication. You can use them, or you can write your own.
*/

#include <iostream>
#include "sortedtype.cpp"
#include "timeStamp.cpp"
using namespace std;

template <class T>
void Print(SortedType<T> u)                      // Helper function to Print the list
{

    int length = u.LengthIs();
    T value;

    for(int i=0; i<length; i++)
    {
        u.GetNextItem(value);
        cout << value << " ";
    }
    cout << endl;
}
template <class T>
void Retrieve(SortedType<T> u, T value)          // Helper function to Retrieve an item
{
    bool b;
    u.RetrieveItem(value,b);

    if(b)
        cout << "Item is found" << endl;
    else
        cout << "Item is not found" << endl;

}
void checkFull(bool b)                           // Helper function to check if the list is full
{
    if(b)
        cout << "List is full" << endl;
    else
        cout << "List is not full" << endl;
}

int main()
{

    // First Task
    SortedType<int> st;                          // Creating an object of SortedType class

    cout << st.LengthIs() << endl;               // Print length of the list

    st.InsertItem(5);                            // Insert five items 5, 7, 4 ,2, 1
    st.InsertItem(7);
    st.InsertItem(4);
    st.InsertItem(2);
    st.InsertItem(1);

    Print(st);                                   // Print the list

    Retrieve(st,6);                              // Retrieve 6 and print whether found or not
    Retrieve(st,5);                              // Retrieve 5 and print whether found or not

    checkFull(st.IsFull());                      // Print if the list is full or not

    st.DeleteItem(1);                            // Delete 1

    Print(st);                                   // Print the list

    checkFull(st.IsFull());                      // Print if the list is full or not


    // Second Task
    timeStamp t1(15, 34, 23);                    // Creating objects of timeStamp class with the given information
    timeStamp t2(13, 13, 02);
    timeStamp t3(43, 45, 12);
    timeStamp t4(25, 36, 17);
    timeStamp t5(52, 02, 20);

    SortedType<timeStamp> timeStampList;         // Creating an object of SortedType class
    timeStampList.InsertItem(t1);                // Inserting the objects in the list
    timeStampList.InsertItem(t2);
    timeStampList.InsertItem(t3);
    timeStampList.InsertItem(t4);
    timeStampList.InsertItem(t5);

    timeStamp temp(25, 36, 17);                  // Creating a temporary object to search for the given time
    timeStampList.DeleteItem(temp);              // Deleting the item from the list

    // Printing the list
    for (int i = 0; i < timeStampList.LengthIs(); i++)
    {
        timeStampList.GetNextItem(temp);
        cout << temp << endl;
    }

    return 0;
}
