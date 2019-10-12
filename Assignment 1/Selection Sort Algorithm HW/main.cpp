/*
Albrit Bendo
ADS homework(1)
a.bendo@jacobs-university.de
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void average(int a[],int n) {
    for(int i=0; i<n; i++) // A loop to create an array of size 'size'
        {
            a[i] = rand() % 100; // & to fill the array with random numbers from 0-99
            cout << a[i] << endl; // & print them
        }
        cout << "Average case" << endl; // Because the numbers are random is the average case
}

void worst(int a[], int n) {
    for (int i=0; i < n; i++) {
        a[i] = n-i-1; // Nr of elements you want to sort in reverse
        cout << a[i] << endl;
    }
    cout << "Worst case" << endl; // Because the numbers are in reverse is the worst case
}

void best(int a[], int n) {
    for (int i=0; i < n; i++) {
        a[i] = i; // Nr of elements already sorted
        cout << a[i] << endl;
    }
    cout << "Best case" << endl; // Because the numbers are in order is the best case

}

int main()
{
    srand(time(0)); // To generate new numbers each time we run the program

    int size;
    cout << "How many elements you want to sort?" << endl;
    cin >> size;
    int *array = new int[size]; // Creating the array with the desired number of elements

    for(int i=0; i<1; i++)
    {
    average(array,size); // Using this for the average case
    //worst(array,size); // Using this for the worst case
    //best(array,size); // Using the best case


        int start_s = clock(); // Function to measure the time of sorting in increasing order

        for(int i=0; i<size; i++) // Sorting the numbers
        {
            for(int j=i+1; j<size; j++)
            {
                if(array[i]>array[j])
                {
                    int max = array[i];
                    array[i] = array[j];
                    array[j] = max; // Swapping the values; Could also use swap() function
                }
            }
        }
            for(int i=0; i<size; i++)
            {
                cout << array[i] << " "; // Printing the numbers in order
            }
            cout << endl;

            int stop_s = clock(); // Function for the measure of time
            cout << "Time taken: "
                 << (stop_s - start_s)/double(CLOCKS_PER_SEC) << " seconds" << endl; // Print the time
}
        delete [] array;
        return 0;
    }

    /*
    I generated the random numbers via the function in c++ rand()
    In this way I get the array filled with random values between 0 and 99 (in my case)
    By calling the functions one by one I was able to measure the time and I left them as comment
    as we cannot use them at the same time.
    */
