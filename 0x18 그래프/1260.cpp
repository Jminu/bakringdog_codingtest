#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int N; //정점 수
int M; //간선 수
int V; //탐색 시작 정점

bool adj_matrix[1001][1001] = { false };
bool visited[1001] = { false };

//비재귀 방식 DFS,
//기존의 비재귀 DFS에서는, 방문순서가 틀릴 수 있어서 -> 비재귀 DFS를 약간 수정했음
void dfs_not_recursive(int start_v)
{
    stack<int> s;
    s.push(start_v); //탐색 시작정점 푸시
    visited[start_v] = true; //탐색 시작정점 방문표시

    while (!s.empty())
    {
        int cur_v = s.top();
        s.pop();

        if (visited[cur_v] == true && cur_v != start_v)
            continue;

        cout << cur_v << ' ';

        visited[cur_v] = true;

        for (int i = N; i >= 1; i--) //오름차순으로 방문할 수 있게
        {
            if (visited[i] == false && adj_matrix[cur_v][i]) //아직 방문하지 않았고, 간선이 존재한다면?
            {
                int next_v = i;
                s.push(next_v); //연결되어있는 정점을 스택에 푸시
            }
        }
    }
}

//비재귀 방식 BFS
void bfs_not_recursive(int start_v)
{
    queue<int> q;
    q.push(start_v);
    visited[start_v] = true;

    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();

        cout << cur_v << ' ';

        for (int i = 1; i <= N; i++)
        {
            if (visited[i] == false && adj_matrix[cur_v][i])
            {
                int next_v = i;
                q.push(next_v);
                visited[next_v] = true;
            }
        }
    }
}

void initialize_visited()
{
    for (int i = 1; i <= N; i++)
    {
        visited[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> V;
    for (int i = 0; i < M; i++)
    {
        int u;
        int v;
        cin >> u >> v;
        adj_matrix[u][v] = true; //양방향 그래프라
        adj_matrix[v][u] = true; //반대에도 적용
    }

    dfs_not_recursive(V);
    initialize_visited();
    cout << '\n';
    bfs_not_recursive(V);
}
