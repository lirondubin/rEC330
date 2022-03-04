#include <iostream>
#include <vector>
//#include "problem3a.h"

using namespace std;
int b_counter = 0;
int c_counter = 0;
int reset_counter = 0;

void printArray(int *arr[], int size);
void mergeSort(int *arr[], int l, int r);
void merge(int *arr[], int p, int q, int r);

// countOOO computes the number of pairs of elements in rankedListA that are out of order in rankedListB
/*int countOOO(std::vector<std::string> rankedListA, std::vector<std::string> rankedListB)
{
    int size = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);
    // cout << "Sorted array: \n";
    return b_counter; // don't forget to change this
}*/

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];
    int t_counter = 0;
    int tc_counter = 0;

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    // int counter = 0;
    cout << endl;
    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
            cout << "a" << endl;
            // b_counter++;
        }
        else
        {
            arr[k] = M[j];
            j++;
            cout << "b" << endl;
            b_counter++;
            t_counter++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
        t_counter++;
        tc_counter++;
        /*if ((n1) > 2)
        {
            c_counter++;
        }*/
        cout << "c" << endl;
        cout << "r-p = " << r - q << endl;
        cout << "n1 = " << n1 << endl;
        cout << "t_counter = " << t_counter << endl;
    }
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
        // b_counter++;
        cout << "d" << endl;
    }
    if (t_counter > 2)
    {
        c_counter = c_counter + tc_counter;
    }

    cout << "tc_counter = " << tc_counter << endl;
    cout << "b_counter = " << b_counter << endl;
    cout << "c_counter = " << c_counter << endl;
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r)
{
    // int counter;
    if (l < r)
    {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

// Print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    // int counter;
    // int arr[] = {6, 5, 12, 10, 9, 1};
    // int arr[] = {4, 2, 3, 1};
    // int arr[] = {4, 2, 1, 3};
    // int arr[] = {3, 1, 2, 4};
    // int arr[] = {4, 1, 2};
    // int arr[] = {2, 1};
     int arr[] = {2};
    
    


    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: \n";
    printArray(arr, size);
    // cout << "counter = " << counter << endl;
    int tot = c_counter + b_counter;
    cout << "tot = " << tot << endl;
    return 0;
}