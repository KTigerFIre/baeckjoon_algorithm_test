#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	string s;
	cin >> n;
	vector<string> table;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		table.push_back(s);
	}
	int row_cnt(0);
	for (int i = 0; i < n; i++)
	{
		std::string tmp_s;
		for (int j = 0; j < n; j++)
		{
			auto c = table[i][j];

			if (c == '.')
			{
				tmp_s.push_back(c);
			}
			else if (c == 'X')
			{
				if (tmp_s.size() > 1)
				{
					row_cnt++;
					
				}
				tmp_s.clear();
			}
		}

		if (tmp_s.size() > 1)
		{
			row_cnt++;
		}
	}

	int col_cnt(0);
	for (int i = 0; i < n; i++)
	{
		std::string tmp_s;
		for (int j = 0; j < n; j++)
		{
			auto c = table[j][i];

			if (c == '.')
			{
				tmp_s.push_back(c);
			}
			else if (c == 'X')
			{
				if (tmp_s.size() > 1)
				{
					col_cnt++;
				}
				tmp_s.clear();
			}
		}

		if (tmp_s.size() > 1)
		{
			col_cnt++;
		}
	}

	cout << row_cnt << " " << col_cnt;

	return 0;
}