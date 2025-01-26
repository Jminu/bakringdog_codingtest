#include <iostream>
#include <string>
using namespace std;

string exp_str;
string exp_grp[50]; //'-'를 기준으로 나눈 그룹들 ex)50+30-20+10은 (50+30)그룹과 (20+10)그룹으로 나눈다.
int grp_cnt = 0;

//그룹의 계산 결과 (20+10)그룹이면 30을 리턴한다.
int get_exp_result(string exp)
{
    string str_num;
    int num = 0;
    int result = 0;
    int start_idx = 0;

    for (int i = 0; i <= exp.length(); i++)
    {
        if (exp[i] == '+' || exp[i] == '\0')
        {
            str_num = exp.substr(start_idx, i - start_idx);
            num = atoi(str_num.c_str()); //문자열 -> 숫자형
            result += num;
            start_idx = i + 1;
        }
    }

    return result;
}

int main(void)
{
    getline(cin, exp_str); //수식입력

    int result = 0;
    int grp_idx = 0;
    int start_idx = 0;

    //'-'를 기준으로한 그룹으로 나눈다.
    for (int i = 0; i <= exp_str.length(); i++)
    {
        if (exp_str[i] == '-' || exp_str[i] == '\0')
        {
            exp_grp[grp_idx] = exp_str.substr(start_idx, i - start_idx); //그룹을 만든다.
            grp_idx++;
            grp_cnt++;
            start_idx = i + 1;
        }
    }

    result = get_exp_result(exp_grp[0]);

    for (int i = 1; i < grp_cnt; i++)
    {
        result -= get_exp_result(exp_grp[i]);
    }

    cout << result;
}
