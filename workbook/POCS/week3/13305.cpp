#include <iostream>
using namespace std;

int n; //도시 개수
int m; //도시를 연결하는 도로수
long long int fuel_price[100001]; //각 도시에서 기름값
long long int dist[100001]; //도로사이의 거리
long long int cost = 0;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n; //도시 수
    m = n - 1; //도로 수

    //도로사이 거리 입력
    for (long long int i = 0; i < m; i++)
    {
        cin >> dist[i];
    }

    //기름값 입력
    for (int i = 0; i < n; i++)
    {
        cin >> fuel_price[i];
    }

    //가장 저렴한 주유소
    long long int min_price = fuel_price[0];

    //초기 필요금액
    cost = fuel_price[0] * dist[0];

    for (int i = 1; i < n - 1; i++)
    {
        if (fuel_price[i] < min_price) //현재 주유소가 더 싸면
        {
            min_price = fuel_price[i]; //가장 저렴한 주요소 교체
            cost = cost + fuel_price[i] * dist[i];
        }
        else //현재 주유소가 더 비싸면
        {
            cost = cost + min_price * dist[i];
        }
    }

    cout << cost;
}
