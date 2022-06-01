#include <iostream>
#include <cstring>
using namespace std;
const int MAX_CH = 500000*2;

const int START_CH = 100;
const int MAX_BUTTONS = 10;

bool buttons[10];


bool check(int ch, int &cnt)
{
	if (ch == 0)
	{
		if (buttons[0])
		{
			cnt++;
			return true;
		}
		else
		{
			return false;
		}	
	}

	while (ch > 0)
	{
		if (buttons[ch % 10] == false)
		{
			return false;
		}
		cnt++;
		ch /= 10;
	}

	return true;
}

int main()
{
	//n 목표 ch, m 고장난 버튼 개수
	int n, m;
	cin >> n >> m;
	
	memset(buttons, true, sizeof(buttons));

	
	for (int i = 0; i < m; i++)
	{
		int tmp_num;
		cin >> tmp_num;
		buttons[tmp_num] = false;
	}


	if (START_CH == n)
	{
		cout << 0;
		return 0;
	}

	if (MAX_BUTTONS == m)
	{
		cout << abs(n - START_CH);
		return 0;
	}
	int ans(abs(START_CH - n));
	for (int i = 0; i <= MAX_CH; i++)
	{
		int cnt(0);
		if (check(i, cnt))
		{
			int gap = abs(i - n);

			if (ans > cnt + gap)
			{
				ans = cnt + gap;
			}
		}
	}

	
	cout << ans;

	return 0;
}