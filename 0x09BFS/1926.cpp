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
	int max_surface = 0; //�ִ����
	int max_surface_temp = 0;
	int surface_count = 0; //���� ī��Ʈ
	int painting_count = 0; //�׸� ����

	queue<pair<int, int>> queue;

	cin >> n >> m;


	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];



	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < m; y++)
		{
			if (vis[x][y] == 1 || board[x][y] != 1) //�̹� �湮�ߴ���, ��ĥ�� '��'�Ǿ��ִ���
				continue; //�׷��� �Ѿ
			
			vis[x][y] = 1; //�湮ó�� �Ѵ��� ť�� ����
			queue.push({ x, y });

			surface_count = 0;

			while (!queue.empty())
			{
				pair<int, int> current = queue.front();
				queue.pop();
				surface_count++; //ť���� ������ ����++

				for (int i = 0; i < 4; i++) //���� �湮���� ����
				{
					int nx = current.first + dx[i];
					int ny = current.second + dy[i];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) //���� �˻�
						continue;
					if ((vis[nx][ny] == 1) || board[nx][ny] != 1) //�̹� �湮 �߰ų�, ��ĥ�� '��'�Ǿ��ִ���
						continue;

					//���⼭ surface_count�� ++�ϸ� ���̻� �湮�� �� ���� ��, ���� ��ġ�� �߰��ȵ�

					vis[nx][ny] = 1; //�˻� ����ϸ� �湮ó��
					queue.push({ nx, ny }); //ť�� ����
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