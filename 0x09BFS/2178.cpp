#include <iostream>
#include <utility>
#include <queue>
#include <string>

using namespace std;

string board[101];
int distance[101][101] = { -1 }; //으로 초기화

int dx[4] = {1, -1, 0, 0}; //상하좌우 이동
int dy[4] = {0, 0, -1, 1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int M;

	cin >> N >> M; //행 열 입력
	
	for (int i = 0; i < N; i++)
		cin >> board[i]; //board를 문자열 형태로 입력

	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			::distance[i][j] = -1;

	queue<pair<int, int>> queue;
	::distance[0][0] = 0; //map의 0, 0은 방문처리
	queue.push({ 0, 0 }); //(0, 0)을 큐 삽입

	while (!queue.empty())
	{
		pair<int, int> current = queue.front();
		queue.pop();

		//현재 위치한 곳에서 상하좌우 이동해봄
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = current.first + dx[dir];
			int ny = current.second + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue; //범위 지났거나
			if (::distance[nx][ny] >= 0 || board[nx][ny] == '0')
				continue; //이미 방문한 곳이거나, 지나갈 수 없는 길이면

			queue.push({ nx, ny });
			::distance[nx][ny] = ::distance[current.first][current.second] + 1; //거리계산
		}
	}

	cout << ::distance[N - 1][M - 1] + 1;
}