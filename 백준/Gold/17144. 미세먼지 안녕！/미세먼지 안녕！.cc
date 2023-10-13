#include<iostream>
#include<vector>
#define MAX 51
using namespace std;


int R, C, T;
int A[MAX][MAX];
int airCon[2];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void Input()
{
	int tmp = 0;
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> A[i][j];
			if (A[i][j] == -1)airCon[tmp++] = i;
		}
	}
}

void miseGo()
{
	int tmp[MAX][MAX];
	fill(&tmp[0][0], &tmp[0][0] + MAX * MAX, 0);

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (A[i][j] > 0)
			{
				int cost = A[i][j] / 5;
				int cnt = 0;
				for (int d = 0; d < 4; d++)
				{
					int ny = i + dy[d];
					int nx = j + dx[d];

					if (ny >= R || ny < 0 || nx >= C || nx < 0)continue;
					if (A[ny][nx] == -1)continue;
					tmp[ny][nx] += cost;
					cnt++;
				}
				tmp[i][j] += A[i][j] - cost * cnt;
			}
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			A[i][j] = tmp[i][j];
		}
	}
	A[airCon[0]][0] = -1;
	A[airCon[1]][0] = -1;
}

int changeDir(int d)
{
	switch (d)
	{
	case 0:
		return 3;
	case 1:
		return 0;
	case 2:
		return 1;
	case 3:
		return 2;
	}
}

void goClean()
{
	int ud = 1;
	int suy = airCon[0];
	int sux = 1;

	int dd = 1;
	int sdy = airCon[1];
	int sdx = 1;

	int tmp[MAX][MAX];
	fill(&tmp[0][0], &tmp[0][0] + MAX * MAX, 0);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			tmp[i][j] = A[i][j];
		}
	}
	tmp[suy][sux] = 0;
	tmp[sdy][sdx] = 0;

	while (1)
	{
		int nuy = suy + dy[ud];
		int nux = sux + dx[ud];
		if (nuy == airCon[1] && nux == 0)break;
		if (nuy >= R || nuy < 0 || nux >= C || nux < 0)
		{
			ud = changeDir(ud);
			continue;
		}
		tmp[nuy][nux] = A[suy][sux];
		suy = nuy;
		sux = nux;
	}


	while (1)
	{
		int ndy = sdy + dy[dd];
		int ndx = sdx + dx[dd];
		if (ndy == airCon[0] && ndx == 0)break;
		if (ndy >= R || ndy < 0 || ndx >= C || ndx < 0)
		{
			dd = (dd + 1) % 4;
			continue;
		}
		tmp[ndy][ndx] = A[sdy][sdx];
		sdy = ndy;
		sdx = ndx;
	}
	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			A[i][j] = tmp[i][j];
		}
	}
	A[airCon[0]][0] = -1;
	A[airCon[1]][0] = -1;
}

int Solution()
{
	while (T--)
	{
		miseGo();
		goClean();
	}
	int ret = 2;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			ret += A[i][j];
		}
	}
	return ret;
}


int main()
{
	Input();
	cout<<Solution()<<"\n";

	return 0;
}