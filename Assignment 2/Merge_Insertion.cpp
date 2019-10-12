/**
*   Albrit Bendo
*   Matr nr. 30001902
*   ADS HW 2.1
*   implementation of merge  
*   and insertion sort
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <chrono>

#define MAX 100000000 // Using a macro just to define a max nr

using namespace std;

// Genereting random numbers
void random_number_generator(int *arr, int size) 
{ // For the average case
    cout << "Random values:" << endl;
    for(int i=0; i<size; i++)
    {
        arr[i] = rand() % 100; // function rand() for random
        cout << arr[i] << endl;
    }
 // Besauce the numbers are rendom is the average case   
}

void worst_case(int a[], int size) 
{ // For the worst case
    for (int i=0; i < size; i++) {
        a[i] = size-i-1; // Nr of elements you want to sort in reverse
        cout << a[i] << endl;
    }
// Because the numbers are in reverse is the worst case
}

void best_case(int a[], int size) 
{ // For the best case
    for (int i=0; i < size; i++) {
        a[i] = i; // Nr of elements already sorted
        cout << a[i] << endl;
    }
// Because the numbers are in order is the best case
}

// Insertion sort function
void insertionSort(int arr[], int x, int y)
{
   for (int i=x; i<=y; i++)
   {
       int index = arr[i];
       int j = i-1;
// Move nr greater than index one position ahead
       while (j>=0 && arr[j]>index)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = index;
   }
}

// The merge function
void merge(int *arr, int low, int mid, int high)
{
    int start = low;
    int end = high;

    low =(mid - start)+ 1; // All elements of the first half
    high = end - mid; 

    int *p = new int[low+1]; // Creating two subarrays
    int *q = new int[high+1]; // for first and sec half of array

    p[low] = MAX; // So it doesn't go out of the line
    q[high] = MAX;

    for(int i=start; i<=mid; i++)
        p[i-start] = arr[i]; // for loop for the first half

    for(int i=mid+1; i<=end; i++)
        q[i-mid-1] = arr[i]; // for loop for the sec half

    // Just to point where we want
    int i=0;
    int j=0;
    int k=start;

    while(k <= end) // Deffining the function of the variable k
    {
        if(p[i] <= q[j]) // Guards
        {
            arr[k]=p[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=q[j];
            k++;
            j++;
        }
    }
}

// Implementing both function insertion and merge
void merge_sort(int *arr, int x, int y, int k) 
// Where x is the beggining, y last and k just a parameter to determine where to stop dividing 
{
    if (y-x+1 <= k)
    {
        insertionSort(arr, x, y); // From k and down we implement the insertion sort
    }
    else
    {
        merge_sort(arr,x,(x+y)/2,k); // Else keep using the merge sort first half
        merge_sort(arr,(x+y)/2+1,y,k); // sec half
        merge(arr,x,(x+y)/2,y); // all 
    }
}

// Main function
int main()
{
    srand(time(0)); // Specific time each time of running

    int size;
    cout << "Enter the number of elements you want to sort:" << endl;
    cin >> size; // Determine the size of the array
    int *arr = new int[size]; // Dynamically allocated array

//for(int i=0; i<100; i++)
//{
    //random_number_generator(arr, size); // Fill the array with some random values
    //best_case(arr, size);
    worst_case(arr, size);

    int k;
    cout << "Subsequences of length k = ";
    cin >> k;

// clock() function used to measure the time
    
    auto start = chrono::high_resolution_clock::now();

    merge_sort(arr, 0, size-1, k); // Calling the merge function
// Where 0 is the beggining x, size-1 is the finnish of array y and k is the subsequences of length
    // As we add 1 now we have to substract 1 from the size so all elements get printed
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    cout << "Elapsed time: " << elapsed.count() << " Seconds";

    cout << endl;
//}
    cout << "Sorted array: " << endl;

    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " "; // Print the sorted array
    }

    delete [] arr;

    return 0;
}

// P.S.: Sorry for the long code. Going to learn using python soon.