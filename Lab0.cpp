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


