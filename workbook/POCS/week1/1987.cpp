#include <iostream>
#include <utility>
#include <stack>
using namespace std;

bool visited_alpha[26] = { false };
char board[20][20];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int max_count = 1;

void dfs(int x, int y, int R, int C, int length) {
	max_count = max(max_count, length);

		//상하좌우 탐색
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= R || ny < 0 || ny >= C) //경계선(판) 넘는지 확인
			continue;

		if (visited_alpha[board[nx][ny] - 'A'] == true) //방문한 알파벳인지 확인
			continue;

		visited_alpha[board[nx][ny] - 'A'] = true; //방문처리
		dfs(nx, ny, R, C, length + 1);
		visited_alpha[board[nx][ny] - 'A'] = false;
	}
}

int main(void) {
	int R;
	int C;

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}

	visited_alpha[board[0][0] - 'A'] = true;
	dfs(0, 0, R, C, 1);
	cout << max_count;
}