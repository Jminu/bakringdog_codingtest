#include <iostream>
using namespace std;

int factorial(int n);
int combination(int n, int r);

int N;
int M;
int K;

int combination(int n, int r)
{
    int result = 0;
    result = factorial(n) / factorial(n - r) / factorial(r);

    return result;
}

int factorial(int n)
{
    int result = 1;
    for (int i = n; i > 0; i--)
    {
        result = result * i;
    }
    return result;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //1부터 N까지의 수 중에 서로 다른 M개의 수를 고른다., 주최자도 똑같이 하되, 적어도 주최자랑 K개의 수가 같으면 당첨
    cin >> N >> M >> K;

    double possible = 0;
    double total = combination(N, M);

    double result_prob = 0;

    for (int i = K; i <= M; i++)
    {
        if (i == M)
        {
            possible++;
        }
        else
        {
            possible += (combination(N - M, M - i) * combination(M, i));
        }
    }
    result_prob = (double)(possible / total);

    cout.precision(9);
    cout << result_prob;
}
