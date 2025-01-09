#include <iostream>
#include <queue>
#include <utility>

using namespace std;

bool board[51][51] = { false };
bool visit[51][51] = { false };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int warms = 0;

int bfs(int n, int m) { //n: 세로길이, m: 가로길이
	queue<pair<int, int>> queue;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == true || board[i][j] != true)
				continue; //이미 방문한 곳이거나, 양배추가 없는 곳이면, 패스

			queue.push({ i, j });
			visit[i][j] = true;
			
			while (!queue.empty()) {
				pair<int, int> cur = queue.front();
				queue.pop();
				
				//상하좌우 탐색
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) //board를 넘어가는지 확인
						continue;
					if (visit[nx][ny] == true || board[nx][ny] != true) 
						continue; //방문했던 곳이거나, 양배추가 없는 곳이라면

					queue.push({ nx, ny });
					visit[nx][ny] = true; //방문처리
				}
			}

			warms++;
		}
	}
	return warms;
}

void init_board() {
	for (int i = 0; i < 51; i++)
		for (int j = 0; j < 51; j++)
			board[i][j] = false;
}

void init_visit() {
	for (int i = 0; i < 51; i++)
		for (int j = 0; j < 51; j++)
			visit[i][j] = false;
}

int main(void) {
	int T;
	cin >> T; //테스트 케이스

	int M; //가로길이
	int N; //세로길이
	int K; //배추갯수


	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;

		for (int j = 0; j < K; j++) {
			int X;
			int Y;

			cin >> X >> Y;
			board[Y][X] = true;
		}

		cout << bfs(N, M) << '\n';
		init_board();
		init_visit();
		warms = 0;
	}
}