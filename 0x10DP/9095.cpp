#include <iostream>
using namespace std;

int t;
int n;
int DP[12] = { 0 };

int dp(int num)
{
    for (int i = 4; i <= num; i++)
    {
        DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
    }
    return DP[num];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 4;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << dp(n) << '\n';
    }
}
