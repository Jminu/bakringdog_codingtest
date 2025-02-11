//BOJ 1806 부분합
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
    int arr_len = n + 1; //최장 부분수열의 길이는 n이다.
    int total = arr[0];

    for (st = 0; st < n; st++)
    {
        while (en < n && total < sum) //en이 끝까지 가지 않고, 수열의 부분합이 s를 넘지 않을때
        {
            en++;
            if (en != n)
                total += arr[en];
        }
        if (en == n) //만약 en이 끝까지 다다르면 종료
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
