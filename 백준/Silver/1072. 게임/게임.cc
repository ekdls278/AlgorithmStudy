#include<iostream>

#define INF 1e18
using namespace std;

long long X, Y, Z;
long long ret = 1;
void Input()
{
	cin >> X >> Y;
	Y *= 100;
	Z = Y / X;
}

bool check(long long mid)
{
	long long tmp = (Y + mid * 100) / (X+mid);
	if (tmp != Z)
		return true;

	return false;
}

void BinarySearch()
{
	long long l = 1, r = 1e16;
	while (l <= r)
	{
		long long mid = (l + r) / 2;
		if (check(mid))
		{
			ret = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
}

int main()
{
	Input();
	if (Z >= 99)
	{
		cout << -1;
		return 0;
	}
	BinarySearch();
	cout << ret << "\n";
	

	return 0;
}