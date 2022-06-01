#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    int n, a;
    std::vector<int> data;
    std::vector<int> sum_data;
    cin >> n;
    //������ �Է�
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        data.push_back(a);
    }
    // sort�Լ��� �̿��ؼ� vector���� ���� �������� ����
    sort(data.begin(), data.end());
    int sum(0);
    // ������ ���� ���������� �� �ϳ��� vector�� ����
    for (auto& d : data)
    {
        sum += d;
        sum_data.push_back(sum);
    }
    //accumulate �Լ��� ����ϸ� vector���� ������ ���� ���� �� �ִ�. ����° ���ڴ� sum�� default ���̴�. 0 + vector�� ��
    sum = std::accumulate(sum_data.begin(), sum_data.end(), 0);

    cout << sum;

    return 0;
}