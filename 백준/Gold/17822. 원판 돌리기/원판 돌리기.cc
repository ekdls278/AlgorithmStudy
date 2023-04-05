#include <stdio.h>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

struct node {
	int cost;
	bool check;
};

vector<deque<node>> q;
int N, M, T;
int x, d, k, num;
double sum;
void clockWise(deque<node>& q, int t )
{
	for (int i = 0; i < t; i++)
	{
		node tmp = q.back();
		q.pop_back();
		q.push_front(tmp);
	}
	
	
}

void counterWise(deque<node>& q, int t)
{
	for (int i = 0; i < t; i++)
	{
		node tmp = q.front();
		q.pop_front();
		q.push_back(tmp);
	}
}

int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\17822.txt", "r", stdin);
#endif
	
	scanf("%d %d %d", &N, &M, &T);
	q.resize(N + 3);
	num = N * M;
	int tmp = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &tmp);
			sum += (double)tmp;
			q[i].push_back({ tmp, false });
		}
	}


	while (T--)
	{
		scanf("%d%d%d", &x, &d, &k);
		//clockWise
		if (d==0)
		{
			for (int i = x; i <= N; i += x)
			{
				clockWise(q[i], k);
			}
		}
		else
		{
			for (int i = x; i <= N; i += x)
			{
				counterWise(q[i], k);
			}
		}
		//같은지 확인
		//맨 윗층 제외
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				//오른쪽, 위 같은지 검사 후 check = true
				
				//꼬리에 있는 수 이면
				if (j == M - 1)
				{
					//우측
					if (q[i][j].cost == q[i][0].cost)
					{
						q[i][j].check = true, q[i][0].check = true;
					}
					//위
					if (q[i][j].cost == q[i + 1][j].cost)
					{
						q[i][j].check = true, q[i+1][j].check = true;
					}
				}
				else
				{
					//우측
					if (q[i][j].cost == q[i][j + 1].cost)
					{
						q[i][j].check = true, q[i][j + 1].check = true;
					}
					//위
					if (q[i][j].cost == q[i + 1][j].cost)
					{
						q[i][j].check = true, q[i + 1][j].check = true;
					}
				}

			}
		}
		//맨윗층 검사
		for (int i = 0; i < M-1; i++)
		{
			if (q[N][i].cost == q[N][i + 1].cost)
			{
				q[N][i].check = true, q[N][i+1].check = true;

			}
		}
		if (q[N][M - 1].cost == q[N][0].cost)q[N][M - 1].check = true, q[N][0].check = true;
		//check된 수 0으로 만들기
		int cnt = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				//0이 된 적 없고 check가 true이면
				if (q[i][j].cost != 0 && q[i][j].check)
				{
					sum -= (double)q[i][j].cost;
					cnt++;
					num--;
					q[i][j].cost = 0;
				}
			}
		}
		//같은 수가 하나도 없었으면
		if (!cnt)
		{
			double sub = sum / (float)num;
			for (int i = 1; i <= N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (!q[i][j].check)
					{
						if (q[i][j].cost > sub)
						{
							q[i][j].cost -= 1;
							sum -= 1;
						}
						else if (q[i][j].cost < sub)
						{
							q[i][j].cost += 1;
							sum += 1;
						}
					}
				}
			}
		}
		

	}
	printf("%d", (int)sum);


	return 0;
}