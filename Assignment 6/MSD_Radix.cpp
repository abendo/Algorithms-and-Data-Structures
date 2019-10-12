/**
 * ALBRIT BENDO
 * ADS HW6
 * PROBLEM 6.2(a)
 * RADIX SORT (original)
 * */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int max_element(vector<int>& arr) 
{
    int max_el = 0;
    for(size_t i = 0; i < arr.size(); i++) {
        max_el = max(max_el, arr[i]);
    }
    return max_el;
}
void bucket_sort(vector<int>& arr, int exponent)
{
    vector<int> bucket[10];
    int count = 0;

    for(size_t i = 0; i < arr.size(); i++) {
        int a = (arr[i]/exponent) % 10;
        bucket[a].push_back(arr[i]);
    } 

    for(int i = 0; i < 10; i++) {
        if(bucket[i].size() > 1) {
            bucket_sort(bucket[i], exponent/10);
        }
    }

    for(int i = 0; i < 10; i++) {
        for(size_t j = 0; j < bucket[i].size(); j++) {
            arr[count++] = bucket[i][j];
        }
    }
}

void radix_sort(vector<int>& arr)
{
    int exponent = 1;
    int max_el = max_element(arr); 
    
    while(max_el/exponent > 0) {
        exponent *= 10;
    }
    exponent /= 10; 
    // To get the current value after we get the number of digits divide by 10

    bucket_sort(arr, exponent);
}

// A print function
void print(vector<int>& arr) 
{
    for(size_t i = 0; i < arr.size(); i++) {
        cout << "[" << arr[i] << "] ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = { 34, 234, 532, 23, 432, 87 };
    
    radix_sort(arr);
    print(arr);
    return 0;
}