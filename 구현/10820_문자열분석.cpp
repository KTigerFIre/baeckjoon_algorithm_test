#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	//lower , larger, num, ฐ๘น้
	string s;
	vector<int> cnt_bank;

	while (getline(cin,s))
	{
		int digit_cnt(0);
		int low_letter_cnt(0);
		int cap_letter_cnt(0);
		int space_cnt(0);

		for (auto c : s)
		{
			if (isdigit(c))
			{
				digit_cnt++;
			}
			else if (isalpha(c))
			{
				if (islower(c))
				{
					low_letter_cnt++;
				}
				else
				{
					cap_letter_cnt++;
				}
			}
			else
			{
				space_cnt++;
			}
		}



		cout << low_letter_cnt << " " << cap_letter_cnt << " " << digit_cnt << " " << space_cnt << endl;




	}


}
