#include<iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

int N, M;
map<string, int> A, B;


void Input()
{
	string tmp = "";
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		A[tmp] = stoi(tmp.c_str());
	}
	for (int j = 0; j < M; j++)
	{
		cin >> tmp;
		B[tmp] = stoi(tmp.c_str());
	}
}

int Solution() 
{
	int ret = 0;
	for (auto it : A)
	{
		if (B[it.first])
			ret++;
	}
	ret = N + M - ret * 2;
	return ret;
}
int main()
{
	Input();
	cout<<Solution();

	return 0;
}