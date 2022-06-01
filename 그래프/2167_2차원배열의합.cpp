#include <iostream>
#include <vector>
using namespace std;

static int arr[90000]= { 0 };

int main()
{
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n, m , k;

	cin >> n >> m;

	for (int i = 0; i < n * m; i++)
	{
		cin >> arr[i];
	}


	//시작점 (i,j) 끝점 (x,y)
	int i, j, x, y;

	cin >> k;
	std::vector<int> results;
	for (int start = 0; start < k; start++)
	{
		cin >> i >> j >> x >> y;
		i--; j--; x--; y--;
		int sum(0);

		int start_point = m * (i) + j;
		int end_point = m * (x) + y;

		for (; start_point <= end_point; start_point++)
		{
			sum += arr[start_point];
		}

		results.push_back(sum);
	}

	for (auto& result : results)
	{
		cout << result << endl;
	}

	return 0;
}