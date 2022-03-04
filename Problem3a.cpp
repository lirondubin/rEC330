#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
int Gcounter = 0;
int c_counter = 0;
int reset_counter = 0;

void printArray(vector<int> *Bint, int size);
void mergeSort(vector<int> *Bint, int l, int r);
void merge(vector<int> *Bint, int p, int q, int r);

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
        cout << "Bint[i] = " << Bint[i] << endl;
    }

    // This section does the good stuff and solves the mystery
    int size = rankedListB.size();
    mergeSort(Bint, 0, size - 1);
    cout << "Sorted array: \n";
    printArray(Bint, size);
    int tot = c_counter + Gcounter;
    cout << "tot = " << tot << endl;
    return tot;
}

// Merge two subarrays L and M into arr
void merge(vector<int> Bint, int p, int q, int r)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

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
            Gcounter++;
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
        if (n1 != 2)
        {
            c_counter++;
        }
    }
    while (j < n2)
    {
        Bint[k] = M[j];
        j++;
        k++;
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

        // Merge the sorted subarrays
        merge(Bint, l, m, r);
        cout << "final c_counter = " << c_counter << endl;
    }
}

// Print the array
void printArray(vector<int> Bint, int size)
{
    for (int i = 0; i < size; i++)
        cout << Bint[i] << " ";
    cout << endl;
}


int main()
{

    vector<string> rankedListA = {"A", "Q", "B", "CDR"};
    vector<string> rankedListB = {"Q", "A", "CDR", "B"};
    countOOO(rankedListA, rankedListB);
    return 0;

    // int counter;

    // vector<string> rankedListA = {"A", "Q", "B", "CDR"};
    // vector<string> rankedListB = {"Q", "A", "CDR", "B"};

    /* You used brackets [] insteas of parenthesis () here when specifying the size */
    /*
    vector<int> Bint(rankedListB.size());
    map<string, int> songMap;
    for (int i = 0; i < rankedListA.size(); i++)
    {
        songMap.insert(pair<string, int>(rankedListA[i], i + 1));
    }

    map<string, int>::iterator itr;
    cout << "\nThe map songMap is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = songMap.begin(); itr != songMap.end(); ++itr)
    {
        cout << '\t' << itr->first << '\t' << itr->second << '\n';
    }
    cout << endl;
    for (int i = 0; i < rankedListB.size(); i++)
    {
        string temp = rankedListB[i];
        cout << typeid(songMap[temp]).name() << endl;
        cout << "songMap[temp] = " << songMap[temp] << endl;
        Bint[i] = songMap.at(temp);
        cout << "Bint[i] = " << Bint[i] << endl;
    }

    // vector<int> rankedListB = {6, 5, 12, 10, 9, 1};
    // vector<int> rankedListB = {4, 2, 1, 3};

    int size = rankedListB.size();

    mergeSort(Bint, 0, size - 1);

    cout << "Sorted array: \n";
    printArray(Bint, size);
    int tot = c_counter + Gcounter;
    cout << "tot = " << tot << endl;
    return 0;

    * /
}