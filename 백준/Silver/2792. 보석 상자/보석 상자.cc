#include<stdio.h>
#include<algorithm>
#include<iostream>
#pragma warning (disable:4996)
#define MAX 300002
using namespace std;


int n,m;
int arr[MAX];
int ret = 1e9;

bool check(int mid)
{
	int num = 0;
	for (int i = 0; i < m; i++)
	{
		num += arr[i] / mid;
		if (arr[i] % mid)num += 1;
	}
	return n >= num;
	
}


int main()
{
	scanf("%d%d", &n, &m);
	int lo = 1, hi = 0, mid;
	for(int i=0; i<m; i++)
	{
		scanf("%d", &arr[i]);
		hi = max(hi, arr[i]);
	}

	while (lo <= hi)
	{
		mid = (lo + hi) / 2;
		if (check(mid))
		{
			ret = min(ret, mid);
			hi = mid - 1;
		}
		else lo = mid + 1;
	}

	printf("%d", ret);
	return 0;
}


