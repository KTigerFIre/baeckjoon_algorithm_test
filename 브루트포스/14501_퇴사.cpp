#include <iostream>

using namespace std;

int T[16];
int P[16];
int res;
//����� ���� ����
void solution(int dday, int sum, int day)
{
	if (day == dday)
	{
		//�ִ�
		if (res < sum)
		{
			res = sum;
		}
		return ;
	}

	//�Ұ���
	if (day > dday) return;

	//i�� : T[i]�� , P[i]��


	//����� ���Ѵ�
	solution(dday, sum, day + 1);

	//����� �Ѵ�
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