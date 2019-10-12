/**
 * ALBRIT BENDO
 * ADS HW6
 * PROBLEM 6.1(a)
 * COUNTING SORT
 * */
#include <iostream>
#include <cstring>

using namespace std;

// Creating a function for implementing Counting Sort
void count_sort(int arr[], int size, int range)
{
    int arr_out[size];
    int arr_s[range];
    int count = 0;
    memset(arr_s, 0, sizeof(arr_s)); // To avoid segmentation error
                                    // we initialize arr_s with zeros

    for(int i = 0; i < size; i++) {
        arr_s[arr[i]]++; // Store the counting
    }

    for(int i = 0; i < range; i++) {
       int prev_count = arr_s[i]; // Getting the starting index
       arr_s[i] = count;
       count += prev_count;
    }

    for(int i = 0; i < size; i++) {
        arr_out[arr_s[arr[i]]] = arr[i]; // Place at the correct position
        arr_s[arr[i]]++;
    }

    for(int i = 0; i < size; i++) { 
        arr[i] = arr_out[i]; // Copy the output to input
    }
}

void print(int arr[]) // Printing function
{
    for(int i = 0; i < 7; i++) {
        cout << "[" << arr[i] << "] ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {9, 1, 6, 7, 6, 2, 1};
    int range = 10; // Range = 9+1

    count_sort(arr, 7, range);

    print(arr);

    return 0;
}

// Reference: Introduction to Algorithms (book)