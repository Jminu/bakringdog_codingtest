#include <iostream>
#include <string>
using namespace std;

int N;
int cnt = 0;
bool alphabet[26] = { false };

void initializer_alphabet()
{
    for (int i = 0; i < 26; i++)
    {
        alphabet[i] = false;
    }
}

bool is_group_word(string word, int str_len)
{
    initializer_alphabet();
    for (int i = 0; i < str_len; i++)
    {
        if (i == 0)
        {
            alphabet[word[0] - 'a'] = true;
            continue;
        }

        if (alphabet[word[i] - 'a'] != true) //üũ�Ǿ����� ������
        {
            alphabet[word[i] - 'a'] = true; //üũ��
        }
        else //�̹� �����ߴ� ���ĺ��̸�
        {
            if (word[i - 1] == word[i]) //�����ߴ� ���ĺ�������, ���� ���ĺ��� ���ٸ�
            {
                continue;
            }
            else //�����ߴ� ���ĺ��ε�, ���� ���ĺ��� �ٸ��� �׷�ܾ� �ƴ�
            {
                return false;
            }
        }
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    string* str = new string[N]; //N���� ���ڿ��� ����Ű�� ������ str

    for (int i = 0; i < N; i++)
    {
        cin >> str[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (is_group_word(str[i], str[i].length()) == true)
        {
            cnt++;
        }
    }

    cout << cnt;
}