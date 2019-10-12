/**
 * ALBRIT BENDO
 * ADS HW 5
 * QUICK SORT 
 * DUAL PIVOT QUICKSORT
 * */
#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>

using namespace std;

int dual_pivot_partition(int arr[], int low, int high, int* ptr)
{
    if(arr[low] > arr[high]) // If less then 
    {
        swap(arr[high], arr[low]);
    }
    
    int i = low + 1;
    int j = high - 1; 
    int k = low + 1; 
    int ptr_left = arr[low]; 
    int ptr_right = arr[high]; 

    while(k <= j)
    {
        if(arr[k] < ptr_left)
        {
            swap(arr[k], arr[i]);
            i++;
        }
        else if(arr[k] >= ptr_right) // If greater of equal to pivot
        {
            while(arr[j] > ptr_right && k < j)
            {
                j--;
            }
            swap(arr[k], arr[j]);
            j--;
            if(arr[k] < ptr_left)
            {
                swap(arr[k], arr[i]);
                i++;
            }
        }
        k++;
    }
    i--;
    j++;

    swap(arr[low], arr[i]);
    swap(arr[high], arr[j]);

    *ptr = i;

    return j;
}

void quick_sort(int arr[], int low, int high)
{
    int left_pivot;
    int right_pivot;

    if(low < high)
    {
        right_pivot = dual_pivot_partition(arr, low, high, &left_pivot);
        quick_sort(arr, low, left_pivot-1);
        quick_sort(arr, left_pivot+1, right_pivot-1);
        quick_sort(arr, right_pivot+1, high);
    }
}

int main()
{
    srand(time(0));

    int arr[10];

    for(int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 1000;
        cout << arr[i] << endl;
    }
    cout << endl;

    auto start = chrono::steady_clock::now();

    quick_sort(arr, 0, 9); // As we are using the last element

    auto stop = chrono::steady_clock::now();

    for(int i = 0; i < 10; i++)
    {
        cout << "[" << arr[i] << "] ";
    }
    cout << endl;
    cout << "Dual-Pivot Quciksort Algorithm elapsed time: " <<
    chrono::duration_cast<chrono::milliseconds>(stop - start).count() <<
    " milliseconds" << endl;

    return 0;
}    