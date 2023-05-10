#include <iostream>
#include<algorithm>
#define MAX 44
#define INF	1987654321
using namespace std;

int N;
int coin[MAX];
string str;
int ret = INF;
void solution(int here)
{
	if (here == N+1)
	{
		int sum = 0;
		for (int i = 1; i <= (1 << (N - 1)); i *= 2)
		{
			int cnt = 0;
			for (int j = 1; j <= N; j++)if (coin[j] & i) cnt++;
			sum += min(cnt, N - cnt);
		}
		ret = min(ret, sum);
		return;
	}

	//here 행 뒤집었을 때
	coin[here] = ~coin[here];
	solution(here + 1);
	//here 행 안뒤집었을 때
	coin[here] = ~coin[here];
	solution(here + 1);
}


int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> str;
		int value = 1;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == 'T')coin[i] |= value;
			value *= 2;
		}

	}
	solution(1);
	cout << ret << '\n';


	return 0;
}