#include <iostream>

#define MAX 1024 + 1
#pragma warning(disable:4996)

using namespace std;

int N, M;
int DP[MAX][MAX];


void Input()
{
	int tmp = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			DP[i+1][j+1] = DP[i+1][j] + DP[i][j+1] - DP[i][j] + tmp;
		}
	}
}

void Solution()
{
	int y1, x1, y2, x2;
	for (int i = 0; i < M; i++)
	{
		cin >> y1 >> x1 >>y2 >> x2;

		cout<<DP[y2][x2] - DP[y2][x1-1] - DP[y1-1][x2] + DP[y1-1][x1-1] << "\n";
	}
}


int main(int argc, char** argv)
{
//#ifdef _DEBUG
//	freopen("C:\\Users\\ekdls\\Desktop\\study\\1249.txt", "r", stdin);
//#endif
    	ios::sync_with_stdio(0);
	cin.tie(0);

	Input();
	Solution();


	
	return 0;
}