#include <iostream>
using namespace std;

int n;
int m;
int arr[9] = { 0 };
bool is_used[9] = { false };

void func(int k, int start_ele)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int i = start_ele; i <= n; i++)
    {
        if (is_used[i] == false)
        {
            arr[k] = i;
            is_used[i] = true;
            func(k + 1, i + 1);
            is_used[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    func(0, 1);
}
