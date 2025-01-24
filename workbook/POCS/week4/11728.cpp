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
        if (A_idx == N) //A�迭�� �� ��ġ ���� ��,
        {
            C[i] = B[B_idx]; //B�迭�� �� ��ġ
            B_idx++;
        }
        else if (B_idx == M) //B�迭�� �� ��ġ ���� ��,
        {
            C[i] = A[A_idx]; //A�迭�� �� ��ġ
            A_idx++;
        }
        else
        {
            if (A[A_idx] < B[B_idx]) //B�迭�� ���� �� ũ��
            {
                C[i] = A[A_idx]; //A�� ��ġ�Ѵ���
                A_idx++; //A�ε��� ����
            }
            else //A�迭�� ���� �� ũ��
            {
                C[i] = B[B_idx]; //B�� ��ġ�Ѵ���
                B_idx++; //B�ε��� ����
            }
        }
    }

    for (int i = 0; i < N + M; i++)
    {
        cout << C[i] << ' ';
    }
}
