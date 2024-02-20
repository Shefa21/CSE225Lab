//printing 0 to 9 using 3 loops

#include <iostream>

using namespace std;

int main()
{
    cout<<"using for loop"<<endl;
    for(int i=0; i<10; i++)
    {
        cout << i << endl;
    }
    cout<<"using while loop"<<endl;
    int j=0;
    while(j<10)
    {
        cout<<j<<endl;
        j++;
    }

    cout<<"using do while loop "<<endl;
    int k=0;
    do
    {
        cout<<k<<endl;
        k++;
    }
    while(k<10);

    return 0;
}

//checking odd,even,perfect number,palindrome and prime number using 3 loops
#include<iostream>
using namespace std;

int main()
{
    int n1;
    cout << "Enter a number: ";
    cin >> n1;

    // Checking odd or even
    if (n1 % 2 == 0)
    {
        cout << "It is an even number" << endl;
    }
    else
    {
        cout << "It is an odd number" << endl;
    }

    // Checking palindrome
    cout << "Using for loop" << endl;
    int originalNum, reversedNum = 0;
    originalNum = n1;
    for (int temp = n1; temp > 0; temp /= 10)
    {
        int digit = temp % 10;
        reversedNum = reversedNum * 10 + digit;
    }
    if (originalNum == reversedNum)
    {
        cout << "It is a palindrome" << endl;
    }
    else
    {
        cout << "It is not a palindrome" << endl;
    }

    cout << "Using while loop" << endl;
    int temp = n1; // Reset temp to the original value of n1
    reversedNum = 0;
    while (temp > 0)
    {
        int digit = temp % 10;
        reversedNum = reversedNum * 10 + digit;
        temp /= 10;
    }
    if (originalNum == reversedNum)
    {
        cout << "It is a palindrome" << endl;
    }
    else
    {
        cout << "It is not a palindrome" << endl;
    }

    cout << "Using do-while loop" << endl;
    temp = n1; // Reset temp to the original value of n1
    reversedNum = 0;
    do
    {
        int digit = temp % 10;
        reversedNum = reversedNum * 10 + digit;
        temp /= 10;
    }
    while (temp > 0);
    if (originalNum == reversedNum)
    {
        cout << "It is a palindrome" << endl;
    }
    else
    {
        cout << "It is not a palindrome" << endl;
    }

    // Checking perfect number
    int i = 1;
    int sum = 0;
    cout << "Using for loop" << endl;
    for (i = 1; i <= n1 / 2; i++)
    {
        if (n1 % i == 0)
        {
            sum += i;
        }
    }
    if (sum == n1)
    {
        cout << "It is a perfect number" << endl;
    }
    else
    {
        cout << "It is not a perfect number" << endl;
    }

    cout << "Using while loop" << endl;
    i = 1; // Reset i to 1
    sum = 0;
    while (i <= n1 / 2)
    {
        if (n1 % i == 0)
        {
            sum += i;
        }
        ++i;
    }
    if (sum == n1)
    {
        cout << "It is a perfect number" << endl;
    }
    else
    {
        cout << "It is not a perfect number" << endl;
    }

    cout << "Using do-while loop" << endl;
    i = 1; // Reset i to 1
    sum = 0;
    do
    {
        if (n1 % i == 0)
        {
            sum += i;
        }
        i++;
    }
    while (i <= n1 / 2);
    if (sum == n1)
    {
        cout << "It is a perfect number" << endl;
    }
    else
    {
        cout << "It is not a perfect number" << endl;
    }

    // Checking prime number
    bool isPrime = true;

    // Using for loop
    cout << "Using for loop to check prime number" << endl;
    for (int j = 2; j <= n1 / 2; ++j)
    {
        if (n1 % j == 0)
        {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
    {
        cout << "It is a prime number" << endl;
    }
    else
    {
        cout << "It is not a prime number" << endl;
    }

    // Using while loop
    isPrime = true;
    int j = 2;
    cout << "Using while loop to check prime number" << endl;
    while (j <= n1 / 2)
    {
        if (n1 % j == 0)
        {
            isPrime = false;
            break;
        }
        ++j;
    }
    if (isPrime)
    {
        cout << "It is a prime number" << endl;
    }
    else
    {
        cout << "It is not a prime number" << endl;
    }


    // Using do-while loop
    isPrime = true;
    int k = 2;
    cout << "Using do-while loop to check prime number" << endl;
    do
    {
        if (n1!=2 && n1 % k == 0)
        {
            isPrime = false;
            break;
        }
        ++k;
    }
    while (k <= n1 / 2 );
    if (isPrime)
    {
        cout << "It is a prime number" << endl;
    }
    else
    {
        cout << "It is not a prime number" << endl;
    }


    return 0;
}
