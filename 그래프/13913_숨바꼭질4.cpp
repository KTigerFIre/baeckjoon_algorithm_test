#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int walk[2] = { -1,1};
int n, k;

queue<int> q;

const int MAX = 200000;
bool visited[MAX+1];
int dist[MAX + 1];
int path[MAX+1];
int cnt = 0;
int minimum_time;
bool revisit;

void bfs()
{
	visited[n] = true;
	dist[n] = 0;
	path[n] = n;
	q.push(n);

	while (!q.empty())
	{
		int y = q.front();
		q.pop();
		if (y == k && !revisit)
		{
			minimum_time = dist[y];
			visited[y] = false;
			cnt++;
			revisit = true;
		}

		if (y == k && revisit)
		{
			if (minimum_time == dist[y])
			{
				cnt++;
				visited[y] = false;
			}
			else if (minimum_time < dist[y])
			{
				visited[y] = true;
				break;
			}
			else if (minimum_time > dist[y])
			{
				minimum_time = dist[y];
				cnt++;
				visited[y] = false;
			}
		}
			

		if (y - 1 >= 0)
		{
			if (visited[y - 1] == false)
			{
				q.push(y - 1);
				visited[y - 1] = true;
				dist[y - 1] = dist[y] + 1;
				path[y-1] = y;
				
			}
		}

		if (y + 1 < MAX)
		{
			if (visited[y + 1] == false)
			{
				q.push(y + 1);
				visited[y + 1] = true;
				dist[y + 1] = dist[y] + 1;
				path[y + 1] = y;

			}
		}

		if (y *2 < MAX)
		{
			if (visited[y * 2] == false)
			{
				q.push(y * 2);
				visited[y * 2] = true;
				dist[y * 2] = dist[y] + 1;
				path[y * 2] = y;

			}
		}


	}
}

int main()
{
	cin >> n >> k;
	bfs();
	cout << minimum_time << endl;
	
	cout << cnt;

}