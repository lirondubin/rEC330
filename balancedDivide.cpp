#include "balancedDivide.h"

using namespace std;

Assignment computation(const vector<int> &birthdays, vector<int> ga, vector<int> gb, int i, int sumA, int sumB);

Assignment balancedDivide(vector<int> const &birthdays)
{
    return computation(birthdays, {}, {}, 0, 0, 0);
}

Assignment computation(const vector<int> &birthdays, vector<int> ga, vector<int> gb, int i, int sumA, int sumB)
{
    int totalBirthdays = birthdays.size();
    if (i == totalBirthdays)
    {
        return Assignment(abs(sumA - sumB), ga, gb);
    }

    int birthday_a = birthdays[i];
    ga.push_back(birthday_a);
    Assignment partition_ga = computation(birthdays, ga, gb, i + 1, sumA + birthdays[i], sumB);
    ga.pop_back();
    int birthday_b = birthdays[i];
    gb.push_back(birthday_b);
    Assignment partition_gb = computation(birthdays, ga, gb, i + 1, sumA, sumB + birthdays[i]);
    gb.pop_back();

    if (partition_ga.diff < partition_gb.diff)
    {
        return partition_ga;
    }
    else
    {
        return partition_gb;
    }
}