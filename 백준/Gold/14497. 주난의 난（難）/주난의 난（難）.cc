#include<bits/stdc++.h>

#define MAX 302
using namespace std;

int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };


int N, M;
int x1, Y1, x2, y2;
int board[MAX][MAX];
int visited[MAX][MAX];
int ans;
string str;

int main()
{
	cin >> N >> M;
	cin >> Y1 >> x1 >> y2 >> x2;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		for (int j = 0; j <= str.size(); j++)
		{
			board[i][j] = str[j] - '0';
		}
	}
	while (1)
	{
		ans++;
		vector<pair<int, int>> vec;
		queue<pair<int, int>> q;
		memset(&visited[0][0], 0, sizeof(visited));
		vec.clear();
		q.push({ Y1 - 1, x1 - 1 });
		visited[Y1 - 1][x1 - 1] = 1;

		while (!q.empty())
		{
			
			int y, x;
			tie(y, x) = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny >= N || ny < 0 || nx >= M || nx < 0)continue;
				if (visited[ny][nx])continue;

				if (ny == y2 - 1 && nx == x2 - 1)
				{
					//종료
					printf("%d\n", ans);
					return 0;
				}

				visited[ny][nx] = 1;

				if (board[ny][nx] == 1)
				{
					vec.push_back({ ny, nx });
				}
				else
				{
					q.push({ ny,nx });
				}


			}
		}
		for (auto it : vec)
		{
			board[it.first][it.second] = 0;
		}


	}

	return 0;
}