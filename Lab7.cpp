//unsorted list linked list implementation

unsortedtype.h
#ifndef UNSORTEDTYPE_H_INCLUDED
#define UNSORTEDTYPE_H_INCLUDED
template <class ItemType>
class UnsortedType
{
    struct NodeType
    {
        ItemType info;
        NodeType* next;
    };
public:
    UnsortedType();
    ~UnsortedType();
    bool IsFull();
    int LengthIs();
    void MakeEmpty();
    void RetrieveItem(ItemType&,
                      bool&);
    void InsertItem(ItemType);
    void DeleteItem(ItemType);
    void ResetList();
    void GetNextItem(ItemType&);
private:
    NodeType* listData;
    int length;
    NodeType* currentPos;
};
#endif // UNSORTEDTYPE_H_INCLUDED

unsortedtype.cpp
#include "unsortedtype.h"
#include <iostream>
using namespace std;
template <class ItemType>
UnsortedType<ItemType>::UnsortedType()
{
    length = 0;
    listData = NULL;
    currentPos = NULL;
}
template <class ItemType>
int UnsortedType<ItemType>::LengthIs()
{
    return length;
}
template<class ItemType>
bool UnsortedType<ItemType>::IsFull()
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
}
template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType
                                        item)
{
    NodeType* location;
    location = new NodeType;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
}
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType
                                        item)
{
    NodeType* location = listData;
    NodeType* tempLocation;
    if (item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;
    }
    else
    {
        while (!(item==(location->next)->info))
            location = location->next;
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}
template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType&
        item, bool& found)
{
    NodeType* location = listData;
    bool moreToSearch = (location != NULL);
    found = false;
    while (moreToSearch && !found)
    {
        if (item == location->info)
            found = true;
        else
        {
            location = location->next;
            moreToSearch = (location != NULL);
        }
    }
}
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
{
    NodeType* tempPtr;
    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
{
    MakeEmpty();
}
template <class ItemType>
void UnsortedType<ItemType>::ResetList()
{
    currentPos = NULL;
}
template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType&
        item)
{
    if (currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;
    item = currentPos->info;
}
/*
 Task:
 Generate the driver file (main.cpp) where you perform the following tasks. Note that you cannot make any change to the
 header file or the source file.

 You are given two sequences of integers arranged in ascending order. Your task is to combine the sequences into one
 ascending sequence. In order to get full marks, you have to make sure that the time complexity of combining two
 sequences is `O(N)`. You can safely assume that no integer will be repeated.Input starts with a positive integer
 "m" which specifies the number of elements in the first sequence. Next "m" values are the elements in the first
 sequence. The next positive integer "n" specifies the number of elements in the second sequence. Next "n" values are
 the elements in the second sequence.The output is the combined sequence.
*/

#include <iostream>
#include "unsortedtype.h"
#include "unsortedtype.cpp"
using namespace std;

int main()
{

    UnsortedType<int> list1, list2, merged;      // Create three lists

    int n, v;                                    // Taking inputs for list1
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        list1.InsertItem(v);
    }

    cin >> n;                                    // Taking inputs for list2
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        list2.InsertItem(v);
    }

    int value1, value2;
    int index1 = list1.LengthIs();
    int index2 = list2.LengthIs();
    list1.GetNextItem(value1);
    list2.GetNextItem(value2);

    while (index1 > 0 && index2 > 0)             // Merging the lists
    {
        if (value1 > value2)
        {
            merged.InsertItem(value1);
            index1--;
            if (index1 > 0)
                list1.GetNextItem(value1);
        }
        else if (value2 > value1)
        {
            merged.InsertItem(value2);
            index2--;
            if (index2 > 0)
                list2.GetNextItem(value2);
        }
        else
        {
            merged.InsertItem(value1);
            merged.InsertItem(value2);
            index1--;
            index2--;
            if (index1 > 0)
                list1.GetNextItem(value1);
            if (index2 > 0)
                list2.GetNextItem(value2);
        }
    }

    while (index1 > 0)                           // Adding the remaining elements of list1
    {
        merged.InsertItem(value1);
        index1--;
        if (index1 > 0)
            list1.GetNextItem(value1);
    }

    while (index2 > 0)                           // Adding the remaining elements of list2
    {
        merged.InsertItem(value2);
        index2--;
        if (index2 > 0)
            list2.GetNextItem(value2);
    }

    int value_merged;
    int index_merged = merged.LengthIs() - 1;

    while (index_merged >= 0)                    // Printing the merged list
    {
        merged.GetNextItem(value_merged);
        cout << value_merged << ' ';
        index_merged--;
    }
    cout << endl;

    return 0;
}


