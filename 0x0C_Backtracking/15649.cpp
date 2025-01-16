#include <iostream>
using namespace std;

int n;
int m;
int arr[9] = { 0 };
bool is_used[9] = { false };

void func(int k) {
	if (k == m + 1) {
		for (int i = 1; i <= m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (is_used[i] != true) {
			arr[k] = i;
			is_used[i] = true;
			func(k + 1);
			is_used[i] = false;
		}
	}
}


//1~n까지 수 중에서, 중복없이 m개를 뽑아서 수열을 구성한다
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	func(1);
}