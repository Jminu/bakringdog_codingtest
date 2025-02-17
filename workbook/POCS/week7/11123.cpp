#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int t; //테스트 케이스
int h; //세로
int w; //가로

string grid[101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool visited[101][101] = { false };

int cnt = 0; //무리 수

void initialize()
{
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			visited[i][j] = false;
	cnt = 0;
}

void bfs()
{
	queue<pair<int, int>> q;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (visited[i][j] == true || grid[i][j] == '.')
				continue;

			q.push({ i, j });
			visited[i][j] = true;

			while (!q.empty())
			{
				pair<int, int> cur = q.front();
				q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (nx < 0 || nx >= h || ny < 0 || ny >= w)
						continue;
					if (visited[nx][ny] == true || grid[nx][ny] == '.')
						continue;

					visited[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
			cnt++;
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> h >> w;
		for (int j = 0; j < h; j++)
		{
			cin >> grid[j]; //문자열 입력 ex) "#.#.##" 같은 문자열
		}
		initialize();
		bfs();
		cout << cnt << '\n';
	}
}