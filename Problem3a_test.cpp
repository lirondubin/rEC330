#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
int b_counter = 0;
int c_counter = 0;
int reset_counter = 0;

int countOOO(std::vector<std::string> rankedListA, std::vector<std::string> rankedListB);
void mergeSort(vector<int> Bint, int l, int r);
void merge(vector<int> Bint, int p, int q, int r);

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
    return b_counter;
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
    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            Bint[k] = L[i];
            i++;
        }
        else
        {
            Bint[k] = M[j];
            j++;
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
    }
    while (j < n2)
    {
        Bint[k] = M[j];
        j++;
        k++;
    }
    if (t_counter > 2)
    {
        c_counter = c_counter + tc_counter;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(vector<int> Bint, int l, int r)
{
    // int counter;
    if (l < r)
    {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;
        mergeSort(Bint, l, m);
        mergeSort(Bint, m + 1, r);
        merge(Bint, l, m, r);
    }
}

int main()
{
    int expected;

    // vector<int> Bint = {6, 5, 12, 10, 9, 1}; // expected = 9;
    // excpected = 9;

    // vector<int> Bint = {4, 2, 3, 1}; // expected = 4
    // expected = 4;

    // vector<int> Bint = {4, 2, 1, 3}; // expected = 3;
    // expected = 3;

    // vector<int> Bint = {3, 1, 2, 4}; // expected = 2;
    // expected = 2;

    // vector<int> Bint = {1,2,3}; / expected = 0;
    // expected = 0;

    // vector<int> Bint = {2, 1}; // expected = 1;
    // expected = 1;

    // vector<int> Bint = {2}; expected = 0
    // expected = 0;

    vector<std::string> rankedListA = {"E", "G", "S"};
    vector<std::string> rankedListB = {"S", "E", "G"};
    expected = 2;

    // vector<std::string> rankedListA = {"S", "E", "G"};
    // vector<std::string> rankedListB = {"S", "E", "G"};
    // expected = 0;

    // vector<string> rankedListA = {"A", "Q", "B", "CDR"};
    // vector<string> rankedListB = {"Q", "A", "CDR", "B"};

    int tot = countOOO(rankedListA, rankedListB);
    cout << "tot = " << tot << endl;
    return 0;

    // int size = Bint.size();
    // mergeSort(Bint, 0, size - 1);
    // int tot = c_counter + b_counter;
    // cout << "tot = " << tot << endl;
    // return 0;
}