#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

long test_case[101][101] = { 0 };


bool check(int i, int j, int n)
{
	return (i >= 0 && i < n&& j >= 0 && j < n);
}


int main()
{
	int n;
	int test_cnt(0);
	int cnt(0);
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		else
		{
			test_cnt++;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> test_case[i][j];
			}
		}
		long max_val = -987654321;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				//shape 1 straight tetromino/I �۴�� 2���� ���¸� ���� �� �ִ�.
				if (check(i,j+3,n))
					max_val = max(max_val, test_case[i][j] + test_case[i][j + 1] + test_case[i][j + 2] + test_case[i][j + 3]);
				if (check(i+3, j, n))
					max_val = max(max_val, test_case[i][j] + test_case[i + 1][j] + test_case[i + 2][j] + test_case[i + 3][j]);


				// shape 2 skew tetromino/Z �� skew tetromino/S�� ������ �ٸ��� shape2�� Z�̴�
				/*
				1100
				0110
				*/
				if (check(i + 1, j + 2, n))
					max_val = max(max_val, test_case[i][j] + test_case[i][j + 1] + test_case[i + 1][j + 1] + test_case[i + 1][j + 2]);
				/*
				0100
				1100
				1000
				*/
				if (check(i + 2, j - 1, n))
					max_val = max(max_val, test_case[i][j] + test_case[i + 1][j] + test_case[i + 1][j - 1] + test_case[i + 2][j - 1]);

				//shape3 J�̳�  '��' �� 4���� ���¸� ������.
				/*
				1110
				0010
				0000
				*/
				if (check(i + 1, j + 2, n))
					max_val = max(max_val, test_case[i][j] + test_case[i][j + 1] + test_case[i][j + 2] + test_case[i + 1][j + 2]);

				/*
				0100
				0100
				1100
				*/
				if (check(i + 2, j - 1, n))
					max_val = max(max_val, test_case[i][j] + test_case[i + 1][j] + test_case[i + 2][j - 1] + test_case[i + 2][j]);

				/*
				1000
				1110
				0000
				*/
				if (check(i + 1, j + 2, n))
					max_val = max(max_val, test_case[i][j] + test_case[i + 1][j] + test_case[i + 1][j + 1] + test_case[i + 1][j + 2]);

				/*
				1100
				1000
				1000
				*/
				if (check(i + 2, j + 1, n))
					max_val = max(max_val, test_case[i][j] + test_case[i][j + 1] + test_case[i + 1][j] + test_case[i + 2][j]);


				//shape4 T�̳� 

				/*
				1110
				0100
				0000
				*/
				if (check(i + 1, j + 2, n))
					max_val = max(max_val, test_case[i][j] + test_case[i][j + 1] + test_case[i][j + 2] + test_case[i + 1][j + 1]);
				/*
				0100
				1100
				0100
				*/
				if (check(i + 2, j - 1, n))
					max_val = max(max_val, test_case[i][j] + test_case[i + 1][j - 1] + test_case[i + 1][j] + test_case[i + 2][j]);
				/*
				0100
				1110
				0000
				*/
				if (check(i + 1, j - 1, n) && check(i + 1, j + 1, n))
					max_val = max(max_val, test_case[i][j] + test_case[i + 1][j - 1] + test_case[i + 1][j] + test_case[i + 1][j + 1]);

				/*
				0100
				0110
				0100
				*/
				if (check(i + 2, j + 1, n))
					max_val = max(max_val, test_case[i][j] + test_case[i + 1][j] + test_case[i + 1][j + 1] + test_case[i + 2][j]);

				//shpae 5 square tetromino/O ������� 1���� �����ۿ� ����
				if (check(i + 1, j + 1, n))
					max_val = max(max_val, test_case[i][j] + test_case[i][j +1] + test_case[i+1][j] + test_case[i + 1][j + 1]);
			}
		}

		cout <<test_cnt << ". " << max_val <<endl;
	}


	return 0;
}