#include<iostream>
#define MAX 100003
using namespace std;

long long N;
long long arr[MAX];
long long visited[MAX];
long long ret;

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
}

void Solution()
{
	long long l = 0, r = 0;
	while (r<N)
	{
		if (!visited[arr[r]])
		{
			visited[arr[r++]] = 1;
		}
		else
		{
			ret += (r - l);
			visited[arr[l++]]--;
		}
	}
	ret += ((r - l) * (r - l + 1)) / 2;
	cout << ret << "\n";


}
	


int main()
{
	Input();
	Solution();

	return 0;
}