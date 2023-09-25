#include<iostream>
#include<algorithm>
#include<string>

#define MAX 21

using namespace std;

int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };

int R, C;
int grid[MAX][MAX];
int visited[26];
int ret = 1;

void Input()
{
	string str;
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		cin >> str;
		for (int j = 0; j < C; j++)
		{
			grid[i][j] = str[j] - 'A';
		}
	}
}

void dfs(int y, int x, int cnt)
{
	if (ret < cnt)
	{
		ret = cnt;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= R || ny <0 || nx >=C || nx < 0)continue;
		if (visited[grid[ny][nx]])continue;

		visited[grid[ny][nx]] = 1;
		dfs(ny, nx, cnt + 1);
		visited[grid[ny][nx]] = 0;
	}


}

int main()
{
	Input();

	visited[grid[0][0]] = 1;
	dfs(0, 0, 1);

	cout << ret << "\n";

	return 0;
}