#include<stdio.h>
#include<vector>
#include<queue>
#define MAX 1001
#define INF 1e9
#pragma warning (disable:4996)
using namespace std;

struct edge
{
	int end;
	int cost;
	bool operator<(const edge& b) const
	{
		return cost > b.cost;
	}
};

int n, e;
int dist[MAX];
vector<vector<edge>> adj;

void dijk(int startNode)
{
	priority_queue<edge> pq;

	for (int i = 1; i <= n; i++)
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
		
		if (nowCost > dist[nowVertex])continue;

		for (int i = 0; i < adj[nowVertex].size(); i++)
		{
			edge next = adj[nowVertex][i];
			if (dist[next.end] > dist[nowVertex] + next.cost)
			{
				dist[next.end] = dist[nowVertex] + next.cost;
				pq.push({ next.end, dist[next.end] });
			}

		}

	}
	
}

int main()
{
	scanf("%d%d", &n, &e);
	adj.resize(n + 1);
	int a = 0, b = 0, c = 0;
	while (e--)
	{
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back({ b,c });
	}
	int startNode = 0, endNode = 0;
	scanf("%d%d", &startNode, &endNode);
	dijk(startNode);
	printf("%d", dist[endNode]);
}