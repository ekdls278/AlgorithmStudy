#include<iostream>
#pragma warning(disable:4996)

#define MAX ((1<<6)+1)

using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0 ,-1 };

int N, Q;
int A[MAX][MAX];
int visited[MAX][MAX];
int sum = 0;
int maxArea = 0;
int area = 0;
bool checkMelt[MAX][MAX];


void Input()
{
	cin >> N >> Q;
	N = (1 << N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}
}

void rotateRight(int y, int x, int L)
{
	int tmp[MAX][MAX];
	fill(&tmp[0][0], &tmp[0][0] + MAX * MAX, 0);

	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			tmp[i][j] = A[y + L - j - 1][x + i];
		}
	}
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < L; j++)
		{
			A[y + i][x + j] = tmp[i][j];
		}
	}
}

 
void Glacier()
{
	fill(&checkMelt[0][0], &checkMelt[0][0] + MAX * MAX, false);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (A[i][j] > 0)
			{
				int cnt = 0;
				for (int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];

					if (ny >= N || ny < 0 || nx >= N || nx < 0)continue;
					if (A[ny][nx] > 0)cnt++;
				}
				if (cnt < 3)checkMelt[i][j] = true;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (checkMelt[i][j])A[i][j]--;
		}
	}

	return;
}

void dfs(int y, int x)
{
	
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= N || ny < 0 || nx >= N || nx < 0 || !A[ny][nx] || visited[ny][nx])continue;
		area++;
		visited[ny][nx] = 1;
		dfs(ny, nx);
	}
	return;

}



void Solution()
{
	int L = 0;
	while (Q--)
	{
		cin >> L;
		L = (1 << L);
		for (int i = 0; i < N; i += L)
		{
			for (int j = 0; j < N; j += L)
			{
				rotateRight(i, j, L);
			}
		}
		Glacier();	
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (A[i][j] >0)
			{
				sum += A[i][j];
				if (!visited[i][j])
				{
					area = 1;
					visited[i][j] = 1;
					dfs(i, j);
					maxArea = max(maxArea, area);
				}
			}
		}
	}
	cout << sum << "\n" << maxArea;
	

}

int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\20058.txt", "r", stdin);
#endif
	Input();
	Solution();
	return 0;
}