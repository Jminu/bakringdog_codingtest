#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string works[7] = { "Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex" };
vector<string> works_vec;

void split_str(string bees_works)
{
	istringstream iss(bees_works);
	string strbuf;
	while (getline(iss, strbuf, ' '))
	{
		works_vec.push_back(strbuf);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int works_cnt[7] = { 0 };
	int total_cnt = 0;

	string bees_works;
	while (true)
	{
		getline(cin, bees_works); //일 입력  getline으로 공백포함해서 받음
		if (bees_works == "") //빈칸 입력하면 종료
			break;
		split_str(bees_works);
	}

	vector<string>::iterator it = works_vec.begin();
	for (it = works_vec.begin(); it != works_vec.end(); it++)
	{
		if (*it == "Re")
		{
			works_cnt[0]++;
		}
		else if (*it == "Pt")
		{
			works_cnt[1]++;
		}
		else if (*it == "Cc")
		{
			works_cnt[2]++;
		}
		else if (*it == "Ea")
		{
			works_cnt[3]++;
		}
		else if (*it == "Tb")
		{
			works_cnt[4]++;
		}
		else if (*it == "Cm")
		{
			works_cnt[5]++;
		}
		else if (*it == "Ex")
		{
			works_cnt[6]++;
		}
		total_cnt++;
	}

	cout.precision(2);
	cout << fixed;

	for (int i = 0; i < 7; i++)
	{
		cout << ::works[i] << ' ' << works_cnt[i] << ' ' << (double)works_cnt[i] / (double)total_cnt << '\n';
	}

	cout << "Total " << total_cnt << " 1.00";
}

//Cc Pt Pt Re Tb Re Cm Cm Re Pt Pt Re Ea Ea Pt Pt Pt Re Re Cb Cb Pt Pt Cb
//