#include<iostream>
#include<algorithm>
#define MAX 100004

using namespace std;

int N, M;
int arr[MAX];
int ret = 987654321;

void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
}

bool check(int mid)
{
	int cnt = 1;
	int tmpSum = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > mid)return 0;
		tmpSum += arr[i];
		if (tmpSum > mid)
		{
			cnt++;
			tmpSum = arr[i];
		}
	}
	return cnt <= M;
}

void BinarySearch()
{
	int l = 1, r = 1000000004;
	while (l <= r)
	{
		int mid = (l + r) / 2;

		if (check(mid))
		{
			r = mid - 1;
			ret = mid;
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
	BinarySearch();
	cout << ret <<"\n";

	return 0;
}