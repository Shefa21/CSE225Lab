/* task 1: Using the new operator, allocate an integer array of user specified size (the user gives the size of the array as 
input). Assign values to the array elements by taking user inputs and then print the values. Finally de-allocate the array 
using the delete operator.*/
#include<iostream>
using namespace std;

int main()
{
    int size;
    cout<<"enter size of array : ";
    cin>>size;
    int *arr = new int[size];
    cout<<"enter values: ";
    for(int i=0; i<size; i++)
    {

        cin>>arr[i];
    }

    cout<<"the 1d array is : "<<endl;
    for(int i=0; i<size; i++)
    {

        cout<<arr[i] <<" ";

    }


    delete[] arr;
    return 0;


}

/* task 2 Using the new operator, allocate an integer array of user specified size (the user gives the size of the array as 
input). Assign values to the array elements by taking user inputs and then print the values. Finally de-allocate the array 
using the delete operator*/
#include<iostream>
using namespace std;

int main()
{
    // Declare variables for the number of rows and columns
    int r, c;

    // Prompt user to enter the number of rows and columns
    cout << "Enter the number of rows and columns: ";
    cin >> r >> c;

    // Dynamically allocate memory for a 2D array of characters
    char **arr = new char*[r];
    for (int i = 0; i < r; i++)
    {
        arr[i] = new char[c];
    }

    // Input characters into the 2D array
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "Enter character for position [" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    // Display the 2D array
    cout << "The 2D array is: " << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    // Deallocate the dynamically allocated memory to prevent memory leaks
    for (int i = 0; i < r; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    // Return 0 to indicate successful program execution
    return 0;
}




/* task3 Using the new operator, allocate a two dimensional integer array. The number of rows and columns are going 
to be provided by the user as input. However, in this task, all of the rows are not the same size (the array is uneven). 
The user will specify how many elements the individual rows will have. Assign values to the array elements by taking 
user inputs and then print the values. Finally de-allocate the array using the delete operator. */

#include<iostream>
using namespace std;
int main()
{
    int r;
    cout<<"enter the number of rows ";
    cin>>r;

    int *size = new int[r];

    for(int i=0; i<r; i++)
    {
        cout<<"enter number of elements for row " << i+1<<" ";
        cin>>size[i];
    }

    int **arr = new int *[r];
    for(int i=0; i<r; i++)
    {
        arr[i]=new int[size[i]];
    }
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<size[i]; j++)
        {
            cout<<"enter value for arr[" <<i<<j<<"] ";
            cin>>arr[i][j];
        }
    }
    cout<<"The 2D array is : "<<endl;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<size[i]; j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<"\n";
    }
    for(int i=0; i<r; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] size;
    return 0;


}


