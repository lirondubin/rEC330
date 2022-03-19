#include <string>
#include <vector>
#include <iostream>
#include "sorta.h"

using namespace std;

string sortByFreq(string s) {
	
    vector<int> letter_counter(26,0);
    vector<int> temp_sorted(26,0);
    string sorted_back = "";
    string sorted_good = "";
    int length_s = s.size();

    for (int i = 0; i < length_s; i++){
        int converted = (int)s[i] - 97;
        letter_counter[converted] = letter_counter[converted] + 1;
    }
    for (int i = 0; i < 26; i++){
        int largest_val = 0;
        int largest_ind = 0;
        for (int j = 0; j < 26; j++){ 
            if (letter_counter[j] >= largest_val){
                largest_ind = j;
                largest_val = letter_counter[j];
            }
        }

        // cout << "largest_val: " << largest_val << endl;
        // cout << "largest_ind: " << largest_ind << endl;
        for(int k = 0; k < largest_val; k++){
            sorted_back = sorted_back + (char)(largest_ind+97);
        }
        // cout << sorted_back << endl;
        // cout << endl;
        letter_counter[largest_ind] = 0;
    }

    for (int i = length_s; i >= 0; i--){
        sorted_good = sorted_good + sorted_back[i];
    }
    cout << sorted_good << endl;    
    return sorted_good;
}

int main(){
    string test1 = "engineers"; // girsnneee
    string test2 = "engineering"; // rggiieeennn
    string test3 = "hello"; // eholl
    sortByFreq(test1);
    return 0;
}