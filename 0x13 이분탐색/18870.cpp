#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int arr[1000001] = { 0 };
vector<int> v;
vector<int> temp;

//이분탐색
int binary_search(int target)
{
    int start = 0;
    int end = v.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (v[mid] == target)
            return mid;
        else if (v[mid] < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        temp.push_back(arr[i]);
    }

    sort(arr, arr + n); //오른차순 정렬(default)

    //중복제거
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            v.push_back(arr[i]);
        }
        else
        {
            if (arr[i] == arr[i - 1])
                continue;

            v.push_back(arr[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        int tg = temp[i];
        int idx = binary_search(tg); //이분탐색 후, 찾으려는 target이 위치한 index가 target보다 작은 원소의 갯수임!!
        cout << idx << ' ';
    }
}
