#include<iostream>

using namespace std;

string str;
int cnt[26];
int flag;
char mid;
string ret;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;
	for (auto it : str)
	{
		cnt[it - 'A']++;
	}

	for (int i = 25; i >= 0; i--)
	{
		if (cnt[i] % 2 != 0)
		{
			flag++;
			cnt[i]--;
			mid = i + 'A';
		}

		if (flag == 2)
		{
			cout << "I'm Sorry Hansoo\n";
			return 0;
		}

		for (int j = 0; j < cnt[i]; j += 2)
		{
			ret = char(i + 'A') + ret;
			ret += char(i + 'A');
		}
	}

	if (mid)ret.insert(ret.begin() + ret.length() / 2, mid);
	cout << ret;


	return 0;
}