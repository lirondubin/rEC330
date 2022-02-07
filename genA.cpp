#include <iostream>
#include <cstring>

using std::cout;
using std::memset;

unsigned long genA(int n)
{
	int A[n];
	memset(A, 0, sizeof(int) * n);
	A[0] = 1;
	A[1] = 1;
	unsigned long runSUM = 0;
	unsigned long totSUM = 0;

	if (n == 1)
	{
		cout << 1;
		return 1;
	}
	else if (n == 2)
	{
		cout << 1;
		return 1;
	}
	else
	{
		for (int temp_n = 2; temp_n < n; temp_n++)
		{
			for (int i = 0; i < temp_n; i++)
			{
				runSUM = runSUM + (A[i] * A[temp_n - 1 - i]);
				if (temp_n - 1 - i == 0)
				{
					A[temp_n] = runSUM;
					runSUM = 0;
				}
			}
			totSUM = A[temp_n];
		}
	}
	// cout << totSUM;
	return totSUM;
}