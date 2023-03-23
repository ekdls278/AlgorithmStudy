#include <stdio.h>
#include<vector>
#include<queue>
#pragma warning (disable:4996)
using namespace std;

int dy[] = { 0, -1, 0, 1 };
int dx[] = { -1, 0, 1, 0 };

struct tD {
	int time;
	char direction;
};

struct YX {
	int y;
	int x;
};

int n, k, c, r, t;
vector<vector<int>> vec;
queue<tD> timeDirec;
int main()
{

#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\3190.txt", "r", stdin);
#endif
	scanf("%d", &n);
	scanf("%d", &k);
	vec.resize(n + 2, vector<int>(n + 2, 0));
	//시작 위치 1,1임
	while (k--)
	{
		scanf("%d %d", &c, &r);
		vec[c][r] = 1;
	}
	scanf("%d", &t);
	int a;
	char b;
	while (t--)
	{
		scanf("%d %c", &a, &b);
		timeDirec.push({ a,b });
	}
	int ret = 0;
	int d = 2;
	int y = 1, x = 1;
	queue<YX> tail;
	tail.push({ 1,1 });
	vec[1][1] = 2;
	while (1)
	{
		//진행 방향으로 1칸 전진
		int ny = y + dy[d];
		int nx = x + dx[d];
		//벽에 부딪히거나 몸이면 break;
		if (ny > n || ny <= 0 || nx > n || nx <= 0 || vec[ny][nx] == 2)break;

		//사과면
		tail.push({ ny, nx });
		if (vec[ny][nx] == 1)
		{
			vec[ny][nx] = 2;
		}
		//사과가 아니면
		else if (vec[ny][nx] != 1)
		{
			//꼬리 끌어오기
			vec[ny][nx] = 2;
			YX back = tail.front();
			tail.pop();
			vec[back.y][back.x] = 0;
		}


		ret++;
		//방향 돌리기
		if (!timeDirec.empty() && timeDirec.front().time == ret)
		{
			//시계방향 90도 회전
			if (timeDirec.front().direction == 'D')
			{
				d = (d + 1)%4;
			}
			//반시계 방향 90도 회전
			else
			{
				d = (d + 3) % 4;
			}
			timeDirec.pop();
		}
		y = ny;
		x = nx;
	}

	printf("%d", ret+1);


	return 0;
}