#include <iostream>
#include <algorithm>
#define MAX 22
#define INF 1987654321
using namespace std;

int N;
int arr[MAX];
int ret = INF;
string str;

void dfs(int cur)
{
	if (cur == N)
	{
		int sum = 0;
		//열 뒤집을지 말지 확인
		for (int i = 1; i <= (1 << (N-1)); i*=2)
		{
			int cnt = 0;
			for (int j = 0; j < N; j++)
			{
				//T이면
				if (arr[j] & i)cnt++;
			}
			sum += min(cnt, N - cnt);

		}
		ret = min(ret, sum);
		return;
	}

	//cur 행 뒤집기
	arr[cur] = ~arr[cur];
	dfs(cur + 1);

	//뒤집지 않았을 때
	arr[cur] = ~arr[cur];
	dfs(cur + 1);
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int value = 1;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == 'T')arr[i] |= value;
			value *= 2;
		}
	}
	dfs(0);
	cout << ret;

	return 0;
}