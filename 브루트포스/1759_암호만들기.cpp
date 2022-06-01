#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
set<char> v_map = { 'a','e','i','o','u' };

solution(int n, string &alpha, i)

int main()
{
	int L, C;
	cin >> L >> C;

	std::string alps;

	char tmp;
	for (int i = 0; i < C; i++)
	{
		cin >> tmp;
		alps.push_back(tmp);
	}

	int max_v = L - 2;

	sort(alps.begin(), alps.end());

	
	set<string> set_passwords;
	for (auto& ch : v_map)
	{
		auto index = alps.find(ch);
		if (index == alps.npos) continue;

		auto tmp_alps = alps;
		tmp_alps.erase(index,1);
		// 모음은 반드시 한개 들어가니 순서대로 순회하며 L개의 암호중 1개를 제거하고 시작 (L-1)개의 조합만 생각한다.
		// max_v는 (L -1) 개에서 모음이 들어갈 수 있는 최대 가짓수, 자음은 최소 2개가 필요
		
		vector<bool> check((C - 1), true);

		for (int i = 0; i < L - 1; i++)
		{
			check[i] = false;
		}

		do
		{
			string password;
			password.push_back(ch);
			for (int i = 0; i < tmp_alps.size(); i++)
			{
				if (check[i] == false)
				{
					password.push_back(tmp_alps[i]);
				}
			}
			if (checkMaxV(password, max_v))
			{
				sort(password.begin(), password.end());
				set_passwords.insert(password);
			}

		} while (next_permutation(check.begin(),check.end()));


	}

	for (auto s : set_passwords)
	{

		cout << s <<endl;
	}


	return 0;
}