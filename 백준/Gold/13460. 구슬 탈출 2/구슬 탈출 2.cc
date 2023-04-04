#include <iostream>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

struct rbYX {
	int ry, rx;
	int by, bx;
	int cnt;
};
int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };

rbYX start;
int N, M;
int visited[11][11][11][11];
char map[11][11];
int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\13460.txt", "r", stdin);
#endif
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			if (str[j] == 'R')start.ry = i, start.rx = j;
			if (str[j] == 'B')start.by = i, start.bx = j;
			map[i][j] = str[j];
		}
	}
	start.cnt = 0;
	int ret = 0;

	queue<rbYX> q;
	q.push(start);
	visited[start.ry][start.rx][start.by][start.bx] = 1;
	while (!q.empty())
	{
		rbYX cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			rbYX next = cur;
			int rMove = 0, bMove = 0;

			while (1)
			{
				if(map[next.ry+dy[i]][next.rx+dx[i]] != '#' && map[next.ry+dy[i]][next.rx+dx[i]] != 'O')
				{
					next.ry += dy[i];
					next.rx += dx[i];
					rMove++;
				}
				else
				{
					break;
				}
			}
			while (1)
			{
				if (map[next.by+dy[i]][next.bx+dx[i]] != '#' && map[next.by+dy[i]][next.bx+dx[i]] != 'O')
				{
					next.by += dy[i];
					next.bx += dx[i];
					bMove++;
				}
				else
				{
					break;
				}
			}
			//if blue가 구멍에 빠졌을 때
			if (map[next.by + dy[i]][next.bx + dx[i]] == 'O')
			{
				//끝내버리면 된다.
				continue;
			}
			//if red만 구멍에 빠졌을 때
			if (map[next.ry + dy[i]][next.rx + dx[i]] == 'O')
			{
				//최솟값 이므로 출력 후 프로그램 종료
				printf("%d\n", next.cnt + 1);
				return 0;
			}
			//같을 때 처리
			if (next.ry == next.by && next.rx == next.bx)
			{
				//많이 움직인 쪽이 더 멀리 있던 쪽
				if (rMove > bMove)
				{
					next.ry -= dy[i];
					next.rx -= dx[i];
				}
				else
				{
					next.by -= dy[i];
					next.bx -= dx[i];
				}
			}
			//방문하지 않았으면 q에 push
			//이동 횟수를 한번 증가시키고 q에 push
			next.cnt++;
			if (next.cnt >= 10)continue;
			if (!visited[next.ry][next.rx][next.by][next.bx])
			{
				visited[next.ry][next.rx][next.by][next.bx];
				q.push(next);
			}
		}
	}
	printf("-1\n");
	return 0;
}