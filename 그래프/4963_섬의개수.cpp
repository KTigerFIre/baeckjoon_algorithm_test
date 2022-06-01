#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int m[51][51];
bool visited[51][51];

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };


void bfs(int i, int j, int w, int h)
{
	queue<pair<int,int>> q;

	q.push(make_pair(i, j));
	visited[i][j] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k++)
		{
			int d_x = x + dx[k];
			int d_y = y + dy[k];

			if (0 <= d_x && d_x < h && 0 <= d_y && d_y < w)
			{
				if (visited[d_x][d_y] == false && m[d_x][d_y] == 1)
				{
					q.push(make_pair(d_x, d_y));
					visited[d_x][d_y] = true;
				}
			}
		}
	}


}

int main()
{
	int w, h;
	vector<int> ans;

	while (true)
	{
		cin >> w >> h;

		if (w == 0 && h == 0)
		{
			break;
		}
		int cnt(0);
		memset(m, 0, sizeof(m));
		memset(visited, false, sizeof(visited));

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> m[i][j];
			}
		}


		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (visited[i][j] == false && m[i][j] == 1)
				{
					cnt++;
					bfs(i, j, w, h);
				}
			}
		}
		
		ans.push_back(cnt);
	}

	for (auto n : ans)
	{
		cout << n << endl;
	}

	return 0;
}
