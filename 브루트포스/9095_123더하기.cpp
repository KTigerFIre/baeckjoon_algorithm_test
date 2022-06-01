#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


// n일 경우 가지의 개수 저장
int dp[12] = {-1};

int solution(int n)
{
	if (dp[n] != -1)
	{
		return dp[n];
	}

	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}


	return dp[n];
}

int main()
{
	int T;

	memset(dp, -1, sizeof(dp));

	dp[0] = 0;
	dp[1] = 1; // 1
	dp[2] = 2; // (1 + 1), 2;
	dp[3] = 4; // (1 + 2).(2 + 1),(3), (1+1+1) ;


	cin >> T;
	std::vector<int> test_case;
	int s;
	for (int i = 0; i < T; i++)
	{
		cin >> s;
		test_case.push_back(s);
	}

	for (auto &n : test_case)
	{
		cout << solution(n) << endl;
	}


	return 0;
}


