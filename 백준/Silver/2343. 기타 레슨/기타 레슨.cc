#include<iostream>
#pragma warning(disable:4996)
#define MAX 100001
using namespace std;

int N, M;
int arr[MAX];
int sum;
int ret = 987654321;


void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
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
	int l = 1, r = sum;
	while (l <= r)
	{
		int mid = (l + r) / 2;
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
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\2343.txt", "r", stdin);
#endif
	Input();
	BinarySearch();
	cout << ret;


	return 0;
}