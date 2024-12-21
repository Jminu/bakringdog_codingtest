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
 {0,0,0,0,0,0,0,0,0,0} }; // 1�� �Ķ� ĭ, 0�� ���� ĭ�� ����

bool vis[502][502];

int n = 7;
int m = 10;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 }; //�����¿�


int main(void)
{
	queue<pair<int, int>> queue;
	vis[0][0] = 1; //ù��°ĭ�� �湮����(������)
	
	queue.push({ 0, 0 }); //ť�� ������
	
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