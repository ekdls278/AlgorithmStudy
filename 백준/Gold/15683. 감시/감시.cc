#include<iostream>
#include<vector>
#pragma warning(disable:4996)

#define MAX 9
#define INF 1987654321
using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

struct CCTV
{
	int type;
	int y, x;
};

int N, M;
int grid[MAX][MAX];
vector<CCTV> cctvs;
int ret = INF;


void Input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] <= 5 && grid[i][j] >= 1)
			{
				cctvs.push_back({ grid[i][j], i, j });
			}
		}
	}
}

int checkEmpty(int board[MAX][MAX])
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0)cnt++;
		}
	}
	return cnt;
}

void secure(int y, int x, int d, int board[MAX][MAX])
{
	int ny = y;
	int nx = x;
	while (1)
	{
		ny += dy[d];
		nx += dx[d];
		if (ny >= N || ny < 0 || nx >= M || nx < 0)break;
		if (board[ny][nx] == 6)break;
		if (board[ny][nx] == 0)board[ny][nx] = 7;
	}
}

void dfs(int idx, int board[MAX][MAX])
{
	if (idx == cctvs.size())
	{
		ret = min(ret, checkEmpty(board));
		return;
	}
	CCTV now = cctvs[idx];
	
	switch (now.type)
	{
	case 1:
		for (int i = 0; i < 4; i++)
		{
			int newBoard[MAX][MAX];
			copy(&board[0][0], &board[0][0] + MAX * MAX, &newBoard[0][0]);
			secure(now.y, now.x, i, newBoard);
			dfs(idx + 1, newBoard);
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++)
		{
			int newBoard[MAX][MAX];
			copy(&board[0][0], &board[0][0] + MAX * MAX, &newBoard[0][0]);
			secure(now.y, now.x, i, newBoard);
			secure(now.y, now.x, i + 2, newBoard);
			dfs(idx + 1, newBoard);
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++)
		{
			int newBoard[MAX][MAX];
			copy(&board[0][0], &board[0][0] + MAX * MAX, &newBoard[0][0]);

			secure(now.y, now.x, i, newBoard);
			secure(now.y, now.x, (i+1)%4, newBoard);
			dfs(idx + 1, newBoard);
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++)
		{
			int newBoard[MAX][MAX];
			copy(&board[0][0], &board[0][0] + MAX * MAX, &newBoard[0][0]);

			secure(now.y, now.x, i, newBoard);
			secure(now.y, now.x, (i+1)%4, newBoard);
			secure(now.y, now.x, (i+2)%4, newBoard);
			dfs(idx + 1, newBoard);
		}
		break;
	case 5:
		int newBoard[MAX][MAX];
		copy(&board[0][0], &board[0][0] + MAX * MAX, &newBoard[0][0]);
		for (int i = 0; i < 4; i++)
		{
			
			secure(now.y, now.x, i, newBoard);
		}
		dfs(idx + 1, newBoard);
		break;
	default:
		break;
	}
	
	

}


void Solution()
{
	dfs(0, grid);
	cout << ret << "\n";
}


int main()
{

#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\15683.txt", "r", stdin);
#endif
	Input();
	Solution();

	return 0;
}





//#include<iostream>
//
//using namespace std;
//
//void go(int arr[2][2])
//{
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			arr[i][j] = i + 100;
//		}
//	}
//}
//
//int main()
//{
//
//	int arr[2][2] = { {1,2}, {3,4} };
//
//	go(arr);
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 2; j++)
//		{
//			cout << arr[i][j] << " ";
//		}
//		cout << "\n";
//	}
//
//	return 0;
//
//}
//
