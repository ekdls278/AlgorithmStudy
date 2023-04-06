#include <stdio.h>
#include <algorithm>
#include <string.h>
#define MAX 52
#pragma warning(disable:4996)
using namespace std;

int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int N, M;
int A[MAX][MAX];
int nowCloud[MAX][MAX];

int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\21610.txt", "r", stdin);
#endif
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}
	nowCloud[N - 1][1] = 1, nowCloud[N - 1][2] = 1;
	nowCloud[N][1] = 1, nowCloud[N][2]=1;

	int d = 0, s = 0;
	while (M--)
	{
		scanf("%d %d", &d, &s);
		int newCloud[MAX][MAX];
		memset(newCloud, 0, sizeof(newCloud));
		//구름 이동
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (nowCloud[i][j] == 1)
				{
					int ny = i;
					int nx = j;
					for (int k = 0; k < s; k++)
					{
						ny += dy[d];
						nx += dx[d];
						if (ny == 0)ny = N;
						if (nx == 0)nx = N;
						if (ny > N)ny -= N;
						if (nx > N)nx -= N;
					}
					newCloud[ny][nx] = 1;
				}
			}
		}
		//4번 물복사버그
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (newCloud[i][j])
				{
					A[i][j]++;
				}
			}
		}
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (newCloud[i][j])
				{
					int cnt = 0;
					for (int k = 2; k <= 8; k += 2)
					{
						int ny = i + dy[k];
						int nx = j + dx[k];
						if (ny > N || ny <1 || nx >N || nx < 1)continue;
						if (A[ny][nx])cnt++;
					}
					A[i][j] += cnt;
				}
			}
		}
		//새로운 구름 생성
		memset(nowCloud, 0, sizeof(nowCloud));
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (A[i][j] >= 2 && !newCloud[i][j])
				{
					nowCloud[i][j] = 1;
					A[i][j] -= 2;
				}
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			ret += A[i][j];
		}
	}

	printf("%d\n", ret);
	return 0;
}