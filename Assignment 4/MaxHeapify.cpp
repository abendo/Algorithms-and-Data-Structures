/** 
 *  ALBRIT BENDO  
 *  ADS HW 4
 *  PROBLEM 4.2
 *  HEAP SORT ALGORITHM
 **/
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <ctime>
#include <math.h>

using namespace std;

// Creating a max heap
void create_heap(int array[], int size, int root)
{
    int largest = root;
    int left = 2*root + 1; // Could be also done by bit shifting to left
    int right = 2*root + 2; // By bit shifting to left and adding 1
// From the pseudocode of slides
    if(left <= size && array[left] > array[largest])
    {
        largest = left;
    }

    if(right <= size && array[right] > array[largest])
    {
        largest = right;
    }

    if(largest != root)
    {
        swap(array[root], array[largest]);
        create_heap(array, size, largest); // Using a recursive function
    }
}

void return_up(int array[], int root)
{
    int parent = ceil((root-2)/2);
    if(array[parent] < array[root] && parent > 0)
    {
        swap(array[parent], array[root]);
        return_up(array, parent);
    }
}

void max_heap(int array[], int size, int root)
{
    int largest;
    int left = 2*root+1;
    int right = 2*root+2;

    if((left <= size) && (array[left] > array[root]))
    {
        largest = left;
    }
    else
    {
        largest = root;
    }

    if((right <= size) && (array[right] > array[largest]))
    {
        largest = right;
    }

    if(largest != root)
    {
        swap(array[root], array[largest]);
        max_heap(array, size, largest);
    }
    
}

// This is the main algorithm of heap sort
void heap_sort(int array[], int size)
{
    for(int i = (size-1)/2; i >= 0; i--)
    {
        create_heap(array, size, i);
    }
    int n = size;
        for(int i = n; i > 0; i--)
    {
        swap(array[0], array[i]);
        size--;
        max_heap(array, size, 0);
    }
}

int main()
{
    srand(time(0));
// Creating a dynamically allocated array
    int size;
    cout << "Enter the size of array" << endl;
    cin >> size;
    int n = size;
    int *array = new int[size];
// Filling it with random numbers
    cout << "Array filled with random number is of size " << size << ": " << endl; 
    for(int i = 0; i < size; i++)
    {
        array[i] = rand() % 1000;
        cout << "[" << array[i] << "]" << " ";
    }
    cout << endl;

auto start = chrono::steady_clock::now();

    heap_sort(array, size-1);

auto stop = chrono::steady_clock::now();

    cout << "Heapify.. " << endl;
    //Print the elements
    for(int i = 0; i < n; ++i)
    {
        cout << array[i] << endl;
    }

cout << "Elapsed time: " << 
    chrono::duration_cast<chrono::milliseconds>(stop - start).count() << 
    " milliseconds" << endl;
    
    return 0;
}