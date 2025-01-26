#include <iostream>
#include <string>
using namespace std;

string exp_str;
string exp_grp[50]; //'-'�� �������� ���� �׷�� ex)50+30-20+10�� (50+30)�׷�� (20+10)�׷����� ������.
int grp_cnt = 0;

//�׷��� ��� ��� (20+10)�׷��̸� 30�� �����Ѵ�.
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
            num = atoi(str_num.c_str()); //���ڿ� -> ������
            result += num;
            start_idx = i + 1;
        }
    }

    return result;
}

int main(void)
{
    getline(cin, exp_str); //�����Է�

    int result = 0;
    int grp_idx = 0;
    int start_idx = 0;

    //'-'�� ���������� �׷����� ������.
    for (int i = 0; i <= exp_str.length(); i++)
    {
        if (exp_str[i] == '-' || exp_str[i] == '\0')
        {
            exp_grp[grp_idx] = exp_str.substr(start_idx, i - start_idx); //�׷��� �����.
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
