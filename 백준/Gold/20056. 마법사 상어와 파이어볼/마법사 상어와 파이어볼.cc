#include<iostream>
#include<vector>
#pragma warning(disable:4996)
#define MAX 52

using namespace std;


struct FireBall
{
	int m;
	int s;
	int d;
};

int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int N, M, K;
vector<FireBall> grid[MAX][MAX];

void Input()
{
	cin >> N >> M >> K;
	int y, x, m, s, d;
	for (int i = 0; i < M; i++)
	{
		cin >> y >> x >> m >> s >> d;
		grid[y][x].push_back({ m, s, d });
	}

}

int getNewY(int y, int d, int s) {
	int ny = y + dy[d] * s;
	while (ny <= 0) {
		ny += N;
	}
	while (ny > N) {
		ny -= N;
	}

	return ny;
}

int getNewX(int x, int d, int s) {
	int nx = x + dx[d] * s;

	while (nx <= 0) {
		nx += N;
	}
	while (nx > N) {
		nx -= N;
	}

	return nx;
}

void MvFireBall()
{
	vector<FireBall> tmp[MAX][MAX];
	for (int i = 1; i <= N; i++)
	{
		for(int j=1; j <= N; j++)
		{
			for (int k = 0; k < grid[i][j].size(); k++)
			{
				FireBall now = grid[i][j][k];
				int ny = getNewY(i, now.d, now.s);
				int nx = getNewX(j, now.d, now.s);

				tmp[ny][nx].push_back({ now });
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			grid[i][j] = tmp[i][j];
		}
	}
}

void CombineFireBall()
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (grid[i][j].size() >= 2)
			{
				FireBall tmp = { 0, 0, 0 };
				int oddCnt = 0;
				int evenCnt = 0;
				int len = grid[i][j].size();
				for (auto it : grid[i][j])
				{
					tmp.m += it.m;
					tmp.s += it.s;
					if (it.d % 2 == 0)evenCnt++;
					else oddCnt++;

					grid[i][j].pop_back();
				}
				tmp.m /= 5;
				if (tmp.m == 0)continue;
				tmp.s /= len;
				if (evenCnt == 0 || oddCnt == 0)
				{
					grid[i][j].push_back({ tmp.m, tmp.s, 0 });
					grid[i][j].push_back({ tmp.m, tmp.s, 2 });
					grid[i][j].push_back({ tmp.m, tmp.s, 4 });
					grid[i][j].push_back({ tmp.m, tmp.s, 6 });
				}
				else
				{
					grid[i][j].push_back({ tmp.m, tmp.s, 1 });
					grid[i][j].push_back({ tmp.m, tmp.s, 3 });
					grid[i][j].push_back({ tmp.m, tmp.s, 5 });
					grid[i][j].push_back({ tmp.m, tmp.s, 7 });

				}
			}
		}
	}
}

void Sol()
{
	int ret = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (auto it : grid[i][j])
			{
				ret += it.m;
			}
		}
	}

	cout << ret << "\n";
}

void Solution()
{
	while (K--)
	{
		MvFireBall();
		CombineFireBall();
	}
	Sol();
}

int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\20056.txt", "r", stdin);
#endif
	Input();
	Solution();
	return 0;
}