//sorted list linked list implementation

//sortedtype.h
#ifndef SORTEDTYPE_H_INCLUDED
#define SORTEDTYPE_H_INCLUDED
template <class ItemType>
class SortedType
{
    struct NodeType
    {
        ItemType info;
        NodeType* next;
    };
public:
    SortedType();
    ~SortedType();
    bool IsFull();
    int LengthIs();
    void MakeEmpty();
    void RetrieveItem(ItemType&,
                      bool&);
    void InsertItem(ItemType);
    void DeleteItem(ItemType);
    void ResetList();
    void GetNextItem(ItemType&);
private:
    NodeType* listData;
    int length;
    NodeType* currentPos;
};
#endif // SORTEDTYPE_H_INCLUDED
//sortedtype.cpp
#include "sortedtype.h"
#include <iostream>
using namespace std;
template <class ItemType>
SortedType<ItemType>::SortedType()
{
    length = 0;
    listData = NULL;
    currentPos = NULL;
}
template <class ItemType>
int SortedType<ItemType>::LengthIs()
{
    return length;
}
template<class ItemType>
bool SortedType<ItemType>::IsFull()
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
}
template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
    NodeType* newNode;
    NodeType* predLoc;
    NodeType* location;
    bool moreToSearch;
    location = listData;
    predLoc = NULL;
    moreToSearch = (location != NULL);
    while (moreToSearch)
    {
        if (location->info < item)
        {
            predLoc = location;
            location = location->next;
            moreToSearch = (location != NULL);
        }
        else moreToSearch = false;
    }
    newNode = new NodeType;
    newNode->info = item;
    if (predLoc == NULL)
    {
        newNode->next = listData;
        listData = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}
