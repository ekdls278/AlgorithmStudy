#include<iostream>
#define MAX 30002
using namespace std;

//접시 수, 가짓수, 연속, 쿠폰번호
int N, d, k, c;
int arr[MAX];
int visited[3002];


void Input()
{
	cin >> N >> d >> k >> c;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
}

int Solution()
{
	int l = 0, r = k-1;
	int cnt = 0;
	for (int i = l; i <= r; i++)
	{
		visited[arr[i]]++;
		if (visited[arr[i]] == 1)cnt++;
	}
	if (!visited[c])cnt++;
	do
	{
		int tmp = 0;
		
		visited[arr[l++]]--;
		visited[arr[++r]]++;
		for (int i = 1; i <= d; i++)
		{
			if (visited[i])tmp++;
		}
		if (!visited[c])tmp++;
		cnt = max(cnt, tmp);
		if (r == N-1)
		{
			r = -1;
		}
	} while (r != k - 1);
	return cnt;
}

int main()
{
	Input();
	cout << Solution();

	return 0;
}