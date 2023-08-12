#include <iostream>
#define MAX 1001
using namespace std;

int N;
int arr[MAX];
int cnt[MAX];
int ret;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		int maxValue = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && maxValue < cnt[j])
				maxValue = cnt[j];
		}
		cnt[i] = maxValue + 1;
		ret = max(ret, cnt[i]);
	}
	
	cout << ret;

	return 0;
}