#include <iostream>
#include <cstring>

using std::cout;
using std::memset;

char findOdd(char arr[], int arr_size)
{
    // const char* error = "Error, please enter new characters.";
    int error = 0;
    int char_count[26];
    memset(char_count, 0, sizeof(int) * 26);
    for (int i = 0; i < arr_size; i++)
    {
        char_count[(int)arr[i] - 97] = char_count[(int)arr[i] - 97] + 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (char_count[i] % 2 != 0)
        {
            int val = i + 97;
            char ret_char = (char)val;
            // cout << ret_char;
            return ret_char;
        }
    }
    return error;
}