#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::sort;

int sumTo330(vector<int> nums)
{
    int closeUnder = 0;
    int closeOver = 0;
    int money = 0;
    int tempClose = 0;
    int counter = 0;
    int numsLength = nums.size();
    cout << "nums.size() = " << nums.size() << endl;

    // 3 for loops will run through the vec in algorithmic fashion
    for (int first = 0; first < nums.size() - 2; first++)
    {
        for (int second = first + 1; second < nums.size() - 1; second++)
        {
            for (int third = second + 1; third < nums.size(); third++)
            {
                tempClose = nums[first] + nums[second] + nums[third];
                if (tempClose == 330)
                {
                    money = 330;
                    return money;
                }
                else if (tempClose > 330 && (abs(tempClose - 330) < abs(closeOver - 330)))
                {
                    closeOver = tempClose;
                }
                else if (tempClose < 330 && (abs(tempClose - 330) < abs(closeUnder - 330)))
                {
                    closeUnder = tempClose;
                    counter++;
                }
            }
        }
    }
    cout << "counter = " << counter << endl;
    if (counter == 0){
        cout << "\nArray before sorting using default sort is : " << endl;
        for (int i = 0; i < numsLength; i++){
                cout << nums[i] << " ";
            }
        sort(nums.begin(),nums.end());
        cout << "\nArray after sorting using default sort is : " << endl;
        for (int i = 0; i < numsLength; i++){
            cout << nums[i] << " ";
        }
        cout << endl;
        cout << "nums[numsLength-1] = " << nums[numsLength-1] << endl;
        cout << "nums[numsLength-2] = " << nums[numsLength-2] << endl;
        cout << "nums[numsLength-3] = " << nums[numsLength-3] << endl;
        int negSum = nums[numsLength-1] + nums[numsLength-2] + nums[numsLength-3];
        return negSum;
    }
    else if (abs(330 - closeUnder) > abs(330 - closeOver))
    {
        return closeOver;
    }
    else
    {
        return closeUnder;
    }
}

int main()
{
    vector<int> nums{-1, -1, -1, -1, -1231, -23, -23,-3432,-543,-23, -23, -43, -543};
    // vector<int> nums{100, 90, 80, 70};
    int theSum = sumTo330(nums);
    cout << theSum << endl;
}