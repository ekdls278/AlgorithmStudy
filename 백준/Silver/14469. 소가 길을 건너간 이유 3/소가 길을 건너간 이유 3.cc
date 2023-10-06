#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>


using namespace std;

int N;
vector<pair<int, int>> cows;


void Input()
{
	int dep, cost;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> dep >> cost;
		cows.push_back(make_pair(dep, cost));
	}

}

int Solution()
{
	sort(cows.begin(), cows.end());
	int nowTime = cows[0].first + cows[0].second;
	for (int i = 1; i < cows.size(); i++)
	{
		if (cows[i].first < nowTime)
		{
			nowTime += cows[i].second;
		}
		else
		{
			nowTime = cows[i].first + cows[i].second;
		}
	}
	return nowTime;
	
}


int main()
{
	Input();
	cout<<Solution()<<"\n";
	


	return 0;
}