#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

struct Lecture
{
	int cost;
	int dead;

	bool operator < (const Lecture b) const {
		return dead < b.dead;
	}
};

int n;
vector<Lecture> vec;
priority_queue<int, vector<int>, greater<int>> pq;
int ret;

void Input()
{
	cin >> n;
	int p, d;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> d;
		vec.push_back({ p,d });
	}
	sort(vec.begin(), vec.end());

}

void Solution()
{
	for (int i = 0; i < n; i++)
	{
		pq.push(vec[i].cost);
		if (pq.size() > vec[i].dead) {
			pq.pop();
		}
	}

	while (pq.size())
	{
		ret += pq.top();
		pq.pop();
	}
}

int main()
{
	Input();
	Solution();
	cout << ret;

	return 0;
}