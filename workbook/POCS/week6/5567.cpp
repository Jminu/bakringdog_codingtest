#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs();
bool is_directly(int v);
bool is_directly_with_co(int v);

int n; //상근이의 동기의 수
int m; //리스트의 길이
vector<int> adj_list[501];
bool vis[501] = { false }; //방문한 정점인지
int cnt = 0;

void bfs()
{
    queue<int> q;
    q.push(1); //자기자신: 방문 시작 정점
    vis[1] = true; //방문표시

    while (!q.empty())
    {
        int cur_v = q.front(); //현재 위치한 정점
        q.pop();

        for (int i = 0; i < adj_list[cur_v].size(); i++)
        {
            int next_v = adj_list[cur_v][i];

            if (vis[next_v]) //방문했다면 넘어감
                continue;
            if (is_directly(next_v) || is_directly_with_co(next_v)) //직접연결되어있거나, 동기와 직접연결 되어있으면,
                cnt++; //초대장을 준다.

            q.push(next_v);
            vis[next_v] = true;
        }
    }
}

//정점 1과 직접 연결되어있는지 확인
bool is_directly(int v) //v: 1과 직접 연결되어있는지 확인하려는 정점
{
    for (int i = 0; i < adj_list[1].size(); i++)
    {
        if (adj_list[1][i] == v)
            return true;
    }
    return false;
}

//동기와 직접 연결되어있는지 확인
bool is_directly_with_co(int v) //v: 1의 동기와 직접 연결되어있는지 확인하려는 정점
{
    for (int i = 0; i < adj_list[1].size(); i++) //1과 직접연결 되어있는 정점(동기)
    {
        int directly_v = adj_list[1][i]; //1과 직접연결 되어있는 정점(동기)
        for (int j = 0; j < adj_list[directly_v].size(); j++)
        {
            if (adj_list[directly_v][j] == v) //동기와 직접 연결 되어있다면
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        //일단 그래프를 인접리스트 방식으로 생성해준다.
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    bfs();
    cout << cnt;
}
