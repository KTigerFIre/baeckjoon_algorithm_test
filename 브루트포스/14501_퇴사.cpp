#include <iostream>

using namespace std;

int T[16];
int P[16];
int res;
//상담을 할지 말지
void solution(int dday, int sum, int day)
{
	if (day == dday)
	{
		//최댓값
		if (res < sum)
		{
			res = sum;
		}
		return ;
	}

	//불가능
	if (day > dday) return;

	//i일 : T[i]일 , P[i]일


	//상담을 안한다
	solution(dday, sum, day + 1);

	//상담을 한다
	solution(dday, sum + P[day], day + T[day]);


}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >>T[i] >> P[i];
	}

	solution(n + 1, 0, 1);
	cout << res;

}