#include <iostream>
#include<algorithm>

#define MAX 1024 + 1
#pragma warning(disable:4996)

using namespace std;

int N;
int DP[MAX][MAX];


void Input()
{
	int tmp = 0;
	cin >> N;
	cin >> DP[0][0];
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> tmp;
			if (j == 0)
			{
				DP[i][j] = DP[i - 1][j] + tmp;
			}
			else if (j == i)
			{
				DP[i][j] = DP[i - 1][j - 1] + tmp;
			}
			else
			{
				DP[i][j] = tmp + max(DP[i - 1][j - 1], DP[i - 1][j]);
			}
		}
	}
}

void Solution()
{
	int ret = -1;
	for (int i = 0; i < N; i++)
	{
		ret = max(ret, DP[N - 1][i]);
	}
	cout << ret << "\n";
}


int main(int argc, char** argv)
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\1932.txt", "r", stdin);
#endif

	Input();
	Solution();


	
	return 0;
}