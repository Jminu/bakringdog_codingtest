#include <iostream>
using namespace std;

int N;
int M;
int A[1000001];
int B[1000001];
int C[2000002];
int A_idx = 0;
int B_idx = 0;
int C_idx = 0;

int main(void)
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < M; i++)
        cin >> B[i];

    for (int i = 0; i < N + M; i++)
    {
        if (A_idx == N) //A배열을 다 배치 했을 때,
        {
            C[i] = B[B_idx]; //B배열을 쭉 배치
            B_idx++;
        }
        else if (B_idx == M) //B배열을 다 배치 했을 때,
        {
            C[i] = A[A_idx]; //A배열을 쭉 배치
            A_idx++;
        }
        else
        {
            if (A[A_idx] < B[B_idx]) //B배열의 값이 더 크면
            {
                C[i] = A[A_idx]; //A를 배치한다음
                A_idx++; //A인덱스 증가
            }
            else //A배열의 값이 더 크면
            {
                C[i] = B[B_idx]; //B를 배치한다음
                B_idx++; //B인덱스 증가
            }
        }
    }

    for (int i = 0; i < N + M; i++)
    {
        cout << C[i] << ' ';
    }
}
