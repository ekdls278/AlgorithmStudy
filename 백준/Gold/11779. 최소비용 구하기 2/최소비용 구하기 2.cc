#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 1000+1
#define INF 1987654321

using namespace std;

struct edge
{
	int end;
	int cost;

	bool operator<(const edge& b)const {
		return cost > b.cost;
	}
};

int N, M;
vector<vector<edge>> adj;
int dist[MAX];
int route[MAX];
int st, ed;

void Input()
{
	int u, v, w;
	cin >> N >> M;
	adj.resize(N + 1);
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		adj[u].push_back({ v,w });
	}
	cin >> st >> ed;
}


void dijk(int s)
{
	priority_queue<edge> pq;
	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
	}
	pq.push({ s, 0 });
	dist[s] = 0;
	route[s] = -1;

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
				route[next.end] = now.end;
				pq.push({ next.end, dist[next.end] });
			}

		}
	}



}

int main()
{
	Input();
	dijk(st);
	vector<int> answer;
	answer.push_back(ed);
	int i = route[ed];
	for (; i != -1; i = route[i])
	{
		answer.push_back(i);
	}
	cout << dist[ed] << "\n" << answer.size() << "\n";
	reverse(answer.begin(), answer.end());
	for (auto it : answer)
	{
		cout << it << " ";
	}
}