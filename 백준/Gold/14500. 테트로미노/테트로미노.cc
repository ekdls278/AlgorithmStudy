#include <stdio.h>
#include <algorithm>
#include<iostream>
#pragma warning (disable:4996)
#define MAX 505
using namespace std;

int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };
int n, m;
int ret;
int map[MAX][MAX];
int visited[MAX][MAX];
void dfs(int y, int x, int cnt, int price)
{
	if (cnt == 3)
	{
		ret = max(ret, price);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= n || ny < 0 || nx >= m || nx < 0 || visited[ny][nx])continue;
		visited[ny][nx] = 1;
		dfs(ny, nx, cnt+1, price+map[ny][nx]);
		visited[ny][nx] = 0;
	}
}


int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\14500.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = 1;
			dfs(i, j,0, map[i][j]);
			visited[i][j] = 0;
			if (j + 2 < m && i-1>=0)ret = max(ret, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 1]);
			if (j + 2 < m && i + 1 < n)ret = max(ret, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1]);
			if (i + 2 < n && j-1>=0)ret = max(ret, map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j - 1]);
			if(i+2<n && j+1<m)ret = max(ret, map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1]);

		}
	}
	// ㅓ ㅜ ㅏ ㅗ

	printf("%d\n", ret);


	return 0;
}