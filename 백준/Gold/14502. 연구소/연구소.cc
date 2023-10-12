#include<bits/stdc++.h>
#pragma warning(disable:4996)
using namespace std;


struct coordinate {
	int y;
	int x;
};

int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };
int n, m;
int arr[10][10];
int visited[10][10];
vector<coordinate> emptyList;
vector<coordinate> virusList;
int ret;

void dfs(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= n || ny <0 || nx >=m || nx < 0)continue;
		if (!visited[ny][nx] && arr[ny][nx] == 0)
		{
			dfs(ny, nx);
		}
	}
}

int main()
{

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0)emptyList.push_back({ i,j });
			if (arr[i][j] == 2)virusList.push_back({ i,j });
		}
	}
	int len = emptyList.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			for (int k = j + 1; k < len; k++)
			{
				//visited초기화
				memset(visited, 0, sizeof(visited));
				//벽 올리고
				arr[emptyList[i].y][emptyList[i].x] = 1;
				arr[emptyList[j].y][emptyList[j].x] = 1;
				arr[emptyList[k].y][emptyList[k].x] = 1;
				visited[emptyList[i].y][emptyList[i].x] = 1;
				visited[emptyList[j].y][emptyList[j].x] = 1;
				visited[emptyList[k].y][emptyList[k].x] = 1;
				for (int l = 0; l < virusList.size(); l++)
				{
					if (!visited[virusList[l].y][virusList[l].x])
					{
						dfs(virusList[l].y, virusList[l].x);
					}
				}

				int cnt = 0;
				for (int i = 0; i < emptyList.size(); i++)
				{
					if (!visited[emptyList[i].y][emptyList[i].x])
						cnt++;
				}
				ret = max(ret, cnt);

				//벽 내리고
				arr[emptyList[i].y][emptyList[i].x] = 0;
				arr[emptyList[j].y][emptyList[j].x] = 0;
				arr[emptyList[k].y][emptyList[k].x] = 0;


			}
		}
	}

	printf("%d", ret);
	return 0;
}