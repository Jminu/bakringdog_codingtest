#include <iostream>
#include <utility>
#include <queue>
#include <string>

using namespace std;

string board[101];
int distance[101][101] = { -1 }; //���� �ʱ�ȭ

int dx[4] = {1, -1, 0, 0}; //�����¿� �̵�
int dy[4] = {0, 0, -1, 1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int M;

	cin >> N >> M; //�� �� �Է�
	
	for (int i = 0; i < N; i++)
		cin >> board[i]; //board�� ���ڿ� ���·� �Է�

	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			::distance[i][j] = -1;

	queue<pair<int, int>> queue;
	::distance[0][0] = 0; //map�� 0, 0�� �湮ó��
	queue.push({ 0, 0 }); //(0, 0)�� ť ����

	while (!queue.empty())
	{
		pair<int, int> current = queue.front();
		queue.pop();

		//���� ��ġ�� ������ �����¿� �̵��غ�
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = current.first + dx[dir];
			int ny = current.second + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue; //���� �����ų�
			if (::distance[nx][ny] >= 0 || board[nx][ny] == '0')
				continue; //�̹� �湮�� ���̰ų�, ������ �� ���� ���̸�

			queue.push({ nx, ny });
			::distance[nx][ny] = ::distance[current.first][current.second] + 1; //�Ÿ����
		}
	}

	cout << ::distance[N - 1][M - 1] + 1;
}