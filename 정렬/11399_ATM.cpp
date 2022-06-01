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
    //데이터 입력
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        data.push_back(a);
    }
    // sort함수를 이용해서 vector안의 값을 오름차순 정렬
    sort(data.begin(), data.end());
    int sum(0);
    // 누적된 합을 순차적으로 또 하나의 vector에 저장
    for (auto& d : data)
    {
        sum += d;
        sum_data.push_back(sum);
    }
    //accumulate 함수를 사용하면 vector안의 숫자의 합을 얻을 수 있다. 세번째 인자는 sum의 default 값이다. 0 + vector의 합
    sum = std::accumulate(sum_data.begin(), sum_data.end(), 0);

    cout << sum;

    return 0;
}