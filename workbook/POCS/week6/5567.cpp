#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs();
bool is_directly(int v);
bool is_directly_with_co(int v);

int n; //������� ������ ��
int m; //����Ʈ�� ����
vector<int> adj_list[501];
bool vis[501] = { false }; //�湮�� ��������
int cnt = 0;

void bfs()
{
    queue<int> q;
    q.push(1); //�ڱ��ڽ�: �湮 ���� ����
    vis[1] = true; //�湮ǥ��

    while (!q.empty())
    {
        int cur_v = q.front(); //���� ��ġ�� ����
        q.pop();

        for (int i = 0; i < adj_list[cur_v].size(); i++)
        {
            int next_v = adj_list[cur_v][i];

            if (vis[next_v]) //�湮�ߴٸ� �Ѿ
                continue;
            if (is_directly(next_v) || is_directly_with_co(next_v)) //��������Ǿ��ְų�, ����� �������� �Ǿ�������,
                cnt++; //�ʴ����� �ش�.

            q.push(next_v);
            vis[next_v] = true;
        }
    }
}

//���� 1�� ���� ����Ǿ��ִ��� Ȯ��
bool is_directly(int v) //v: 1�� ���� ����Ǿ��ִ��� Ȯ���Ϸ��� ����
{
    for (int i = 0; i < adj_list[1].size(); i++)
    {
        if (adj_list[1][i] == v)
            return true;
    }
    return false;
}

//����� ���� ����Ǿ��ִ��� Ȯ��
bool is_directly_with_co(int v) //v: 1�� ����� ���� ����Ǿ��ִ��� Ȯ���Ϸ��� ����
{
    for (int i = 0; i < adj_list[1].size(); i++) //1�� �������� �Ǿ��ִ� ����(����)
    {
        int directly_v = adj_list[1][i]; //1�� �������� �Ǿ��ִ� ����(����)
        for (int j = 0; j < adj_list[directly_v].size(); j++)
        {
            if (adj_list[directly_v][j] == v) //����� ���� ���� �Ǿ��ִٸ�
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

        //�ϴ� �׷����� ��������Ʈ ������� �������ش�.
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    bfs();
    cout << cnt;
}
