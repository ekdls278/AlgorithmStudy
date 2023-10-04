#include<iostream>
#include<string>
#include<algorithm>
#pragma warning(disable:4996)

using namespace std;

string A, B, C, D;

void Input()
{
	cin >> A >> B >> C >> D;
}

void Solution()
{
	unsigned long long ret = 0;
	A += B;
	C += D;

	unsigned long long AB = stoull(A.c_str());
	unsigned long long CD = stoull(C.c_str());

	ret = AB + CD;
	cout << ret << "\n";

}

int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\10824.txt", "r", stdin);
#endif
	Input();
	Solution();

	return 0;
}