template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
{
    NodeType* location = listData;
    NodeType* tempLocation;
    if (item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;
    }
    else
    {
        while (!(item==(location->next)->info))
            location = location->next;
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}
template <class ItemType>
void
SortedType<ItemType>::RetrieveItem(ItemType
                                   & item, bool& found)
{
    NodeType* location = listData;
    bool moreToSearch = (location != NULL);
    found = false;
    while (moreToSearch && !found)
    {
        if (item == location->info)
            found = true;
        else if (item > location->info)
        {
            location = location->next;
            moreToSearch = (location !=
                            NULL);
        }
        else
            moreToSearch = false;
    }
}
template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
{
    NodeType* tempPtr;
    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
template <class ItemType>
SortedType<ItemType>::~SortedType()
{
    MakeEmpty();
}
template <class ItemType>
void SortedType<ItemType>::ResetList()
{
    currentPos = NULL;
}
template <class ItemType>
void
SortedType<ItemType>::GetNextItem(ItemType
                                  & item)
{
    if (currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;
    item = currentPos->info;
}
//main.cpp
#include <iostream>
#include "sortedtype.h"
#include "timeStamp.h"
using namespace std;

template<class T>
void Print(SortedType<T> u) {
  int length = u.LengthIs();
  T value;
  for (int i = 0; i < length; i++) {
    u.GetNextItem(value);
    cout << value << endl;
  }
  cout << endl;
}

int main() {

  SortedType<Time> st;

  cout<<"insert 5 time values in the format ssmmhh: ";
  for(int i =0;i<5;i++)
  {
      int a,b,c;
      cin>>a>>b>>c;

      Time t1(a,b,c);
      st.InsertItem(t1);
  }

  cout<<"enter the time to delete";
  int d,e,f;
  cin>>d>>e>>f;

  Time temp(d,e,f);
  st.DeleteItem(temp);

  cout<<"your list after deleting:"<<endl;
  Print(st);

  return 0;
}


#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED

#include "sortedtype.cpp"

class Time {
private:
  int seconds;
  int minutes;
  int hours;
public:
  Time();
  Time(int, int, int);
  bool operator==(Time);
  bool operator!=(Time);
  bool operator>(Time);
  bool operator<(Time);
  friend ostream &operator<<(ostream &, Time &);
};

#endif


#include "timeStamp.h"

Time::Time() {

}

Time::Time(int sec, int min, int hr) {
  seconds = sec;
  minutes = min;
  hours = hr;
}

bool Time::operator==(Time t) {
  if ((seconds == t.seconds) && (minutes == t.minutes) && (hours == t.hours))
    return true;
  else
    return false;
}

bool Time::operator<(Time t) {
  if ((hours < t.hours) || ((hours == t.hours) && (minutes < t.minutes)) || ((hours == t.hours) && (minutes == t.minutes) && (seconds < t.seconds)))
    return true;
  else
    return false;
}

bool Time::operator>(Time t) {
  if ((hours > t.hours) || ((hours == t.hours) && (minutes > t.minutes)) || ((hours == t.hours) && (minutes == t.minutes) && (seconds > t.seconds)))
    return true;
  else
    return false;
}

ostream &operator<<(ostream &os, Time &t) {
  os << t.seconds << ":" << t.minutes << ":" << t.hours;
  return os;
}

//alternative

//timeStamp.h
#ifndef TIMESTAMP_H_INCLUDED
#define TIMESTAMP_H_INCLUDED

#include <iostream>
#include <iomanip>

class timeStamp {
private:
    int seconds;
    int minutes;
    int hours;
public:
    timeStamp(int s = 0, int m = 0, int h = 0);
    void printTime() const;
    bool operator==(const timeStamp& other) const;
    bool operator<(const timeStamp& other) const;
};

#endif // TIMESTAMP_H_INCLUDED

//timeStamp.cpp
#include "timeStamp.h"

timeStamp::timeStamp(int s, int m, int h) : seconds(s), minutes(m), hours(h) {}

void timeStamp::printTime() const {
    std::cout << std::setw(2) << std::setfill('0') << seconds << ":"
              << std::setw(2) << std::setfill('0') << minutes << ":"
              << std::setw(2) << std::setfill('0') << hours << std::endl;
}

bool timeStamp::operator==(const timeStamp& other) const {
    return (seconds == other.seconds && minutes == other.minutes && hours == other.hours);
}

bool timeStamp::operator<(const timeStamp& other) const {
    if (seconds < other.seconds)
        return true;
    else if (seconds == other.seconds && minutes < other.minutes)
        return true;
    else if (seconds == other.seconds && minutes == other.minutes && hours < other.hours)
        return true;
    else
        return false;
}

//main.cpp
#include <iostream>
#include "timeStamp.h"
#include "sortedtype.h"
#include "sortedtype.cpp"
int main() {
    SortedType<timeStamp> timeList;

    // Inserting time values
    timeList.InsertItem(timeStamp(15, 34, 23)); // 15:34:23
    timeList.InsertItem(timeStamp(13, 13, 02));  // 13:13:02
    timeList.InsertItem(timeStamp(43, 45, 12)); // 43:45:12
    timeList.InsertItem(timeStamp(25, 36, 17)); // 25:36:17
    timeList.InsertItem(timeStamp(52, 02, 20));  // 52:02:20

    // Deleting the timestamp 25 36 17
    timeList.DeleteItem(timeStamp(25, 36, 17));

    // Printing the list
    int length = timeList.LengthIs();
    timeStamp timeItem;
    for (int i = 0; i < length; ++i) {
        timeList.GetNextItem(timeItem);
        timeItem.printTime();
    }

    return 0;
}

