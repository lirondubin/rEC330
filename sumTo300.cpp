#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;

int sumTo330(vector<int> nums)
{
    int closeUnder = 0;
    int closeOver = 0;
    int money = 0;
    int tempClose = 0;

    // 3 for loops will run through the vec in algorithmic fashion
    for (int first = 0; first < nums.size() - 2; first++)
    {
        for (int second = first + 1; second < nums.size() - 1; second++)
        {
            for (int third = second + 1; third < nums.size(); third++)
            {
                tempClose = nums[first] + nums[second] + nums[third];
                if (tempClose == 300)
                {
                    money = 300;
                    cout << "The answer is " << money << endl;
                    return money;
                }
                else if (tempClose > 300 && (abs(tempClose-300) < abs(closeOver-300)))
                {
                    closeOver = tempClose;
                }
                else if (tempClose < 300 && (tempClose > closeUnder))
                {
                    closeUnder = tempClose;
                }
            }
        }
    }
    if (300 - closeUnder > closeOver - 300){
        return closeOver;
    }
    else{
        return closeUnder;
    }
}

int main()
{
    vector<int> nums{100, 90, 70, 150};
    int sum = sumTo330(nums);
    cout << "The sum is " << sum << endl;
}
