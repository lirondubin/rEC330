#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;

int sumTo330(vector<int> nums)
{
    //sort(nums.begin(), nums.end());
    //for (int i = 0; i < nums.size(); ++i)
    //    cout << tempec[i] << " ";
    //int length = nums.size();
    //cout << nums[length]+nums[length-1]+nums[length-2] << endl;
    int closeUnder = 0;
    int closeOver = 0;
    //int closeOver = nums[length]+nums[length-1]+nums[length-2];
    int money = 0;
    int tempClose = 0;
    // for loop will run through the vec
///*

    for (int first = 0; first < nums.size() - 2; first++)
    {
        //cout << "first = " << first << endl;
        for (int second = first + 1; second < nums.size() - 1; second++)
        {
            //cout << "first = " << first << endl;
            //cout << "second = " << second << endl;
            for (int third = second + 1; third < nums.size(); third++)
            {
                cout << "first = " << first << endl;
                cout << "second = " << second << endl;
                cout << "third = " << third << endl;
                tempClose = nums[first] + nums[second] + nums[third];
                cout << "nums[first] = " << nums[first] << endl;
                cout << "nums[second] = " << nums[second] << endl;
                cout << "nums[third] = " << nums[third] << endl;
                cout << "tempClose = " << tempClose << endl;
                cout << endl;
                if (tempClose == 300)
                {
                    money = 300;
                    cout << "The answer is " << money << endl;
                    return money;
                }
                //else if (tempClose > 300 && (tempClose - 300 < closeOver - 300))
                else if (tempClose > 300 && (abs(tempClose-300) < abs(closeOver-300)))
                {
                    closeOver = tempClose;
                    //cout << "in closeOver = " << tempClose << endl;
                }
                // else if (tempClose < 300 && (300 - tempClose < 300 - closeUnder))
                else if (tempClose < 300 && (tempClose > closeUnder))
                {
                    closeUnder = tempClose;
                    //cout << "in closeUnder = " << closeUnder << endl;
                }
                else
                {
                    const char *baboon = "Big Baboon";
                }
            }
        }
    }

    cout << "closeUnder = " << closeUnder << endl;
    cout << "closeOver = " << closeOver << endl;

    if (300 - closeUnder > closeOver - 300){
        cout << "The answer is " << closeOver << endl;
        return closeOver;
    }
        
    else{
        cout << "The answer is " << closeUnder << endl;
        return closeUnder;
    }
        

    //*/

   return 0;
}

int main()
{
    vector<int> nums{100, 90, 70, 150};
    sumTo330(nums);
}
