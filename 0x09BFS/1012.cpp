#include <iostream>
#include <queue>
#include <utility>

using namespace std;

bool board[51][51] = { false };
bool visit[51][51] = { false };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int warms = 0;

int bfs(int n, int m) { //n: ���α���, m: ���α���
	queue<pair<int, int>> queue;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == true || board[i][j] != true)
				continue; //�̹� �湮�� ���̰ų�, ����߰� ���� ���̸�, �н�

			queue.push({ i, j });
			visit[i][j] = true;
			
			while (!queue.empty()) {
				pair<int, int> cur = queue.front();
				queue.pop();
				
				//�����¿� Ž��
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) //board�� �Ѿ���� Ȯ��
						continue;
					if (visit[nx][ny] == true || board[nx][ny] != true) 
						continue; //�湮�ߴ� ���̰ų�, ����߰� ���� ���̶��

					queue.push({ nx, ny });
					visit[nx][ny] = true; //�湮ó��
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
	cin >> T; //�׽�Ʈ ���̽�

	int M; //���α���
	int N; //���α���
	int K; //���߰���


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