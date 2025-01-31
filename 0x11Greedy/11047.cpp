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

    //N���� ������ ���� ��ġ�� ������������ �Է��Ѵ�.
    for (int i = 0; i < N; i++)
    {
        cin >> value_of_coin[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        if (K == 0)
            break;
        if (K >= value_of_coin[i]) //�����ִ� ���� ������ġ�� ���� ��ġ���� ũ�ٸ�
        {
            coin_cnt += K / value_of_coin[i]; //�� : ���� ��ġ�� ������ ����
            K %= value_of_coin[i]; //������ : ���� ��
        }
    }

    cout << coin_cnt;
}
