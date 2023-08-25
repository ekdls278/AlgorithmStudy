#include<stdio.h>
#include<vector>
#include<queue>
#define MAX 20003
#define INF 1987654321
#pragma warning(disable:4996)
using namespace std;

void djik(int n, int startNode);
struct edge
{
	int end;
	int cost;
	bool operator<(const edge& b) const
	{
		return cost > b.cost;
	}
};


int V, E, sv;
int u, v, w;
int dist[MAX];
vector<vector<edge>> adj;

int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\1753.txt", "r", stdin);
#endif
	scanf("%d%d%d", &V, &E, &sv);
	adj.resize(V + 1);
	for (int i = 0; i < E; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({ v, w });
	}
	djik(V, sv);
	for (int i=1; i<=V ; i++)
	{
		if (dist[i] >= INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
}

void djik(int n, int startNode)
{
	priority_queue<edge> pq;

	for (int i = 0; i <= n; i++)
	{
		dist[i] = INF;
	}

	pq.push({ startNode, 0 });
	dist[startNode] = 0;

	while (!pq.empty())
	{
		edge top = pq.top();
		pq.pop();

		int nowVertex = top.end;
		int nowCost = top.cost;

		int len = adj[nowVertex].size();
		for (int i = 0; i < len; i++)
		{
			edge next = adj[nowVertex][i];
			//다음에 갈 점의 최단거리보다, 지금 점 + 다음 점으로의 가중치가 더 작다면
			//최단거리를 갱신하고 큐에 해당 점을 넣는다.
			if (dist[next.end] > dist[nowVertex] + next.cost)
			{
				dist[next.end] = dist[nowVertex] + next.cost;
				pq.push({ next.end, dist[next.end] });
			}
		}
	}
}