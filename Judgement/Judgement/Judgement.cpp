#include <iostream>
using namespace std;
int main()
{
	long int n, i, j, k, dp[100000], a[100000], m[100000];
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> k;
	dp[100000] = {0};
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < k; j++)
		{
			if (dp[j] >= 0)
			{
				dp[j] = m[i];
			}
			else
			{
				if ((j < a[i]) || (dp[j - a[i]] <= 0))
				{
					dp[j] = -1;
				}
				else
				{
					dp[j] = dp[j - a[i]] - 1;
				}
			}
		}
	}
	if (dp[k] >= 0)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
}