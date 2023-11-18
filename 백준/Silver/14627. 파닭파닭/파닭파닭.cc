#include<iostream>
#define MAX 1000001


typedef long long ll;
using namespace std;

ll S, C;
ll pa[MAX];
ll sum = 0;
ll mxPa=1;
ll ret = 1;

void Input()
{
	cin >> S >> C;
	for (int i = 0; i < S; i++)
	{
		cin >> pa[i];
		sum += pa[i];
		mxPa = (mxPa, pa[i]);
	}
}

bool check(ll mid)
{
	ll cnt = 0;
	for (ll i = 0; i < S; i++)
	{
		cnt += (pa[i] / mid);
	}
	return cnt >= C;
}

void BinarySearch()
{
	ll l = 1, r = 1e9;
	while (l <= r)
	{
		ll mid = (l + r) / 2;
		if (check(mid))
		{
			ret = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
}

void Solute()
{
	cout << sum - ret * C << "\n";
}

void Solution()
{
	Input();
	BinarySearch();
	Solute();
}

int main()
{
	Solution();
	return 0;
}