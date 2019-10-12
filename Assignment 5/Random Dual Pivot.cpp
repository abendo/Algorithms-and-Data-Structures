/**
 * ALBRIT BENDO
 * ADS HW 5
 * QUICK SORT
 * DUAL RANDOM PIVOT QUICKSORT
 * */

#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

int dual_pivot_partition(int arr[], int low, int high, int *ptr)
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

int random_pivot(int arr[], int low, int high)
{
    int p;
    srand(time(0));
    // Assigning two random values to the two pivots
    int random1_pivot = rand() % ((high+low)/2 - low); // One random for the first half
    int random2_pivot = rand() % (high - (high+low)/2); // One random for the sec half

    swap(arr[random1_pivot], arr[low]);
    swap(arr[random2_pivot], arr[high]);
    return dual_pivot_partition(arr, low, high, &p);
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
        arr[i] = rand() % 100;
        cout << "[" << arr[i] << "] ";
    }
    cout << endl;

    
        quick_sort(arr, 0, 9);

    for(int i = 0; i < 10; i++)
    {
        cout << "[" << arr[i] << "] "; 
    }
    cout << endl;

    return 0;
}