#include <stdio.h>
#include<algorithm>
#pragma warning (disable:4996)
#define MAX 505
#define INF 987654321
using namespace std;


int n, m, a, b;
int arr[MAX][MAX];
void floyd()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
}

int main()
{
	int answer = 0;
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] = INF;
		}
	}
	
	while (m--)
	{
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}

	floyd();
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] != INF || arr[j][i] != INF)
			{
				cnt++;
			}
		}
		if (cnt == n - 1)answer++;
	}

	printf("%d", answer);



	return 0;
}