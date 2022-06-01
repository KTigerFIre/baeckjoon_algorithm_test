#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 1 <= m,n <= 8
// check���� ���ڸ� ����ߴ��� ���ߴ��� ���θ� ����
bool check[9];
// X��° ������ ���ڸ� ����
int arr[9];
// X��°�� � ���ڰ� ���� ���ϴ� ��Ȱ
void sol(int index, int n, int m)
{
	// ��ǥ �Ϸ�
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	// ��ɷδ� 1,2 == 2,1 �����Ŵ� ���� ���� dfs�� ���� 
	for (int i = 1; i <= n; i++)
	{
		if (check[i]) continue;
		check[i] = true; 
		arr[index] = i; // arr[index]�� �Ź� ���� �ɰ��̴�.
		sol(index + 1, n, m);
		// index == m�� �����Ͽ� Ż���ϸ�, �ٽ� ��� check�� false�� ������ش�.
		check[i] = false; // ��Ʈ��ŷ
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