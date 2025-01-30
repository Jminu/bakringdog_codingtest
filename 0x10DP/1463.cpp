#include <iostream>
using namespace std;

int N;
int DP[1000001];

int find_min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

void func(int k)
{
    DP[1] = 0;

    for (int i = 2; i <= k; i++)
    {
        DP[i] = DP[i - 1] + 1;
        if (i % 3 == 0)
        {
            DP[i] = find_min(DP[i], DP[i / 3] + 1);
        }
        if (i % 2 == 0)
        {
            DP[i] = find_min(DP[i], DP[i / 2] + 1);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    func(N);
    cout << DP[N];
}
