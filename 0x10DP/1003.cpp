#include <iostream>
using namespace std;

int t;
int n;

int DP[41][2];

void DPing()
{
    DP[0][0] = 1;
    DP[0][1] = 0;

    DP[1][0] = 0;
    DP[1][1] = 1;

    for (int i = 2; i <= 40; i++)
    {
        DP[i][0] = DP[i - 1][0] + DP[i - 2][0];
        DP[i][1] = DP[i - 1][1] + DP[i - 2][1];
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    DPing();
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << DP[n][0] << ' ' << DP[n][1] << '\n';
    }
}
