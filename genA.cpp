#include <iostream>
#include <cstring>
#include <math.h>

using std::cout;
using std::memset;

unsigned long genA(int n)
{
	/* your code here */
	return 0; /* don't forget to change the return value */
}

int main()
{
	// int A1 = 1, A2 = 1;
	int n = 4;
	int A[n];
	memset(A, 0, sizeof(int) * n);
	A[0] = 1;
	A[1] = 1;
	int runSUM = 0;

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
		// int temp_n = n - 2;

		for (int temp_n = 2; temp_n < n; temp_n++)
		{
			cout << "temp_n = " << temp_n << "\n";
			if (temp_n == 0)
			{
				A[temp_n] = 1;
			}
			else if (temp_n == 1)
			{
				A[temp_n] = 1;
			}
			else
			{
				for (int i = 0; i < temp_n; i++)
				{
					runSUM = runSUM + (A[i] * A[temp_n - 1 - i]);
					cout << "i = " << i << "\n";
					cout << "temp_n - 1 - i = " << temp_n - 1 - i << "\n";
					cout << "A[i] = " << A[i] << "\n";
					cout << "A[temp_n - 1 - i] = " << A[temp_n - 1 - i] << "\n";
					cout << "runSUM = " << runSUM << "\n";

					if (temp_n - 1 - i == 0)
					{
						A[temp_n] = runSUM;
						cout << "Val in A: " << A[temp_n] << "\n";
						// i = 0;
					}
				}
				cout << "A[temp_n] = " << A[temp_n] << "\n";
			}
			cout << "\n";
		}
	}
	cout << "runSUM = " << runSUM << "\n";
	return 0;
}