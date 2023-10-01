#include<iostream>
#include<algorithm>
#include<vector>

#pragma warning(disable:4996)
#define MAX 20001

using namespace std;

int T, N, M;
vector<int> A, B;

void Initialize()
{
	N = M = 0;
	A.clear();
	B.clear();
}

void Input()
{
	cin >> N >> M;
	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		A.push_back(tmp);
	}
	for (int j = 0; j < M; j++)
	{
		cin >> tmp;
		B.push_back(tmp);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
}

int BinarySearch(int now, int len)
{
	int ret = -1;
	int l = 0, r = len - 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (B[mid] < now)
		{
			ret = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return ret;
}

int Solution()
{
	int ret = 0;
	int Blen = B.size();
	for (int i = 0; i < A.size(); i++)
	{
		int tmp = BinarySearch(A[i], Blen);
		if (tmp >= 0)
		{
			ret += (tmp+1);
		}
	}
	return ret;
}

int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\7795.txt", "r", stdin);
#endif
	cin >> T;
	while (T--)
	{
		Initialize();
		Input();
		cout<<Solution()<<"\n";
	}

	return 0;
}