#include<iostream>
#define MAX 1000001
typedef long long ll;
using namespace std;

ll n;
ll A[MAX];
ll B, C;
ll ret;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	cin >> B >> C;
	for (int i = 0; i < n; i++)
	{
		ll tmp = A[i] - B;
		if (tmp > 0)
		{
			ll a = tmp / C;
			ll b = tmp % C ? 1 : 0;

			ret += 1 + a + b;
		}
		else
		{
			ret += 1;
		}
	}

	cout << ret << '\n';

}