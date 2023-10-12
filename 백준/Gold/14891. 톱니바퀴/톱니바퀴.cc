#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int K;
vector<int> gear[4];
int rotateCheck[4];

void Input()
{
	int tmp = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			scanf("%1d", &tmp);
			gear[i].push_back(tmp);
		}
	}
	cin >> K;
}

void clockwise(int idx)
{
	rotate(gear[idx].begin(), gear[idx].begin() + gear[idx].size() - 1, gear[idx].end());
}

void counterClockWise(int idx)
{
	rotate(gear[idx].begin(), gear[idx].begin() + 1, gear[idx].end());
}

void rotateGear(int idx,int d)
{
	if (d == 1)
		clockwise(idx);
	else
		counterClockWise(idx);
}


void toLeft(int idx, int d)
{
	//왼쪽으로 갈 수 있고 && 원래 왼쪽 하고 다음으로 갈 오른쪽 다르면 돌린다.
	if (idx - 1 >= 0 && gear[idx][6] != gear[idx-1][2])
	{
		rotateCheck[idx - 1] = d * -1;
		toLeft(idx - 1, d*-1);
	}
	return;
}

void toRight(int idx, int d)
{
	if (idx + 1 < 4 && gear[idx][2] != gear[idx+1][6])
	{
		rotateCheck[idx + 1] = d * -1;
		toRight(idx + 1, d*- 1);
	}
	return;
}

void Solution()
{
	int n = 0, d = 0;
	while (K--)
	{
		cin >> n >> d;
		n -= 1;
		fill(&rotateCheck[0], &rotateCheck[0] + 4, 0);
		rotateCheck[n] = d;
		toLeft(n, d);
		toRight(n, d);
		for (int i = 0; i < 4; i++)
		{
			if (rotateCheck[i] == 0)continue;
			rotateGear(i, rotateCheck[i]);
		}
	}
	int cost = 1;
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		if (gear[i][0])ret += cost;
		cost *= 2;
	}
	cout << ret<<"\n";

}


int main()
{
	Input();
	Solution();
	return 0;
}
