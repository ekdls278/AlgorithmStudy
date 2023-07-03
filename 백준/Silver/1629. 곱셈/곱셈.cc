#include <iostream>

typedef long long ll;
using namespace std;
ll A, B, C;

//A를 B번 곱하는 함수 go
ll go(ll A, ll B)
{
	if (B == 1)return A % C;

	ll ret = go(A, B / 2);
	ret = (ret * ret) % C;
	if (B % 2) ret = (ret * A) % C;
	return ret;
}

int main()
{
	cin >> A >> B >> C;
	cout << go(A, B) << '\n';
	return 0;
}