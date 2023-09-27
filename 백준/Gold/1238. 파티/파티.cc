#include<iostream>
#include<queue>
#include<algorithm>
#pragma warning(disable:4996)

#define MAX 1001
#define INF 1987654321

using namespace std;

struct edge {
	int end;
	int cost;

	bool operator<(const edge& b)const {
		return cost > b.cost;
	}
};

int N, M, X;
vector<vector<edge>> adj;
int dist[MAX];


void Input()
{
	cin >> N >> M >> X;
	adj.resize(N + 1);
	int u, v, w;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
	}
}

int dijk(int s, int x)
{
	priority_queue<edge> pq;
	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
	}
	pq.push({ s, 0 });
	dist[s] = 0;

	while (!pq.empty())
	{
		edge now = pq.top();
		pq.pop();

		if (dist[now.end] != now.cost)continue;

		int len = adj[now.end].size();
		for (int i = 0; i < len; i++)
		{
			edge next = adj[now.end][i];

			if (dist[next.end] > dist[now.end] + next.cost)
			{
				dist[next.end] = dist[now.end] + next.cost;
				pq.push({ next.end, dist[next.end] });
			}
		}
	}
	if (dist[x] != INF)return dist[x];
	return -1;

}

int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\1238.txt", "r", stdin);
#endif
	Input();
	int ret = -1;
	for (int i = 1; i <= N; i++)
	{
		if (i == X)continue;
		int tmp = dijk(i, X) + dijk(X, i);
		ret = max(ret, tmp);
	}
	cout << ret << "\n";

	return 0;
}