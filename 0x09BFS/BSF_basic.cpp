#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int board[502][502] =
{ {1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} }; // 1이 파란 칸, 0이 빨간 칸에 대응

bool vis[502][502];

int n = 7;
int m = 10;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 }; //상하좌우


int main(void)
{
	queue<pair<int, int>> queue;
	vis[0][0] = 1; //첫번째칸은 방문했음(시작점)
	
	queue.push({ 0, 0 }); //큐의 시작점
	
	while (!queue.empty())
	{
		pair<int, int> cur = queue.front();
		queue.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (vis[nx][ny] || board[nx][ny] != 1)
				continue;
			vis[nx][ny] = 1;
			queue.push({ nx, ny });
		}
	}
}