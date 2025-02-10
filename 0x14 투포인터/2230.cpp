#include <iostream>
#include <algorithm>
using namespace std;

int n;
int m;
int a[100001];

int func(int target)
{
    int start = 1;
    int end = n;
    int pos = -1; //target���� ū ������ ���� ���� ������ ��ġ

    while (start <= end)
    {
        int mid = (start + end) / 2; //��� �������� ������.

        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] < target) //������ ����
        {
            start = mid + 1;
        }
        else //���� ����
        {
            pos = mid;
            end = mid - 1;
        }
    }
    return pos;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; //m: �� �� ���� ���̰� m�̻� �����Ѵ�.

    //������ �Է¹ް�
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    //������������ ����
    sort(a + 1, a + n + 1);

    int min_val = 2000000000;
    int pos = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] + m > a[n])
            continue;
        pos = func(a[i] + m);
        min_val = min(min_val, a[pos] - a[i]);
    }

    cout << min_val;
}
