//task 1 - take 4 numbers and print the smallest and greatest among them only using if else
#include<iostream>
using namespace std;
int main()
{
    int n1,n2,n3,n4;
    cin>>n1>>n2>>n3>>n4;
    int smallest,greatest;
    if(n1>n2)
    {
        smallest=n2;
        greatest=n1;
    }
    else
    {
        smallest=n1;
        greatest=n2;
    }

    if (n3 < smallest)
    {
        smallest = n3;
    }
    else if (n3 > greatest)
    {
        greatest = n3;
    }
    if (n4 < smallest)
    {
        smallest = n4;
    }
    else if (n4 > greatest)
    {
        greatest = n4;
    }
    cout << "Smallest number: " << smallest << endl;
    cout << "Greatest number: " << greatest << endl;

    return 0;
}
//task 2 - print 10+20=30 without using any int variables and the calculation should happen in the code
#include<iostream>
using namespace std;
int main()
{
    cout<<"10+20= "<<10+20<<endl;
}
//task 3 - using switch case to check odd even
#include<iostream>
using namespace std;
int main()
{
    cout<<"enter a number: "<<endl;
    int n;
    cin>>n;
    switch(n%2)
    {
    case 0:
        cout<<"it is an even number"<<endl;
        break;
    case 1:
        cout<<"it is an odd number"<<endl;
        break;
    default:
        cout<<"Invalid input"<<endl;
        break;

    }
}



