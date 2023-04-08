#include<stdio.h>
#define MAX 505
#pragma warning (disable:4996)
using namespace std;


int dy[] = { 0, 1, 0, -1 };
int dx[] = { -1, 0, 1, 0 };

int my[4][9] = {
	{-1, 1, -1, 1, 0, -2, 2, -1, 1},
	{1, 1, 0, 0, 2, 0, 0, -1, -1},
	{-1, 1, -1, 1, 0, -2, 2, -1, 1},
	{-1, -1, 0, 0, -2, 0, 0, 1, 1}
};

int mx[4][9] = {
	{-1, -1, 0, 0, -2, 0, 0, 1, 1},
	{-1, 1, -1, 1, 0, -2, 2, -1, 1},
	{1, 1, 0, 0, 2, 0, 0, -1, -1},
	{-1, 1, -1, 1, 0, -2, 2, -1, 1}
};

int percent[9] = { 10, 10, 7, 7, 5, 2, 2, 1, 1 };


int N;
int board[MAX][MAX];
bool visited[MAX][MAX];
int cy, cx;
int ret = 0;

void spread(int y, int x, int d)
{
	if (board[y][x] == 0)return;
	int sand = board[y][x];
	int spreadSand = 0;
	int outSand = 0;
	for (int i = 0; i < 9; i++)
	{
		int ny = y + my[d][i];
		int nx = x + mx[d][i];
		int windSand = (sand * percent[i]) / 100;
		spreadSand += windSand;
		if (ny >= N || ny < 0 || nx >= N || nx < 0)
		{
			outSand += windSand;
			continue;
		}
		board[ny][nx] += windSand;
	}
	int ny = y + dy[d];
	int nx = x + dx[d];
	if (ny >= N || ny < 0 || nx >= N || nx < 0)
	{
		outSand += (sand - spreadSand);
	}
	else
	{
		board[ny][nx] += (sand - spreadSand);
	}
	board[y][x] = 0;
	ret += outSand;


}


void tonado()
{
	int d = -1;
	while (1)
	{
		if (cy == 0 && cx == 0)
			break;
		visited[cy][cx] = true;
		int nd = (d + 1) % 4;
		int ny = cy + dy[nd];
		int nx = cx + dx[nd];
		if (visited[ny][nx])
		{
			nd = d;
			ny = cy + dy[nd];
			nx = cx + dx[nd];
		}
		spread(ny, nx, nd);
		cy = ny, cx = nx, d = nd;
	}

}

int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\20057.txt", "r", stdin);
#endif
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}
	cy = cx = N / 2;
	tonado();

	printf("%d", ret);
	

	return 0;
}