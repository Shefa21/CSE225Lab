//prime numbers in a range and the number of prime numbers
#include<iostream>
using namespace std;
int main()
{
    cout<<" take the starting and ending values: "<<endl;
    int a,b;
    cin>> a >> b;
    int count=0;

    for(int i=a; i<=b; i++)
    {
        bool isPrime=true;
        for(int j=2; j<=i/2; j++)
        {
            if(i%j==0)
            {
                isPrime=false;
                break;
            }
        }
        if(isPrime)
        {
            cout<<i<<endl;
            count++;
        }


    }
    cout<<"count: " << count<<endl;


}

//take integer input and print some of the digits
#include<iostream>
using namespace std;
int main()
{
    int a;
    cout<<"input an integer: "<<endl;
    cin>>a;//34
    int sum=0;
    while(a!=0)
    {
        int digit = a%10;//4 remainder//3 remainder
        sum+=digit;//0+4+3
        a/=10;//3
    }
    cout<<"the sum of digits is : "<< sum<<endl;
    return 0;

}
//right triangle of 5 rows of stars
#include<iostream>
using namespace std;
int main()
{
    int a;
    cout<<"input an integer: "<<endl;
    cin>>a;
    for(int i=1; i<=a; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    return 0;

}
//factorial of a number
#include<iostream>
using namespace std;
int main()
{
    int a;
    cout<<"input an integer: "<<endl;
    cin>>a;
    int factorial=1;
    for(int i=1; i<=a; i++)
    {


        factorial=factorial*i;



    }
    cout<<factorial;
    return 0;

}
//using if else and switch
//check whether 2 numbers are multiples of 3

#include<iostream>
using namespace std;
int main()
{

    int a,b;
    cout<<"input 2 integers: "<<endl;
    cin>>a>>b;
    switch((a%3==0)+(b%3==0)*2)
    {
    case 1:
        cout<<"only first number is the multiple of 3"<<endl;
        break;
    case 2:
        cout<<"only second number is the multiple of 3"<<endl;
        break;
    case 3:
        cout<<"both numbers are the multiples of 3"<<endl;
        break;
    default:
        cout<<"none are multiples of 3"<<endl;
        break;

    }

    return 0;

}
//using if else
#include<iostream>
using namespace std;
int main()
{

    int a,b;
    cout<<"input 2 integers: "<<endl;
    cin>>a>>b;
    if(a%3==0 && b%3!=0)
    {
        cout<<"first multiple";
    }
    else if(a%3!=0 && b%3==0)
    {
        cout<<"second multiple";

    }
    else if(a%3==0 && b%3==0)
    {
        cout<<"both multiples";
    }
    else
    {
        cout<<"none multiples";
    }

    return 0;

}
//take 3 float numbers and check if their summation is between 10 and 15
#include<iostream>
using namespace std;
int main()
{

    float a,b,c;
    cout<<"input 3 float numbers : "<<endl;
    cin>>a>>b>>c;
    if(10<=(a+b+c) && (a+b+c)<=15)
    {
        cout<<"yes";
    }

    else
    {
        cout<<"no";
    }

    return 0;

}
//using switch
#include<iostream>
using namespace std;
int main()
{

    float a,b,c;
    cout<<"input 3 float numbers : "<<endl;
    cin>>a>>b>>c;
    switch ((10<=(a+b+c)) + ((a+b+c)<=15))
    {
    case 2:
        cout<<"yes";
        break;
    default:
        cout<<"no";
    }


    return 0;

}

//take 2 integers and a character (mathematical operation) and do it accordingly
#include<iostream>
using namespace std;
int main()
{

    int a,b;
    char c;
    cout<<"input 2 numbers and a character : "<<endl;
    cin>>a>>b>>c;
    switch (c)
    {
    case '+':
        cout<<a+b;
        break;
    case '-':
        if(a>b)
            cout<<a-b;
        else
            cout<<b-a;
        break;
    case '*':
        cout<<a*b;
        break;
    case '/':
        cout<<a/b;
        break;

    default:
        cout<<"invalid operator";
    }


    return 0;

}
//using if else
#include<iostream>
using namespace std;
int main()
{

    int a,b;
    char c;
    cout<<"input 2 numbers and a character : "<<endl;
    cin>>a>>b>>c;
    if(c=='+')
        cout<<a+b;

    else if (c=='-')
        if(a>b)
            cout<<a-b;
        else
            cout<<b-a;

    else if(c=='*')
        cout<<a*b;

    else if(c=='/')
        cout<<a/b;


    else
        cout<<"invalid operator";



    return 0;

}

////take 3 integers anch check if the product of 3 numbers is less than 100 and can be divided by 8 with no remainder
#include<iostream>
using namespace std;
int main()
{

    int a,b,c;

    cout<<"input 3 numbers : "<<endl;
    cin>>a>>b>>c;
    int product = a*b*c;
    if(product <100 && product%8==0)
        cout<<"yes";


    else
        cout<<"no";



    return 0;

}
//using switch
#include<iostream>
using namespace std;
int main()
{

    int a,b,c;

    cout<<"input 3 numbers : "<<endl;
    cin>>a>>b>>c;
    int product = a*b*c;

    switch((product <100) + (product%8==0))
    {
    case 2:
        cout<<"yes";
        break;


    default:
        cout<<"no";
    }



    return 0;

}

//add 2 numbers using pointers . in addition, give comments before each line of code to explain how it works . After that , delete those variables by using the delete keyword
#include<iostream>
using namespace std;
int main()
{

    //three integers are declared and they are assigned memory location using new int
    //this dynamically allocates memory for integer variables and returns a pointer to that memory
    int* a=new int;
    int* b=new int;
    int* c=new int;
//the * operator is used to dereference the pointers, allowing the user to input values directly into the memory locations pointed to by a,b,c

    cout<<"input 3 numbers : "<<endl;
    cin>>*a>>*b>>*c;
    //the * operators are again used to access the values stored at the memory locations pointed to by a,b,c.These values are then added
    int sum= *a+*b+*c;

    cout<<sum<<endl;
    //delete allocated memory to avoid memory leaks, ensuring that the memory is returned to the system once its no longer needed
    delete a,delete b,delete c;



    return 0;

}

//take 2 numbers as input and swap them using pointers
#include<iostream>
using namespace std;
int main()
{

    //three integers are declared and they are assigned memory location using new int
    //this dynamically allocates memory for integer variables and returns a pointer to that memory
    int* a=new int;
    int* b=new int;

//the * operator is used to dereference the pointers, allowing the user to input values directly into the memory locations pointed to by a,b,c

    cout<<"input 2 numbers : "<<endl;
    cin>>*a>>*b;
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    cout<<*a<<"\n"<<*b<<endl;



    //delete allocated memory to avoid memory leaks, ensuring that the memory is returned to the system once its no longer needed
    delete a,delete b;



    return 0;

}

//take 3 numbers as input and swap them using pointers. 
#include<iostream>
using namespace std;
int main()
{

    //three integers are declared and they are assigned memory location using new int
    //this dynamically allocates memory for integer variables and returns a pointer to that memory
    int* a=new int;
    int* b=new int;
    int* c=new int;

//the * operator is used to dereference the pointers, allowing the user to input values directly into the memory locations pointed to by a,b,c

    cout<<"input 3 numbers : "<<endl;
    cin>>*a>>*b>>*c;
    int temp;
    temp=*a;
    *a=*c;
    *c=*b;
    *b=temp;
    cout<<*a<<"\n"<<*b<<"\n"<<*c<<endl;



    //delete allocated memory to avoid memory leaks, ensuring that the memory is returned to the system once its no longer needed
    delete a,delete b,delete c;



    return 0;

}
