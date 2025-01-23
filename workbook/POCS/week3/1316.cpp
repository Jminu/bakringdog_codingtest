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

        if (alphabet[word[i] - 'a'] != true) //체크되어있지 않으면
        {
            alphabet[word[i] - 'a'] = true; //체크함
        }
        else //이미 등장했던 알파벳이면
        {
            if (word[i - 1] == word[i]) //등장했던 알파벳이지만, 이전 알파벳과 같다면
            {
                continue;
            }
            else //등장했던 알파벳인데, 이전 알파벳과 다르면 그룹단어 아님
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

    string* str = new string[N]; //N개의 문자열을 가리키는 포인터 str

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