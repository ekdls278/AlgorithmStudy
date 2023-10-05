#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>


using namespace std;


int N;
vector<pair<int, int>> vec;
int ret;

void Input()
{
	int d, c;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> d >> c;
		vec.push_back({ d,c });
	}
	sort(vec.begin(), vec.end());

}

void Solution()
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < vec.size(); i++)
	{
		pq.push(vec[i].second);
		if (pq.size() > vec[i].first) {
			pq.pop();
		}
	}

	while (!pq.empty())
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