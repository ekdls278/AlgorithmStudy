#include<stdio.h>
#pragma warning(disable:4996)
#define PIV (1<<20)
using namespace std;

long long tree[PIV * 2];

void update(long long n, long long value)
{
	n += PIV - 1;
	tree[n] = value;

	while (n >>= 1)
	{
		tree[n] = tree[n * 2] + tree[n * 2 + 1];
	}
}

long long query(int l, int r)
{
	long long ret = 0;
	l += PIV - 1, r += PIV - 1;
	while (l <= r)
	{
		if (l % 2 == 1)ret += tree[l++];
		if (r % 2 == 0)ret += tree[r--];
		l/=2, r/=2;
	}

	return ret;
}

int main()
{
	long long tmp;
	int n, m, k;
	long long a, b;
	long long c;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1; i<=n; i++)
	{
		scanf("%lld", &tmp);
		update(i, tmp);
	}
	for (int j = 0; j < m + k; j++)
	{
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a == 1)
		{
			update(b, c);
		}
		else
		{
			printf("%lld\n", query(b, c));
		}
	}
	return 0;
}