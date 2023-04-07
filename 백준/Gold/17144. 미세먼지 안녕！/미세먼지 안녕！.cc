#include<bits/stdc++.h>
#define MAX 55
#pragma warning(disable:4996)

using namespace std;

struct YX {
	int y;
	int x;
};

int dy[] = { 0,-1,0,1 };
int dx[] = { -1,0,1,0 };

int R, C, T;
int _map[MAX][MAX];	
vector<YX> airClean;

void spread()
{
	int newMap[MAX][MAX];
	memset(newMap, 0, sizeof(newMap));
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (_map[i][j] > 0)
			{
				int cnt = 0;
				int cost = _map[i][j] / 5;
				for (int d = 0; d < 4; d++)
				{
					int ny = i + dy[d];
					int nx = j + dx[d];
					if (ny >= R || ny < 0 || nx >= C || nx < 0 || _map[ny][nx] == -1)continue;
					newMap[ny][nx] += cost;
					cnt++;
				}
				_map[i][j] -= cnt * cost;
			}
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			_map[i][j] += newMap[i][j];
		}
	}

}

void clean()
{
	int newMap[MAX][MAX];
	copy(&_map[0][0], &_map[0][0] + MAX * MAX, &newMap[0][0]);
	//위에 있는 공기청정기
	YX top = airClean[0];
	YX bottom = airClean[1];
	newMap[top.y][1] = 0;
	newMap[bottom.y][1] = 0;
	//->
	for (int i = 1; i < C - 1; i++)
	{
		newMap[top.y][i+1] = _map[top.y][i];
		newMap[bottom.y][i + 1] = _map[bottom.y][i];
	}
	//위
	for (int i = top.y; i > 0; i--)
	{
		newMap[i - 1][C - 1] = _map[i][C - 1];
	}
	//bottom down
	for (int i = bottom.y; i < R-1; i++)
	{
		newMap[i + 1][C - 1] = _map[i][C - 1];
	}
	//<-
	for (int i = C - 1; i > 0; i--)
	{
		newMap[0][i - 1] = _map[0][i];
		newMap[R - 1][i - 1] = _map[R - 1][i];
	}
	//아래
	for (int i = 0; i < top.y-1; i++)
	{
		newMap[i + 1][0] = _map[i][0];
	}
	//bottom up
	for (int i = R - 1; i > bottom.y+1; i--)
	{
		newMap[i - 1][0] = _map[i][0];
	}

	copy(&newMap[0][0], &newMap[0][0] + MAX * MAX, &_map[0][0]);
}


int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\17144.txt", "r", stdin);
#endif
	scanf("%d %d %d", &R, &C, &T);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%d", &_map[i][j]);
			if (_map[i][j] == -1)airClean.push_back({ i, j });
		}
	}

	while (T--)
	{
		spread();
		clean();
	}
	int ret = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			ret += _map[i][j];
		}
	}

	printf("%d", ret + 2);
	return 0;
}