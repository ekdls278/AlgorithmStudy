#include<iostream>
#include<vector>
#pragma warning(disable:4996)

#define MAX 22

using namespace std;

int N, M, x, y, K;
vector<int> dice(7, 0);
int grid[MAX][MAX];

int dy[] = { 0, 0, 0, -1, 1 };
int dx[] = { 0, 1, -1, 0, 0 };


void Input()
{
	cin >> N >> M >> y >> x >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
		}
	}
}

void mvEast()
{
	vector<int> nDice = dice;
	dice[1] = nDice[4];
	dice[2] = nDice[2];
	dice[3] = nDice[1];
	dice[4] = nDice[6];
	dice[5] = nDice[5];
	dice[6] = nDice[3];
}

void mvWest()
{
	vector<int> nDice = dice;
	dice[1] = nDice[3];
	dice[2] = nDice[2];
	dice[3] = nDice[6];
	dice[4] = nDice[1];
	dice[5] = nDice[5];
	dice[6] = nDice[4];
}

void mvSouth()
{
	vector<int> nDice = dice;
	dice[1] = nDice[2];
	dice[2] = nDice[6];
	dice[3] = nDice[3];
	dice[4] = nDice[4];
	dice[5] = nDice[1];
	dice[6] = nDice[5];
}

void mvNorth()
{
	vector<int> nDice = dice;
	dice[1] = nDice[5];
	dice[2] = nDice[1];
	dice[3] = nDice[3];
	dice[4] = nDice[4];
	dice[5] = nDice[6];
	dice[6] = nDice[2];
}

void mvDice(int k)
{
	switch (k)
	{
	case 1:
		mvEast();
		break;
	case 2:
		mvWest();
		break;
	case 3:
		mvNorth();
		break;
	case 4:
		mvSouth();
		break;
	}
}


void Solution()
{
	int cmd = 0;
	while (K--)
	{
		cin >> cmd;
		int ny = y + dy[cmd];
		int nx = x + dx[cmd];
		if (ny >= N || ny < 0 || nx >= M || nx < 0)continue;
		mvDice(cmd);
		if (grid[ny][nx])
		{
			dice[6] = grid[ny][nx];
			grid[ny][nx] = 0;
			cout << dice[1]<<"\n";
		}
		else
		{
			grid[ny][nx] = dice[6];
			cout << dice[1]<<"\n";
		}
		y = ny;
		x = nx;
	}
}

int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\14499.txt", "r", stdin);
#endif
	Input();
	Solution();


	return 0;
}