#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int m; //����
int n; //����
int k; //

bool board[101][101] = { false };
bool visited[101][101] = { false };

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int area_cnt_arr[10000];
int area_cnt_idx = 0;

//���� ĥ�ϱ� -> ��ǥ ��ȯ�� �ٽ�
void paint_square(int x1, int y1, int x2, int y2) //����: ��ǥ
{
    int trans_x1 = m - 1 - y1;
    int trans_y1 = x1;
    int trans_x2 = m - 1 - y2;
    int trans_y2 = x2;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= trans_x2 && i <= trans_x1 && j >= trans_y1 && j <= trans_y2)
            {
                board[i][j] = true;
            }
        }
    }
}

void flip()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == true)
                board[i][j] = false;
            else
                board[i][j] = true;
        }
    }
}

void bfs()
{
    int area = 0; //������ ����
    int cnt = 0; //������ ����
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            area = 0;
            if (board[i][j] != true || visited[i][j] == true) //���� ���ų�, �̹� �湮�� ���̶��
                continue; //�Ѿ

            visited[i][j] = true;
            q.push({ i, j });

            while (!q.empty())
            {
                pair<int, int> cur = q.front();
                q.pop();
                area++; //������ ���Ѵ�: ��� 1�� ����

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];

                    if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;
                    if (board[nx][ny] != true || visited[nx][ny] == true)
                        continue;

                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
            } //while�� �����ٴ°�, �� ������ �� ���ߴٴ� ��(�湮)
            area_cnt_arr[area_cnt_idx++] = area;

            cnt++; //������ ��ִ��� ����
        }
    }
    cout << cnt << '\n';

    sort(area_cnt_arr, area_cnt_arr + area_cnt_idx);
    for (int i = 0; i < area_cnt_idx; i++)
    {
        cout << area_cnt_arr[i] << ' ';
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        int temp_x2, temp_y2;

        cin >> x1 >> y1 >> x2 >> y2; //��ĥ�� ��ǥ �Է�
        temp_x2 = x2 - 1;
        temp_y2 = y2 - 1;
        paint_square(x1, y1, temp_x2, temp_y2);
    }

    flip();
    bfs();
}
