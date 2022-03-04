#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
int b_counter = 0;
int c_counter = 0;

void printArray(vector<int> *Bint, int size);
void mergeSort(vector<int> *Bint, int l, int r);
void merge(vector<int> *Bint, int p, int q, int r);
int countOOO(std::vector<std::string> rankedListA, std::vector<std::string> rankedListB);

// countOOO computes the number of pairs of elements in rankedListA that are out of order in rankedListB

int countOOO(std::vector<std::string> rankedListA, std::vector<std::string> rankedListB)
{
    // This section uses a MAP to convert the vec strings to a vec of ints
    vector<int> Bint(rankedListB.size());
    map<string, int> songMap;
    for (int i = 0; i < rankedListA.size(); i++)
    {
        songMap.insert(pair<string, int>(rankedListA[i], i + 1));
    }
    map<string, int>::iterator itr;
    for (int i = 0; i < rankedListB.size(); i++)
    {
        string temp = rankedListB[i];
        Bint[i] = songMap.at(temp);
    }

    // This section does the good stuff and solves the mystery
    int size = Bint.size();
    mergeSort(Bint, 0, size - 1);
    int tot = b_counter + c_counter;

    return tot;
}

// Merge two subarrays L and M into arr
void merge(vector<int> Bint, int p, int q, int r)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], M[n2];
    int t_counter = 0;
    int tc_counter = 0;

    for (int i = 0; i < n1; i++)
        L[i] = Bint[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = Bint[q + 1 + j];

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
            Bint[k] = L[i];
            i++;
            // cout << "a" << endl;
        }
        else
        {
            Bint[k] = M[j];
            j++;
            // cout << "b" << endl;
            b_counter++;
            t_counter++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        Bint[k] = L[i];
        i++;
        k++;
        t_counter++;
        tc_counter++;
        // cout << "c" << endl;
        // cout << "r-p = " << r - q << endl;
        // cout << "n1 = " << n1 << endl;
        // cout << "t_counter = " << t_counter << endl;
    }
    while (j < n2)
    {
        Bint[k] = M[j];
        j++;
        k++;
        // cout << "d" << endl;
    }
    if (t_counter > 2)
    {
        c_counter = c_counter + tc_counter;
    }
}

/*
// Print the array
void printArray(vector<int> Bint, int size)
{
    for (int i = 0; i < size; i++)
        cout << Bint[i] << " ";
    cout << endl;
}
*/

int main()
{

    // vector<std::string> rankedListA = {"E", "G", "S"};
    // vector<std::string> rankedListB = {"S", "E", "G"};
    vector<string> rankedListA = {"A", "Q", "B", "CDR"};
    vector<string> rankedListB = {"Q", "A", "CDR", "B"};
    int tot = mergeSort(Bint, 0, size - 1);
    cout << "tot = " tot << endl;
    return 0;

    // vector<int> Bint = {3,1,2,4};

    /*
    vector<int> Bint(rankedListB.size());
    map<string, int> songMap;
    for (int i = 0; i < rankedListA.size(); i++)
    {
        songMap.insert(pair<string, int>(rankedListA[i], i + 1));
    }
    map<string, int>::iterator itr;
    for (int i = 0; i < rankedListB.size(); i++)
    {
        string temp = rankedListB[i];
        Bint[i] = songMap.at(temp);

        cout << "typeid(Bint[i]).name() = " << typeid(Bint[i]).name() << endl;
        // cout << "typeid(hello[i]).name() = " << typeid(hello[i]).name() << endl;
    }

    cout << "typeid(Bint).name() = " << typeid(Bint).name() << endl;
    // cout << "typeid(hello).name() = " << typeid(hello).name() << endl;
    */

    /*
     // vector<int> Bint = {6, 5, 12, 10, 9, 1};
     // vector<int> Bint = {2,1};
     // vector<int> Bint = {2};
     // vector<int> Bint = {4, 2, 1, 3};
     vector<int> Bint = {4, 1, 2};
     // vector<int> Bint = {3,1,2,4};

     // This section does the good stuff and solves the mystery
     int size = Bint.size();
     mergeSort(Bint, 0, size - 1);
     int tot;
     cout << "Sorted array: \n";
     printArray(Bint, size);
     cout << "total b_counter = " << b_counter << endl;
     cout << "total c_counter = " << c_counter << endl;
     tot = b_counter + c_counter;
     cout << "tot = " << tot << endl;
     return 0;
     */
}