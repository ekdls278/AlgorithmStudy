#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
#pragma warning (disable : 4996)
#define MAX 15
#define INF 1987654321
using namespace std;
struct A
{
	int mp, mf, ms, mv, cost;
};
A arr[MAX];
int N;
int mp, mf, ms, mv;
int tp, tf, ts, tv, sum;
map<int, vector<vector<int>>> ret_v;
int ret = INF;

int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\19942.txt", "r", stdin);
#endif
	cin >> N;
	cin >> mp >> mf >> ms >> mv;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].mp >> arr[i].mf >> arr[i].ms >> arr[i].mv >> arr[i].cost;
	}

	for (int i = 1; i < (1 << N); i++)
	{
		tp = tf = ts = tv = sum = 0;
		vector<int> v;
		for (int j = 0; j < N; j++)
		{
			if (i & (1 << j))
			{
				v.push_back(j + 1);
				tp += arr[j].mp;
				tf += arr[j].mf;
				ts += arr[j].ms;
				tv += arr[j].mv;
				sum += arr[j].cost;
			}
		}
		if (tp >= mp && tf >= mf && ts >= ms && tv >= mv)
		{
			if (ret >= sum)
			{
				ret = sum;
				ret_v[sum].push_back(v);
			}
		}
	}
	if (ret == INF) cout << -1 << '\n';
	else
	{
		sort(ret_v[ret].begin(), ret_v[ret].end());
		cout << ret << '\n';
		for (int it : ret_v[ret][0])
		{
			cout << it << " ";
		}
	}


	return 0;
}