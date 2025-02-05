#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int N; //���� ��
int M; //���� ��
int V; //Ž�� ���� ����

bool adj_matrix[1001][1001] = { false };
bool visited[1001] = { false };

//����� ��� DFS,
//������ ����� DFS������, �湮������ Ʋ�� �� �־ -> ����� DFS�� �ణ ��������
void dfs_not_recursive(int start_v)
{
    stack<int> s;
    s.push(start_v); //Ž�� �������� Ǫ��
    visited[start_v] = true; //Ž�� �������� �湮ǥ��

    while (!s.empty())
    {
        int cur_v = s.top();
        s.pop();

        if (visited[cur_v] == true && cur_v != start_v)
            continue;

        cout << cur_v << ' ';

        visited[cur_v] = true;

        for (int i = N; i >= 1; i--) //������������ �湮�� �� �ְ�
        {
            if (visited[i] == false && adj_matrix[cur_v][i]) //���� �湮���� �ʾҰ�, ������ �����Ѵٸ�?
            {
                int next_v = i;
                s.push(next_v); //����Ǿ��ִ� ������ ���ÿ� Ǫ��
            }
        }
    }
}

//����� ��� BFS
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
        adj_matrix[u][v] = true; //����� �׷�����
        adj_matrix[v][u] = true; //�ݴ뿡�� ����
    }

    dfs_not_recursive(V);
    initialize_visited();
    cout << '\n';
    bfs_not_recursive(V);
}
