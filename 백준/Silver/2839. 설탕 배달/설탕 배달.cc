#include<iostream>
#include<queue>
#define MAX 5001

using namespace std;

int N;
int dp[MAX];


void Input()
{
	cin >> N;
}

void Soltution()
{
	dp[3] = 1;
	dp[5] = 1;
	for (int i = 6; i <= N; i++)
	{
		if (dp[i - 3])dp[i] = dp[i - 3] + 1;

		if (dp[i - 5])dp[i] = dp[i] ? min(dp[i], dp[i - 5] + 1) : dp[i-5]+1;
	}

}


int main()
{
	Input();
	Soltution();
	cout<<(dp[N] ? dp[N] : -1) << "\n";
	return 0;
}