#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;
vector<char> op;
vector<int> num;
int ret = -1987654321;

void Input()
{
	string str;
	cin >> N;
	cin >> str;
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
			num.push_back(str[i] - '0');
		else
			op.push_back(str[i]);
	}
}

//2가지 경우 존재
// (3+8)*7
// 3+(8*7)

int Calculate(char op, int num1, int num2)
{
	if (op == '+')return num1 + num2;
	if (op == '-')return num1 - num2;
	if (op == '*')return num1 * num2;
}

void Solution(int idx, int n)
{
	if (idx == num.size() - 1)
	{
		ret = max(ret, n);
		return;
	}
	Solution(idx + 1, Calculate(op[idx], n, num[idx + 1]));

	if (idx + 2 <= num.size() - 1)
	{
		int tmp = Calculate(op[idx + 1], num[idx + 1], num[idx + 2]);
		Solution(idx + 2, Calculate(op[idx], n, tmp));
	}

}

int main()
{
	Input();
	Solution(0, num[0]);
	cout << ret << "\n";


	return 0;
}