#include <iostream>
using namespace std;

int N;
bool ad_matrix[101][101];
bool ans_arr[101][101];
bool vis[101] = { false };

void bool_zero() {
	for (int i = 0; i < N; i++) {
		vis[i] = false;
	}
}

void dfs(int start) {
	for (int i = 0; i < N; i++) {
		if (vis[i] == false && ad_matrix[start][i] == true) {
			vis[i] = true;
			dfs(i);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ad_matrix[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		bool_zero();
		dfs(i);

		for (int j = 0; j < N; j++) {
			if (vis[j] == true) {
				ans_arr[i][j] = true;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans_arr[i][j] << ' ';
		}
		cout << '\n';
	}
}