#include<iostream>
#include<queue>
#include<vector>

#define INF 1987654321
#define MAX 200000 +1

using namespace std;

int d[] = { -1, 1 };

struct edge
{
	int end;
	int cost;

	bool operator<(const edge& b)const {
		return cost > b.cost;
	}
};


int N, K;
int visited[MAX];
int dist[MAX];


//위치 X
//1.1초 X-1
//2. 1초 X+1
//3. 0초 2*X

void Input()
{
	cin >> N >> K;
}

// 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
// x	   3 2x						  4  5

void dijk(int n)
{
	priority_queue<edge> pq;
	fill(dist, dist + MAX, INF);
	
	pq.push({ n, 0 });
	dist[n] = 0;

	while (!pq.empty())
	{
		edge now = pq.top();
		pq.pop();

		if (dist[now.end] != now.cost)continue;

		for (int i = 0; i < 3; i++)
		{
			edge next = now;
			if (i == 2)
			{
				next.end *= 2;
			}
			else
			{
				next.end += d[i];
				next.cost++;
			}

			if (next.end < 0 || next.end > 100000)
				continue;

			if (dist[next.end] > next.cost)
			{
				dist[next.end] = next.cost;
				pq.push({next.end, dist[next.end]});
			}


		}
	}
}

int main()
{
	Input();
	dijk(N);
	cout << dist[K] << "\n";

	return 0;
}