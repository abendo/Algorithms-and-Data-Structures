/**
 * ALBRIT BENDO
 * ADS HW6
 * PROBLEM 6.1(d)
 * */
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
// To avoid the worning of: "comparison of integer expressions of different signedness"
// in line 17 I am using size_t which is an unsigned integer, 
size_t max_char(string arr[], int size)
{
    size_t element = arr[0].size();
    for(int i = 1; i < size; i++) {
        if(arr[i].size() > element)
            element = arr[i].size();
    }
    return element;
}

void count_sort(string arr[], int size, size_t k)
{
    string *a = NULL;
    int *b = NULL;

    a = new string[size]; // b
    b = new int[257]; // c

    for(int i = 0; i < 257; i++) {
        b[i] = 0;
    }

    for(int j = 0; j < size; j++) {
        b[k < arr[j].size() ? (int)(unsigned char)arr[j][k] + 1 : 0]++;
        // Where arr[j] is the string
    }

    for(int k = 0; k < 257; k++) {
        b[k] += b[k-1];
    }

    for(int r = size - 1; r >= 0; r--) {
        a[b[k < arr[r].size() ? (int)(unsigned char)arr[r][k] + 1 : 0] - 1] = arr[r];
        b[k < arr[r].size() ? (int)(unsigned char)arr[r][k] + 1 : 0]--;
    }

    for(int l = 0; l < size; l++) {
        arr[l] = a[l];
    }

    delete [] a;
    delete [] b;
}

void radix_sort(string arr[], int size) 
{
    size_t max = max_char(arr, size);

    for(size_t i = max; i > 0; i--) {
        count_sort(arr, size, i-1);
    }
}

int main()
{
    string arr[] = { "word", "category", "cat", "new", "news", "world", 
                    "bear", "at", "work", "time"};

    for(int j = 0; j < 10; j++) {
        cout << arr[j].c_str() << ", ";
    }
    cout << endl;

    radix_sort(arr, 10);

    cout << "Alphabetically sorted words are: " << endl;
    for(int i = 0; i < 10; i++) {
        cout << "[" << arr[i].c_str() << "]" << endl;
    }
    return 0;
}