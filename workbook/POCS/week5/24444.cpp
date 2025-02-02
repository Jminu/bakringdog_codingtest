#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

//�׷����� ��������Ʈ�� ǥ��
//������ķ� ǥ���ϸ�, �޸𸮰� ������

int N;
int M;
int R;

int cnt = 0;
int visited_cnt[100001] = { 0 };

bool visited[100001] = { false };
vector<int> adj_list[100001];

//��������Ʈ�� �� �࿡ ���ؼ�, ������������ ����
//�׷��� �������� �������� �湮�ϰ� �ȴ�.
void sort_adj_list()
{	
	for (int i = 1; i <= N; i++)
	{
		sort(adj_list[i].begin(), adj_list[i].end());
	}
}

void bfs(int start_v) //start_v: Ž�� �����ϴ� ����
{
	queue<int> q; //ť ����
	q.push(start_v); //���� ���� ����
	visited[start_v] = true; //���� ������ ó������ �湮ǥ��

	visited_cnt[start_v] = ++cnt; //���� ������ ó���湮�ϴϱ� �湮������ 1��

	while (!q.empty())
	{
		int cur_v = q.front(); //���� ����
		q.pop();
		
		for (int i = 0; i < adj_list[cur_v].size(); i++)
		{
			int next_v = adj_list[cur_v][i];

			if (visited[next_v] == true) //�̹� �湮�ߴ� �����̸� �н�
				continue;

			q.push(next_v); //�湮�ߴ� �� �ƴϸ�, Ǫ���ϰ�
			visited[next_v] = true; //�湮ǥ��

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
		int u; //���� �Է�
		int v;

		cin >> u >> v;

		adj_list[u].push_back(v); //������ �׷����̱� ������
		adj_list[v].push_back(u); //�ݴ� ���⵵ ����
	}

	sort_adj_list();
	bfs(R);

	for (int i = 1; i <= N; i++) //�湮���� ���
	{
		cout << visited_cnt[i] << '\n';
	}
}
