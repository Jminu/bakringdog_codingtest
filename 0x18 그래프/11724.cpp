/*
* BOJ 11724 ���� ����� ����
* bfs�� Ǯ���� �� �ִ� ����.
* ���⼭ ���� ����� ������� ����, -> �׷����� ��
* ���� ���� �ݺ������� Ǯ �� ����
*/
#include <iostream>
#include <queue>
using namespace std;

int N;
int M;
bool adj_mat[1001][1001] = { false };
bool vis[1001] = { false };
int graph_cnt = 0;

void bfs()
{
	queue<int> q;

	for (int start_v = 1; start_v <= N; start_v++) //start_v: Ž�� ���� ����
	{
		if (vis[start_v] == true) //Ž�� ���� ������ �湮�ߴٸ� �н�
			continue;

		q.push(start_v);
		vis[start_v] = true;
		graph_cnt++; //�׷����� �� ����
		

		while (!q.empty())
		{
			int cur_v = q.front();
			q.pop();

			for (int i = 1; i <= N; i++)
			{
				if (vis[i] == false && adj_mat[cur_v][i] == true) { //�湮���� �ʾҰ�, ������ �ִٸ�
					q.push(i);
					vis[i] = true;
				}
			}
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie();

	cin >> N >> M;
	
	for (int i = 0; i < M; i++)
	{
		int u;
		int v;
		
		cin >> u >> v;
		adj_mat[u][v] = true;
		adj_mat[v][u] = true;
	}

	bfs();
	cout << graph_cnt;
}