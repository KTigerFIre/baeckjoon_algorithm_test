#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
int arr[501][501] = { 0 };

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int n;

	cin >> n;
	
	cin >> arr[1][1];

	int max_v = arr[1][1];
	int tmp;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> tmp;

			if (j == 1)
			{
				arr[i][j] = tmp + arr[i - 1][j];
			}
			else if (j == i)
			{
				arr[i][j] = tmp + arr[i - 1][j - 1];
			}
			else
			{
				arr[i][j] = tmp + max(arr[i - 1][j], arr[i - 1][j - 1]);
			}

			if (i == n)
			{
				max_v = max(max_v, arr[i][j]);
			}

		}
	}

	cout << max_v;
	return 0;
}