#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 1001


using namespace std;

int N;
int arr[MAX];
int prev_list[MAX];
int cnt[MAX];
int ret=1, idx;

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	fill(prev_list, prev_list + MAX, -1);
	fill(cnt, cnt + MAX, 1);
	
}

void Solution()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && cnt[i] < cnt[j]+1)
			{
				cnt[i] = cnt[j] + 1;
				prev_list[i] = j;
				if (ret < cnt[i])
				{
					ret = cnt[i];
					idx = i;
				}
			}
		}
	}
	vector<int> real;
	cout << ret << "\n";
	int i = idx;
	for (; prev_list[i] != -1; i = prev_list[i])
	{
		real.push_back(arr[i]);
	}
	real.push_back(arr[i]);
	for (int i = real.size() - 1; i >= 0; i--)
	{
		cout << real[i]<<" ";
	}
}

int main()
{
	Input();
	Solution();

	return 0;
}