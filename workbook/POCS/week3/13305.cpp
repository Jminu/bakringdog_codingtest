#include <iostream>
using namespace std;

int n; //���� ����
int m; //���ø� �����ϴ� ���μ�
long long int fuel_price[100001]; //�� ���ÿ��� �⸧��
long long int dist[100001]; //���λ����� �Ÿ�
long long int cost = 0;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n; //���� ��
    m = n - 1; //���� ��

    //���λ��� �Ÿ� �Է�
    for (long long int i = 0; i < m; i++)
    {
        cin >> dist[i];
    }

    //�⸧�� �Է�
    for (int i = 0; i < n; i++)
    {
        cin >> fuel_price[i];
    }

    //���� ������ ������
    long long int min_price = fuel_price[0];

    //�ʱ� �ʿ�ݾ�
    cost = fuel_price[0] * dist[0];

    for (int i = 1; i < n - 1; i++)
    {
        if (fuel_price[i] < min_price) //���� �����Ұ� �� �θ�
        {
            min_price = fuel_price[i]; //���� ������ �ֿ�� ��ü
            cost = cost + fuel_price[i] * dist[i];
        }
        else //���� �����Ұ� �� ��θ�
        {
            cost = cost + min_price * dist[i];
        }
    }

    cout << cost;
}
