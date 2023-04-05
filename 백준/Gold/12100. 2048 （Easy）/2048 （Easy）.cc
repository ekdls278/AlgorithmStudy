#include<stdio.h>
#include<vector>
#include<algorithm>
#pragma warning (disable:4996)
using namespace std;


int N;
int ret = -1;


void move(vector<vector<int>> &board)
{
	vector<vector<int>> tmp;
	tmp.resize(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		int idx = -1, conti=0;
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 0)continue;
			if (conti && tmp[i][idx] == board[i][j])tmp[i][idx] *= 2, conti = 0;
			else tmp[i][++idx] = board[i][j], conti = 1;
		}
		for (idx++; idx < N; idx++)tmp[i][idx] = 0;
	}
	board = tmp;
}

void rotate(vector<vector<int>> &board)
{
	vector<vector<int>> tmp(N,vector<int>(N,0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tmp[i][j] = board[j][N-i-1];
		}
	}
	board = tmp;
	return;

}

void dfs(vector<vector<int>> board, int cnt)
{
	if (cnt == 5)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				ret = max(ret, board[i][j]);
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		vector<vector<int>> vec = board;
		move(vec);
		dfs(vec,cnt+1);
		rotate(board);
	}
	return;
}

int main()
{
	scanf("%d", &N);
	vector<vector<int>> board;
	board.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}
	dfs(board, 0);
	printf("%d\n", ret);



	return 0;
}