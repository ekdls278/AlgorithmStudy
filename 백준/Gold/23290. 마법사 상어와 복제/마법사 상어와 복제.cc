#include<iostream>
#include<vector>
#pragma warning(disable:4996)

#define MAX 5
using namespace std;

struct fish {
	int x, y;
	int d;
};

int fdx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int fdy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int sdx[] = { 0, -1, 0, 1, 0 };
int sdy[] = { 0, 0, -1, 0, 1 };

int M, S;
int tempRoute[3], route[3];
int maxEat = -1;

vector<fish> fishMap[MAX][MAX], cMap[MAX][MAX];
pair<int, int> shark;
int smellMap[MAX][MAX];


void Input()
{
	int fx, fy, d;
	cin >> M >> S;
	for (int i = 0; i < M; i++)
	{
		cin >> fx >> fy >> d;
		fishMap[fx][fy].push_back({ fx, fy, d });
	}
	cin >> shark.first >> shark.second;
}

void CopyMap(vector<fish> A[][MAX], vector<fish> B[][MAX])
{
	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			A[i][j] = B[i][j];
		}
	}
}

void CopyFish()
{
	CopyMap(cMap, fishMap);
}

int ChangeDir(int dir)
{
	switch (dir)
	{
	case 1:
		return 8;
	case 2:
		return 1;
	case 3:
		return 2;
	case 4:
		return 3;
	case 5:
		return 4;
	case 6:
		return 5;
	case 7:
		return 6;
	case 8:
		return 7;
	default:
		break;
	}
}

void MoveFish()
{
	vector<fish> tmp[MAX][MAX];
	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			for (int k = 0; k < fishMap[i][j].size(); k++)
			{
				fish now = fishMap[i][j][k];
				bool Flag = false;
				int ny = 0;
				int nx = 0;
				for (int u = 0; u < 8; u++)
				{
					ny = now.y + fdy[now.d];
					nx = now.x + fdx[now.d];
					if (ny < MAX && ny > 0 && nx < MAX && nx >0)
					{
						if ((shark.first != nx || shark.second != ny) && !smellMap[nx][ny])
						{
							Flag = true;
							break;
						}
					}
					now.d = ChangeDir(now.d);
				}
				if (Flag == true) 
				{
					tmp[nx][ny].push_back({ nx, ny, now.d });
				}
				else
				{
					tmp[now.x][now.y].push_back(now);
				}
				
			}
		}
	}
	CopyMap(fishMap, tmp);
}

int HuntFish()
{
	int eat = 0;
	bool visited[MAX][MAX]={false, };

 	int x = shark.first;
	int y = shark.second;

	for (int i = 0; i < 3; i++)
	{
		y = y + sdy[tempRoute[i]];
		x = x + sdx[tempRoute[i]];

		if (y >= MAX || y <= 0 || x >= MAX || x <= 0)return -1;
		if (!visited[x][y] && !fishMap[x][y].empty())
		{
			eat += fishMap[x][y].size();
			visited[x][y] = true;
		}
	}

	return eat;
}

void FindRoute(int cnt)
{
	if (cnt == 3)
	{
		int eat = 0;
		eat = HuntFish();
		if (eat > maxEat)
		{
			maxEat = eat;
			for (int i = 0; i < 3; i++)
			{
				route[i] = tempRoute[i];
			}
		}
		return;
	}

	for (int i = 1; i <= 4; i++)
	{
		tempRoute[cnt] = i;
		FindRoute(cnt + 1);
	}

}


void MoveShark(int time)
{
	for (int i = 0; i < 3; i++)
	{
		shark.first += sdx[route[i]];
		shark.second += sdy[route[i]];
		if (!fishMap[shark.first][shark.second].empty())
		{
			fishMap[shark.first][shark.second].clear();
			smellMap[shark.first][shark.second] = time;
		}
	}
}

void SharkGo(int time)
{
	maxEat = -1;
	FindRoute(0);
	MoveShark(time);
}

void removeSmell(int time)
{
	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			if (!smellMap[i][j])continue;
			if (time - smellMap[i][j] == 2)
				smellMap[i][j] = 0;
		}
	}
}

void bornFish()
{
	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			for (int k = 0; k < cMap[i][j].size(); k++)
			{
				fishMap[i][j].push_back(cMap[i][j][k]);
			}
		}
	}
}


int findAnswer()
{
	int ret = 0;
	for (int i = 1; i < MAX; i++)
	{
		for (int j = 1; j < MAX; j++)
		{
			ret += fishMap[i][j].size();
		}
	}
	return ret;
}

int main()
{

#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\23290.txt", "r", stdin);
#endif
	Input();
	for (int i = 1; i <= S; i++)
	{
		CopyFish();
		MoveFish();
		SharkGo(i);
		removeSmell(i);
		bornFish();
	}
	cout << findAnswer() << "\n";

	return 0;
}