#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 1 <= m,n <= 8
// check에는 숫자를 사용했는지 안했는지 여부를 저장
bool check[9];
// X번째 선택한 숫자를 저장
int arr[9];
// X번째에 어떤 숫자가 올지 정하는 역활
void sol(int index, int n, int m)
{
	// 목표 완료
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	// 요걸로는 1,2 == 2,1 같은거는 구분 못함 dfs와 유사 
	for (int i = 1; i <= n; i++)
	{
		if (check[i]) continue;
		check[i] = true; 
		arr[index] = i; // arr[index]는 매번 갱신 될것이다.
		sol(index + 1, n, m);
		// index == m을 만족하여 탈출하면, 다시 모든 check를 false로 만들어준다.
		check[i] = false; // 백트래킹
	}
}

void sol2(int n, int m)
{
	std::vector<int> numbers;
	std::vector<bool> permu(n,true);

	for (int i = 0; i < m; i++)
	{
		permu[i] = false;
	}

	for (int i = 1; i <= n; i++)
	{
		numbers.push_back(i);
	}
	vector<vector<int>> permutation_combs;
	do
	{
		vector<int> permutation_comb;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (permu[i] == false)
			{
				permutation_comb.push_back(numbers[i]);
			}
		}
		permutation_combs.push_back(permutation_comb);
	} while (next_permutation(permu.begin(), permu.end()));

	for (auto &comb : permutation_combs)
	{
		for (auto& num : comb)
		{
			cout << num << " ";
		}
		cout << "\n";
	}

}



int main()
{
	int n, m;
	cin >> n >> m;

	//sol(0, n, m);

	sol2(n, m);



}