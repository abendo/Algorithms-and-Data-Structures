/**
 * ALBRIT BENDO
 * ADS HW 5
 * QUICK SORT 
 * LOMUTO - HOARE - MEDIANOFTHREE
 * */
#include <iostream>
#include <algorithm>
#include <chrono>
#include <ctime>

using namespace std;

/// Implementing the Lomuto Partition 
int lomuto_partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; // Assign the pivot to the last element
    int i = (low - 1); // and an index i to the first so we can compare

    for(int j = low; j <= high-1; j++) // Using an index j to move through the array
    {
        if(arr[j] <= pivot) // Comparing with the pivot (high)
        {
            i++; // Come closer with index i
            swap(arr[i], arr[j]); // swap
        } 
    }
    swap(arr[i+1], arr[high]);     
    return (i+1);
}
// The recursive function of quick sort (Lomuto Partition)
void lomuto_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivot = lomuto_partition(arr, low, high);
        lomuto_sort(arr, low, pivot-1); // perform QuickSort in left-side
        lomuto_sort(arr, pivot+1, high); // perform QuickSort in right-side
    }
}
//==================================================================

/// Implementing the Hoare Partition
int hoare_partition(int arr[], int low, int high)
{
    int pivot = arr[(low+high)/2]; // Assign pivot to a value either low||high||(low+high)/2
    int i = low - 1;
    int j = high + 1;

    while(1) // The infinite loop
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if(i >= j)
        {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}
// The recursive function of quick sort (Hoare Partition)
void hoare_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivot = hoare_partition(arr, low, high);
        hoare_sort(arr, low, pivot); // left-hand side from low to j
        hoare_sort(arr, pivot+1, high); // right-hand side from j to high
    }
}
//==================================================================

int partition(int arr[], int low, int high) // Do the swappings and partition
{
    int left = low;
    int right = high;
    int pivot = arr[low];

    while(left < right)
    {
        while(arr[right] > pivot)
            right--;

        while((left < right) && (arr[left] <= pivot))
            left++;

        if(left < right)
            swap(arr[left], arr[right]);
    }
    arr[low] = arr[right];
    arr[right] = pivot;

    return right;
}

int find_median(int arr[], int low, int high) // Find the median here
{
    int middle = low + (high-low)/2;

    if(arr[low] > arr[middle])
    {
        swap(arr[middle], arr[low]);
    }
    if(arr[low] > arr[high])
    {
        swap(arr[low], arr[high]);
    }
    if(arr[middle] > arr[high])
    {
        swap(arr[high], arr[middle]);
    }
    swap(arr[middle], arr[low]);

    return partition(arr, low, high);
}
// Recursive function for swapping the elements
void medianofthree_sort(int arr[], int low, int high)
{
    int pivot;
    if(low < high)
    {
        pivot = find_median(arr, low, high);
        medianofthree_sort(arr, low, pivot-1);
        medianofthree_sort(arr, pivot+1, high);
    }
    
}

//==================================================================

int main()
{
    srand(time(0));
    int arr[1000];

// Using some random numbers (as we are going to measure the average time)
    for(int i = 0; i < 1000; i++)
    {
        arr[i] = rand() % 1000;
    }
        cout << endl;
// Creating two other copies of the array
    int arr2[1000];
    copy(arr, arr+1000, arr2);

    int arr3[1000];
    copy(arr, arr+1000, arr3);
// Lomuto
    auto start_l = chrono::steady_clock::now();
    for(int i = 0; i < 100000; i++)
    {
        lomuto_sort(arr, 0, 1000);
    }
    auto stop_l = chrono::steady_clock::now();

// Hoare
    auto start_h = chrono::steady_clock::now();
    for(int i = 0; i < 100000; i++)
    {
        hoare_sort(arr2, 0, 999); // As we are using the last element we call it with 999
    }
    auto stop_h = chrono::steady_clock::now();

// Median-Of-three
    auto start_m = chrono::steady_clock::now();
    for(int i = 0; i < 100000; i++)
    {
        medianofthree_sort(arr3, 0, 1000);
    }
    auto stop_m = chrono::steady_clock::now();

    cout << "Lomuto Partition Algorithm elapsed time: " <<
    chrono::duration_cast<chrono::milliseconds>(stop_l - start_l).count() <<
    " milliseconds" << endl;

    cout << "Hoare Partition Algorithm elapsed time: " <<
    chrono::duration_cast<chrono::milliseconds>(stop_h - start_h).count() <<
    " milliseconds" << endl;

    cout << "Median-Of-Three Algorithm elapsed time: " <<
    chrono::duration_cast<chrono::milliseconds>(stop_m - start_m).count() <<
    " milliseconds" << endl;

    return 0;
}

/* I used Wikipedia as a reference and some youtube videos.
    Also the "Introduction to Algorithms" book.
    Theses are the links: 
    https://en.wikipedia.org/wiki/Quicksort
    https://www.youtube.com/watch?v=7h1s2SojIRw
    https://www.youtube.com/watch?v=SLauY6PpjW4
    https://stackoverflow.com/questions/16137953/is-there-a-function-to-copy-an-array-in-c-c
*/ 