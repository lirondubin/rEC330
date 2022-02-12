#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cout;
using std::endl;
using std::sort;
using std::vector;

int sumTo330(vector<int> nums)
{
    int closeUnder = 0;
    int closeOver = 0;
    int money = 0;
    int tempClose = 0;
    int counter = 0;
    int numsLength = nums.size();

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
    if (counter == 0)
    {
        sort(nums.begin(), nums.end());
        int negSum = nums[numsLength - 1] + nums[numsLength - 2] + nums[numsLength - 3];
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