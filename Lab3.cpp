//task 1 reverse an array by storing it in another array. use DMA
//using function
#include <iostream>

using namespace std;

// Function to populate an array
void populateArray(int *arr, int size) {
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

// Function to print an array
void printArray(const int *arr, int size) {
    cout << "Array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to reverse an array and store it in another array
void reverseArray(const int *originalArr, int *reversedArr, int size) {
    for (int i = 0; i < size; ++i) {
        reversedArr[i] = originalArr[size - 1 - i];
    }
}

int main() {
    int n;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Allocate memory for the original array dynamically
    int *originalArr = new int[n];

    // Populate the original array
    populateArray(originalArr, n);

    // Print the original array
    printArray(originalArr, n);

    // Allocate memory for the reversed array dynamically
    int *reversedArr = new int[n];

    // Reverse the array and store it in the new array
    reverseArray(originalArr, reversedArr, n);

    // Print the reversed array
    printArray(reversedArr, n);

    // Deallocate the dynamically allocated memory
    delete[] originalArr;
    delete[] reversedArr;

    return 0;
}

//not using function
#include <iostream>

using namespace std;

int main() {
    int n;

    // Input the size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Allocate memory for the original array dynamically
    int *originalArr = new int[n];

    // Input elements into the original array
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> originalArr[i];
    }

    // Allocate memory for the reversed array dynamically
    int *reversedArr = new int[n];

    // Reverse the array and store it in the new array
    for (int i = 0; i < n; ++i) {
        reversedArr[i] = originalArr[n - 1 - i];
    }

    // Output the reversed array
    cout << "Reversed array: ";
    for (int i = 0; i < n; ++i) {
        cout << reversedArr[i] << " ";
    }

    // Deallocate the dynamically allocated memory
    delete[] originalArr;
    delete[] reversedArr;

    return 0;
}

//task 2 search an element in an array
//using function
#include<iostream>
using namespace std;


void populateArray(int* arr, int size)//takes pointer to integer and size of array

{
    cout<<"enter elements of array: "<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
}
void printArray(int* arr, int size)
{
    cout<<"Array elements: "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }

}
int search(int* arr,int size,int target)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i]==target)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int size;
    cout<<"enter size of the array: ";
    cin>>size;

    int* arr = new int[size];//dynamically allocates memory for an integer array of size size using the new operator
    populateArray(arr,size);//passing array arr but due to array to pointer decay it is treated as a pointer to its first element(int*),not as a whole array
    //this allows the function to modify the elements of the array directly in memory
    //void populateArray(int arr[] , int size)
    //it would essentially be the same, as array parameters decay to pointers in function declarations
    //so using a pointer to an integer allows the function to work with the actual memory locations where the 
    //array elements are stored , making it possible to modify the array directly
    printArray(arr,size);
    int target;
    cout<<"enter element to find: "<<endl;
    cin>>target;
    int index = search(arr,size,target);

        if(index!=-1)
        {
            cout<<"Element found at index "<<index<<endl;
        }
        else
        {
            cout<<"Element not found in the array "<<endl;
        }
        delete[]arr;
        return 0;

}
//without using function
#include<iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    int target;
    cin >> target;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            cout << "Found at index " << i << endl;
            delete[] arr;  // Delete the array before returning
            return 0;

        }
        // No break here
    }

    cout << "Not found" << endl;

    delete[] arr;
    return 0;
}

//task 3 find maximum element in an array
#include<iostream>
using namespace std;
int main()
{
    int size;
    cout<<"enter size of array: ";
    cin>>size;
    int* arr = new int[size];
    cout<<"enter elements in the array : ";
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }
    int maxElement=arr[0];
    for(int i=1; i<size; i++)
    {
        if(arr[i]>maxElement)
        {
            maxElement=arr[i];

        }
    }
    cout<<"the max element is "<<maxElement;
    delete[] arr;
    return 0;
}
//using function
#include<iostream>
using namespace std;

// Function to populate the array
void populateArray(int* arr, int size) {
    cout << "Enter elements in the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

// Function to print the array
void printArray(int* arr, int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to find the maximum element in the array
int findMaxElement(int* arr, int size) {
    int maxElement = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int* arr = new int[size];

    // Call the function to populate the array
    populateArray(arr, size);

    // Call the function to print the array
    printArray(arr, size);

    // Call the function to find the max element
    int maxElement = findMaxElement(arr, size);

    cout << "The max element is " << maxElement << endl;

    delete[] arr;
    return 0;
}

