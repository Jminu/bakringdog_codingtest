#include <iostream>
using namespace std;

int n;
int arr[1001] = { 0 };
int DP[1001] = { 0 };

int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		DP[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j])
				DP[i] = max(DP[i], DP[j] + 1);
	}

	int result = DP[0];
	for (int i = 0; i < n; i++) {
		if (result < DP[i])
			result = DP[i];
	}

	cout << result;
}