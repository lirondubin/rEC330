#include <iostream>
#include <cstring>

using std::cout;
using std::memset;

unsigned long genA(int n)
{
	/* your code here */
	return 0; /* don't forget to change the return value */
}

int main()
{
	int A1 = 1, A2 = 1;
	int n = 4;
	int tracker[n];
	memset(tracker, 0, sizeof(int) * n);
	tracker[0] = 1;
	tracker[1] = 1;
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
		for (int i = 0; i < n; i++)
		{
			runSUM = runSUM + (tracker[i] * tracker[n - 2 - i]);
			// tracker
			cout << "i = " << i << "\n";
			cout << "tracker[i] = " << tracker[i] << "\n";
			cout << "tracker[n - 2 - i] = " << tracker[n - 2 - i] << "\n";
			cout << "runSUM = " << runSUM << "\n";

			if (n - 2 - i == 0)
			{
				// cout << runSUM;
				return runSUM;
			}
		}
	}
}