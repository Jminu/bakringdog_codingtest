/*
* BOJ 11724 연결 요소의 개수
* bfs로 풀이할 수 있는 문제.
* 여기서 연결 요수의 개수라는 것은, -> 그래프의 수
* 따라서 이중 반복문으로 풀 수 있음
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

	for (int start_v = 1; start_v <= N; start_v++) //start_v: 탐색 시작 정점
	{
		if (vis[start_v] == true) //탐색 시작 정점을 방문했다면 패스
			continue;

		q.push(start_v);
		vis[start_v] = true;
		graph_cnt++; //그래프의 수 증가
		

		while (!q.empty())
		{
			int cur_v = q.front();
			q.pop();

			for (int i = 1; i <= N; i++)
			{
				if (vis[i] == false && adj_mat[cur_v][i] == true) { //방문하지 않았고, 간선이 있다면
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