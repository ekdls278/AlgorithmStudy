#include <iostream>

#define MAX 15001
using namespace std;

int N, M;
int uArr[MAX];
int ret;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> uArr[i];
	}

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (uArr[i] + uArr[j] == M)
				ret++;
		}
	}

	cout << ret;
	return 0;
}