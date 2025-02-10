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
    int pos = -1; //target보다 큰 원소중 가장 작은 원소의 위치

    while (start <= end)
    {
        int mid = (start + end) / 2; //계속 절반으로 나눈다.

        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] < target) //오른쪽 영역
        {
            start = mid + 1;
        }
        else //왼쪽 영역
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

    cin >> n >> m; //m: 고른 두 수의 차이가 m이상 나야한다.

    //수열을 입력받고
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    //오름차순으로 정렬
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
