#include<iostream>
#include<vector>
#pragma warning (disable:4996)
#define MAX 10001

typedef long long ll;

using namespace std;

ll N, M;
ll arr[MAX];
ll Total;

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> arr[i];
	}
}

ll check(ll mid)
{
	ll cnt = M;
	for (int i = 0; i < M; i++)
	{
		cnt += (mid / arr[i]);
	}
	return cnt >= N;
}

void BinarySearch()
{
	ll l = 1, r = 60000000000;
	while (l <= r)
	{
		ll mid = (l + r) / 2;
		if (check(mid))
		{
			Total = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
}

void Sol()
{
	ll temp = M;
	for (int i = 0; i < M; i++)
	{
		temp += ((Total-1)/arr[i]);
	}
	for (int i = 0; i < M; i++)
	{
		if (Total % arr[i] == 0)temp++;
		if (temp >= N)
		{
			cout << i + 1 << "\n";
			break;
		}
	}
	return;

}

void Solution()
{
	if (N <= M)cout << N <<"\n";
	else
	{
		BinarySearch();
		Sol();
	}
}
int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\1561.txt", "r", stdin);
#endif
	Input();
	Solution();


	return 0;
}