/**
 * ALBRIT BENDO
 * ADS HW6
 * PROBLEM 6.1(b)
 * BUCKET SORT
 * */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void bucketSort(float arr[], int size)
{
    vector<float> store[size]; // Using size buckets
    int count = 0;
    // Empty bucket

    for(int i = 0; i < size; i++) {
        int a = size*arr[i]; // Put array elements in diff buckets
        store[a].push_back(arr[i]); // Using different buckets
    }

    for(int i = 0; i < size; i++) {
        sort(store[i].begin(), store[i].end()); // Sorting by insertion sort
    }

    for(int i = 0; i < size; i++) { // Collecting all nr.
        for(float j = 0.0; j < store[i].size(); j++) {
            arr[count++] = store[i][j];
        }
    }
}

void print(float arr[]) // A printing function
{
    for(int i = 0; i < 7; i++) {
        cout << "[" << arr[i] << "] ";
    }
    cout << endl;
}

int main()
{
    float arr[] = {0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1 };

    bucketSort(arr, 7);

    print(arr);

    return 0;
}

// Reference: https://en.wikipedia.org/wiki/Bucket_sort
//          : https://www.youtube.com/watch?v=3mxp4JLGasE