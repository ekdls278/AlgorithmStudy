#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> wood;

int N, L;
int ret;
void Input()
{
	int st, ed;
	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		cin >> st >> ed;
		wood.push_back({ st, ed });
	}
	sort(wood.begin(), wood.end());
}

void Solution()
{
	int now = 0;

	for (auto it : wood)
	{
		int cnt = 0;
		int l = 0;
		if (now >= it.second)continue;
		if (now >= it.first)
		{
			l = it.second - now;
		}
		else
		{
			now = it.first;
			l = it.second - it.first;
		}
		cnt = l / L;
		cnt += l % L ? 1 : 0;
		now += cnt * L;
		ret += cnt;

	}


	cout << ret;
}

int main()
{
	Input();
	Solution();


	return 0;
}