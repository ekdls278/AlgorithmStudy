#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Medal
{
	int idx;
	int gold;
	int silver;
	int bronze;
};

int N, K;
int c, g, s, b;
vector<Medal> vec;

bool compare(Medal a, Medal b)
{
	if (a.gold == b.gold)
	{
		if (a.silver == b.silver)
		{
			return a.bronze > b.bronze;
		}
		return a.silver > b.silver;
	}
	return a.gold > b.gold;
}

void Input()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> c >> g >> s >> b;
		vec.push_back({ c,g,s,b });
	}
}

int Solution()
{
	sort(vec.begin(), vec.end(), compare);
	int cnt = 1;
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i - 1].gold == vec[i].gold && vec[i - 1].silver == vec[i].silver && vec[i - 1].bronze == vec[i].bronze)
		{
			if (vec[i].idx == K)return cnt;
			continue;
		}
		cnt++;
	}

}

int main()
{
	Input();
	cout<<Solution();

	return 0;
}