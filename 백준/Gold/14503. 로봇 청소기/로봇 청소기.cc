#include<stdio.h>
#pragma warning (disable:4996)
#define MAX 55
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int n, m;
int map[MAX][MAX];
int visited[MAX][MAX];
int ret = 0;

void go(int y, int x, int d, int cnt)
{
	if (!visited[y][x])
		visited[y][x] = 1, cnt++;
	bool flag = false;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || map[ny][nx] == 1)continue;
		flag = true;
		break;
	}
	//90도씩 반시계로 돌면서 청소 안된 지역 있으면 청소
	if (flag)
	{
		for (int i = 0; i < 4; i++)
		{
			int ncy = y + dy[(d + 3) % 4];
			int ncx = x + dx[(d + 3) % 4];
			d = (d + 3) % 4;
			if (ncy < 0 || ncy >= n || ncx < 0 || ncx >= m || visited[ncy][ncx] || map[ncy][ncx] == 1)continue;
			go(ncy, ncx, d, cnt);
			break;
		}
	}
	//후진
	else
	{
		int ny = y + dy[(d + 2) % 4];
		int nx = x + dx[(d + 2) % 4];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m || map[ny][nx] == 1)
		{
			printf("%d", cnt);
			return;
		}
		else 
		{
			go(ny, nx, d, cnt);
		}
	}
	return;


}

int main()
{

#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\14503.txt", "r", stdin);
#endif
	int sy = 0, sx = 0, sd = 0;
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &sy, &sx, &sd);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	go(sy, sx, sd, 0);

	return 0;
}