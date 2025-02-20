#include <iostream>
using namespace std;

int DP[301] = { 0 };
int stairs[301] = { 0 };
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> stairs[i];
    }

    DP[0] = 0;
    DP[1] = stairs[1];
    DP[2] = stairs[1] + stairs[2];

    if (n == 1)
        cout << DP[1];
    else if (n == 2)
        cout << DP[2];
    else {
        for (int i = 3; i <= n; i++)
        {
            DP[i] = max(DP[i - 3] + stairs[i - 1] + stairs[i], DP[i - 2] + stairs[i]);
        }
        cout << DP[n];
    }
}
