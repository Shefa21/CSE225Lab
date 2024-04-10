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

