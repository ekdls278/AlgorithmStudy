#include<stdio.h>
#include<queue>
#include<vector>
#pragma warning (disable:4996)
#define MAX 21
using namespace std;

struct YX
{
	int y;
	int x;
};

int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };
vector<int> dice = { 0, 1, 2, 3, 4, 5, 6 };

int N, M, K;
int board[MAX][MAX];
int scoreBoard[MAX][MAX];
bool visited[MAX][MAX];
int ret = 0;
int nowY, nowX;

void rollDice(int d)
{
	//서
	if (d == 0)
	{
		dice = { 0,dice[3], dice[2], dice[6], dice[1], dice[5], dice[4] };
	}
	//북
	else if (d == 1)
	{
		dice = { 0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2] };
	}
	//동
	else if (d == 2)
	{
		dice = { 0, dice[4],dice[2],dice[1] ,dice[6] ,dice[5] ,dice[3] };
	}
	else
	{
		dice = { 0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5] };
	}
}

void makeScore(int y, int x, int cost)
{
	int cnt = 1;
	vector<YX> vec;
	queue<YX> q;
	vec.push_back({ y, x });
	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty())
	{
		YX now = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny >= N || ny < 0 || nx >= M || nx < 0 || visited[ny][nx])continue;
			if (cost == board[ny][nx])
			{
				visited[ny][nx] = true;
				q.push({ ny, nx });
				vec.push_back({ ny, nx });
				cnt++;
			}
		}

	}
	for (auto it : vec)
	{
		scoreBoard[it.y][it.x] = cnt*cost;
	}

}

void moveDice(int &y, int &x, int& d)
{
	int ny = y + dy[d];
	int nx = x + dx[d];
	if (ny >= N || ny < 0 || nx >= M || nx < 0)
	{
		d = (d + 2) % 4;
		ny = y + dy[d];
		nx = x + dx[d];
	}
	rollDice(d);
	ret += scoreBoard[ny][nx];
	//시계
	if (board[ny][nx] < dice[6])
	{
		d = (d + 1) % 4;
	}
	//반시계
	else if (board[ny][nx] > dice[6])
	{
		d = (d + 3) % 4;
	}
	y = ny, x = nx;
}

int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\23288.txt", "r", stdin);
#endif
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j])continue;
			makeScore(i, j, board[i][j]);
		}
	}
	nowY = 0, nowX = 0;
	int d = 2;
	while (K--)
	{
		moveDice(nowY, nowX, d);
	}
	printf("%d", ret);


	return 0;
}