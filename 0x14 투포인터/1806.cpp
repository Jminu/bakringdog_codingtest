//BOJ 1806 �κ���
#include <iostream>
using namespace std;

int get_sum(int start, int end);
int func(int sum);

int n;
int s;
int arr[100001];

int func(int sum)
{
    int st = 0;
    int en = 0;
    int arr_len = n + 1; //���� �κм����� ���̴� n�̴�.
    int total = arr[0];

    for (st = 0; st < n; st++)
    {
        while (en < n && total < sum) //en�� ������ ���� �ʰ�, ������ �κ����� s�� ���� ������
        {
            en++;
            if (en != n)
                total += arr[en];
        }
        if (en == n) //���� en�� ������ �ٴٸ��� ����
            break;
        arr_len = min(arr_len, en - st + 1);
        total -= arr[st];
    }

    if (arr_len == n + 1)
        return 0;
    return arr_len;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int min_arr_len = func(s);
    cout << min_arr_len;
}
