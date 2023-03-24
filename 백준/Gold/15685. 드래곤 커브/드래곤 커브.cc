#include <stdio.h>
#include <vector>
#define MAX 101
#pragma warning(disable:4996)
using namespace std;


int dy[] = { 0,-1,0,1 };
int dx[] = { 1, 0,-1,0 };
int n;
int x, y, d, g;
int map[MAX][MAX];
int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\15685.txt", "r", stdin);
#endif
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d %d %d", &x, &y, &d, &g);
		vector<int> dir;
		vector<int> revDir;
		dir.clear();
		dir.push_back(d);
		while (g--)
		{
			revDir = dir;
			int vecLen = revDir.size();
			for(int i=0; i<vecLen; i++)
			{
				revDir[i] = (revDir[i] + 1) % 4;
			}
			for (int i = 0; i < vecLen; i++)
			{
				dir.push_back(revDir.back());
				revDir.pop_back();
			}
		}
		map[y][x] = 1;
		for (auto it : dir)
		{
			int ny = y + dy[it];
			int nx = x + dx[it];
			y = ny, x = nx;
			map[y][x] = 1;
		}
	}
	int ret = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] == 1 && map[i + 1][j + 1] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1)ret++;
		}
	}

	printf("%d", ret);
	return 0;
}