#include<iostream>
#include<memory.h>

#define INF 1987654321

using namespace std;

int T, W;
int t[1004];
int dp[1004][2][34];

void Input()
{
	cin >> T >> W;
	for (int i = 0; i < T; i++)
	{
		cin >> t[i];
	}
}

int Solution(int idx,int loc,int cnt)
{
	if (cnt < 0)return -INF;
	if (idx == T)
	{
		return cnt == 0 ? 0 : -INF;
	}

	if (dp[idx][loc][cnt] != -1)return dp[idx][loc][cnt];
	//dp[idx][loc][cnt] = -INF;
	//idx+1, loc 그대로
	//idx+1, loc 변경 cnt-1

	
	dp[idx][loc][cnt] = max(Solution(idx + 1, loc ^ 1, cnt - 1), Solution(idx + 1, loc, cnt));

	if (loc == t[idx]-1)
	{
		dp[idx][loc][cnt] += 1;
	}

	return dp[idx][loc][cnt];
}

int main()
{
	memset(dp, -1, sizeof(dp));
	Input();
	cout<<max(Solution(0, 1, W - 1), Solution(0, 0, W)) << "\n";


	return 0;
}