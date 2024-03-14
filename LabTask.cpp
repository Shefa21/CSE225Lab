


#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED
template<class T>
class calculator
{

private:
    T a;
    T b;


public:
    calculator(T,T);

    void set_number(T ,T);

    T getadd();
    T getproduct();
    T getdiv();
    T getdiff();
    T getper();



};


#endif // CALCULATOR_H_INCLUDED
#include "calculator.h"
#include<iostream>
using namespace std;
template<class T>
calculator<T>::calculator(T a1, T b1)
{
    a=a1;
    b=b1;
}
template<class T>
void calculator<T>::set_number(T a1,T b1)
{
     a = a1;
     b= b1;
}
template<class T>
T calculator <T>:: getadd()
{
    return a+b;
}
template<class T>
T calculator <T>:: getdiff()
{
    return a-b;
}
template<class T>
T calculator <T>:: getdiv()
{

    return a/b;
}
template<class T>
T calculator <T>:: getproduct(){
return a*b;
}
template<class T>
T calculator <T>:: getper(){
return (a/b)*100;
}
#include <iostream>
#include "calculator.cpp"
#include "calculator.h"

using namespace std;

int main()
{

    cout<<"enter two numbers: ";

    float a,b;
    cin>>a>>b;

    calculator<float>a1(a,b);
    cout<<"add is "<<a1.getadd()<<endl;
    cout<<"subtract is "<<a1.getdiff()<<endl;
    cout<<"product is "<<a1.getproduct()<<endl;
    cout<<"percentage is "<<a1.getper()<<endl;

    cout<<"division  is "<<a1.getdiv()<<endl;
    cout<<"enter two numbers: ";

    int c,d;
    cin>>c>>d;
    calculator<int>a2(c,d);
    cout<<"add is "<<a2.getadd()<<endl;
    cout<<"subtract is "<<a2.getdiff()<<endl;
    cout<<"product is "<<a2.getproduct()<<endl;
    cout<<"percentage is "<<a2.getper()<<endl;

    cout<<"division  is "<<a2.getdiv()<<endl;
    cout<<"enter two numbers: ";
    double e,f;
    cin>>e>>f;
    calculator<double>a3(e,f);
    cout<<"add is "<<a3.getadd()<<endl;
    cout<<"subtract is "<<a3.getdiff()<<endl;
    cout<<"product is "<<a3.getproduct()<<endl;
    cout<<"percentage is "<<a3.getper()<<endl;

    cout<<"division  is "<<a3.getdiv()<<endl;



}
