#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n =3, m =3;

int map[9][9] = { -1 };
int copy_map[9][9] = { -1 };
std::vector<int> no_walls;
std::vector<pair<int, int>> virus;
std::queue<pair<int,int>> q;
bool visited[9][9];

void bfs()
{
	memset(visited, false, sizeof(visited));
	for (auto& v : virus)
	{
		int i = v.first;
		int j = v.second;
		q.push(make_pair(i,j));
		visited[i][j] = true;

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (0 <= nx && nx < n && 0 <= ny && ny < m)
				{
					if (visited[nx][ny] == false && copy_map[nx][ny] == 0)
					{
						q.push(make_pair(nx, ny));
						visited[nx][ny] = true;
						copy_map[nx][ny] = 2;
					}
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	int color;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> color;
			map[i][j] = color;
			if (color == 0)
			{
				int v = i * m + j;
				no_walls.push_back(v);
			}
			else if (color == 2)
			{
				virus.push_back(make_pair(i,j));
			}
		}
	}

	vector<bool> combi(no_walls.size(),true);

	for (int i = 0; i < 3; i++)
	{
		combi[i] = false;
	}
	vector < vector<int>> combs;
	do
	{
		vector<int> comb;
		for (int i = 0; i < no_walls.size(); i++)
		{
			if (combi[i] == false)
			{
				comb.push_back(no_walls[i]);
			}
		}

		combs.push_back(comb);

	} while (next_permutation(combi.begin(), combi.end()));
	int res(0);
	for (auto& comb : combs)
	{
		copy(&map[0][0], &map[0][0] + 81, &copy_map[0][0]);
		for (auto& location : comb)
		{
			int i = location / m;
			int j = location % m;
			copy_map[i][j] = 1;
		}

		bfs();
		int cnt(0);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (copy_map[i][j] == 0)
					cnt++;
			}
		}

		res = max(res, cnt);		
	}

	cout << res;


	// combination 을 이용해서 빈칸들중 3개를 뽑아서 지도에 추가후 bfs를 수행 








}