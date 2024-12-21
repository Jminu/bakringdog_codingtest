#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int board[502][502] = { 0 };
bool vis[502][502] = { 0 };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void)
{
	int n;
	int m;
	int max_surface = 0; //최대넓이
	int max_surface_temp = 0;
	int surface_count = 0; //넓이 카운트
	int painting_count = 0; //그림 갯수

	queue<pair<int, int>> queue;

	cin >> n >> m;


	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];



	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (vis[x][y] == 1 || board[x][y] != 1) //이미 방문했는지, 색칠이 '안'되어있는지
				continue; //그러면 넘어감
			
			vis[x][y] = 1; //방문처리 한다음 큐에 넣음
			queue.push({ x, y });

			surface_count = 0;

			while (!queue.empty())
			{
				pair<int, int> current = queue.front();
				queue.pop();
				surface_count++; //큐에서 꺼내고 넓이++

				for (int i = 0; i < 4; i++) //어디로 방문할지 정함
				{
					int nx = current.first + dx[i];
					int ny = current.second + dy[i];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) //범위 검사
						continue;
					if ((vis[nx][ny] == 1) || board[nx][ny] != 1) //이미 방문 했거나, 색칠이 '안'되어있는지
						continue;

					//여기서 surface_count를 ++하면 더이상 방문할 게 없을 때, 현재 위치가 추가안됨

					vis[nx][ny] = 1; //검사 통과하면 방문처리
					queue.push({ nx, ny }); //큐에 넣음
				}
			}
			painting_count++;
			max_surface_temp = surface_count;
			if (max_surface < max_surface_temp)
			{
				max_surface = max_surface_temp;
			}
		}
	}

	cout << painting_count << '\n';
	cout << max_surface << '\n';

	return 0;
}