#include<iostream>
#include<vector>
#include<memory.h>

#define MAX 1000000 + 1

using namespace std;

int N;
int arr[MAX];
vector<int> vec;
int ret[MAX];

void Solution()
{
	cin >> N;
	memset(ret, -1, sizeof(ret));
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		while (vec.size() && arr[vec.back()] < arr[i])
		{
			ret[vec.back()] = arr[i];
			vec.pop_back();
		}
		vec.push_back(i);
	}

	for (int i = 0; i < N; i++)
	{
		cout << ret[i]<<" ";
	}

}

int main()
{
	Solution();
	return 0;
}