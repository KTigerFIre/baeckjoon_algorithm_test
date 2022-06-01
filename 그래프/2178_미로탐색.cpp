#include <iostream>
#include <vector>
#include <queue>

using namespace std;


bool visited[101][101] = { false };

int dist[101][101] = { 0 };

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0};
int n, m;
queue<pair<int, int>> q;

vector<string> maze;

void bfs()
{
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	dist[0][0] = 1;


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
				if (visited[nx][ny] == false && maze[nx][ny] == '1')
				{
					q.push(make_pair(nx, ny));
					dist[nx][ny] = dist[x][y] + 1;
					visited[nx][ny] = true;
				}
			}

		}
	}
}

int main()
{
	

	cin >> n >> m;

	string s;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		maze.push_back(s);
	}

	bfs();

	cout << dist[n-1][m-1];


	return 0;

}