#include <iostream>
using namespace std;

int N;
int value_of_coin[11] = { 0 };
int K;
int coin_cnt = 0;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    //N개의 동전에 대한 가치를 오름차순으로 입력한다.
    for (int i = 0; i < N; i++)
    {
        cin >> value_of_coin[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        if (K == 0)
            break;
        if (K >= value_of_coin[i]) //남아있는 돈이 현재위치한 돈의 가치보다 크다면
        {
            coin_cnt += K / value_of_coin[i]; //몫 : 현재 위치한 코인의 개수
            K %= value_of_coin[i]; //나머지 : 남은 돈
        }
    }

    cout << coin_cnt;
}
