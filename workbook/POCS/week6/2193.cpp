#include <iostream>
using namespace std;

long long int DP[91];
int n;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	DP[1] = 1;
	DP[2] = 1;
	
	for (int i = 3; i <= n; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	cout << DP[n];
}