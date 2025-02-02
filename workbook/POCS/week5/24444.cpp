#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//그래프를 인접리스트로 표현
//인접행렬로 표현하면, 메모리가 부족함

int N;
int M;
int R;

int cnt = 0;
int visited_cnt[100001] = { 0 };

bool visited[100001] = { false };
vector<int> adj_list[100001];

//인접리스트의 각 행에 대해서, 오름차순으로 정렬
//그래야 오름차순 정점으로 방문하게 된다.
void sort_adj_list()
{	
	for (int i = 1; i <= N; i++)
	{
		sort(adj_list[i].begin(), adj_list[i].end());
	}
}

void bfs(int start_v) //start_v: 탐색 시작하는 정점
{
	queue<int> q; //큐 생성
	q.push(start_v); //시작 정점 삽입
	visited[start_v] = true; //시작 정점은 처음부터 방문표시

	visited_cnt[start_v] = ++cnt; //시작 정점은 처음방문하니까 방문순서가 1임

	while (!q.empty())
	{
		int cur_v = q.front(); //현재 정점
		q.pop();
		
		for (int i = 0; i < adj_list[cur_v].size(); i++)
		{
			int next_v = adj_list[cur_v][i];

			if (visited[next_v] == true) //이미 방문했던 정점이면 패스
				continue;

			q.push(next_v); //방문했던 곳 아니면, 푸시하고
			visited[next_v] = true; //방문표시

			visited_cnt[next_v] = ++cnt;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> R;

	for (int i = 0; i < M; i++)
	{
		int u; //간선 입력
		int v;

		cin >> u >> v;

		adj_list[u].push_back(v); //무방향 그래프이기 때문에
		adj_list[v].push_back(u); //반대 방향도 삽입
	}

	sort_adj_list();
	bfs(R);

	for (int i = 1; i <= N; i++) //방문순서 출력
	{
		cout << visited_cnt[i] << '\n';
	}
}
