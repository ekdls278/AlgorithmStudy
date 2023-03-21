#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#define MAX 21
#pragma warning(disable:4996)
using namespace std;

int n;
vector<vector<bool>> visited;
vector<vector<int>> map;
int ret = -1;

vector<vector<int>> leftMove(vector<vector<int>> vec, vector<vector<bool>> visited)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n-2; j >=0; j--)
		{
			if (vec[i][j] == 0)continue;
			bool emptyFlag = false;
			int y = i, x = j+1;
			//visited[y][x]가 이미 합처진 경우
			while (x <= n - 1 && !visited[y][x])
			{
				//빈칸이 아니면
				if (vec[y][x])
				{
					//merge해야 하는 경우
					if (vec[i][j] == vec[y][x])
					{
						visited[y][x] = true;
						vec[i][j] = 0;
						vec[y][x] *= 2;
					}
					//다른경우 stay
					else
					{
						break;
					}
				}
				//빈칸이면 이동
				else
				{
					emptyFlag = true;
					x++;
				}
			}
			if (emptyFlag)
			{
				vec[y][x - 1] = vec[i][j];
				vec[i][j] = 0;
			}
		}
	}


	return vec;
}
vector<vector<int>> rightMove(vector<vector<int>> vec, vector<vector<bool>> visited)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <n; j++)
		{
			if (vec[i][j] == 0)continue;
			int y = i, x = j-1;
			bool emptyFlag = false;
			//visited[y][x]가 이미 합처진 경우
			while (x >= 0 && !visited[y][x])
			{
				//빈칸이 아니면
				if (vec[y][x])
				{
					//merge해야 하는 경우
					if (vec[i][j] == vec[y][x])
					{
						visited[y][x] = true;
						vec[i][j] = 0;
						vec[y][x] *= 2;
					}
					//다른경우 stay
					else
					{
						break;
					}
				}
				//빈칸이면 이동
				else
				{
					emptyFlag = true;
					x--;
				}
			}
			if (emptyFlag)
			{
				vec[y][x + 1] = vec[i][j];
				vec[i][j] = 0;
			}
			 
		}
	}


	return vec;
}
vector<vector<int>> topMove(vector<vector<int>> vec, vector<vector<bool>> visited)
{
	for (int j = 0; j < n;j++)
	{
		for (int i = 1; i < n; i++)
		{
			if (vec[i][j] == 0)continue;
			int y = i-1, x = j;
			bool emptyFlag = false;
			//visited[y][x]가 이미 합처진 경우
			while (y >= 0 && !visited[y][x])
			{
				//빈칸이 아니면
				if (vec[y][x])
				{
					//merge해야 하는 경우
					if (vec[i][j] == vec[y][x])
					{
						visited[y][x] = true;
						vec[i][j] = 0;
						vec[y][x] *= 2;
					}
					//다른경우 stay
					else
					{
						break;
					}
				}
				//빈칸이면 이동
				else
				{
					emptyFlag = true;
					y--;
				}
			}
			if (emptyFlag)
			{
				vec[y+1][x] = vec[i][j];
				vec[i][j] = 0;
			}

		}
	}
	return vec;
}


vector<vector<int>> bottomMove(vector<vector<int>> vec, vector<vector<bool>> visited)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = n-2; i >=0; i--)
		{
			if (vec[i][j] == 0)continue;
			int y = i + 1, x = j;
			bool emptyFlag = false;
			//visited[y][x]가 이미 합처진 경우
			while (y < n && !visited[y][x])
			{
				//빈칸이 아니면
				if (vec[y][x])
				{
					//merge해야 하는 경우
					if (vec[i][j] == vec[y][x])
					{
						visited[y][x] = true;
						vec[i][j] = 0;
						vec[y][x] *= 2;
					}
					//다른경우 stay
					else
					{
						break;
					}
				}
				//빈칸이면 이동
				else
				{
					emptyFlag = true;
					y++;
				}
			}
			if (emptyFlag)
			{
				vec[y-1][x] = vec[i][j];
				vec[i][j] = 0;
			}
		}
	}
	return vec;
}

void findMaxRet(vector<vector<int>> vec)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ret = max(ret, vec[i][j]);
		}
	}
}
void dfs(vector<vector<int>> vec, vector<vector<bool>> visited, int cnt)
{
	//기저사례
	if (cnt == 5)
	{
		//최댓값을 찾아야함.
		findMaxRet(vec);
		return;
	}
	//상하좌우 DFS
	dfs(leftMove(vec, visited), visited, cnt+1);
	dfs(rightMove(vec, visited),visited, cnt + 1);
	dfs(topMove(vec, visited),visited, cnt + 1);
	dfs(bottomMove(vec, visited),visited, cnt + 1);
}

int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\12100.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	scanf("%d", &n);
	map.resize(n + 1, vector<int>(n + 1));
	vector<vector<bool>> visited(n+1, vector<bool>(n+1, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	dfs(map, visited, 0);
	printf("%d",ret);
	return 0;
}