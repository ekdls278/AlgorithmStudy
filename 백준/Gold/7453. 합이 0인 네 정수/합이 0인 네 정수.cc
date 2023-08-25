#include<stdio.h>
#include<algorithm>
#pragma warning (disable:4996)
#define MAX 4000
using namespace std;

int n;
long long A[MAX], B[MAX], C[MAX], D[MAX];
long long AB[MAX * MAX], CD[MAX*MAX];
long long ret;
int main()
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\7453.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)scanf("%lld %lld %lld %lld", &A[i], &B[i], &C[i], &D[i]);

	int idx = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			AB[idx] = A[i] + B[j], CD[idx] = C[i] + D[j];
			idx++;
		}
	}
	sort(AB, AB + idx);
	sort(CD, CD + idx);



	int l = 0, r = idx - 1;


	while (l < idx && r >= 0)
	{
		if (AB[l] + CD[r] == 0)
		{
			long long cntAB = 0;
			int sameLeft = l;
			while (sameLeft < idx && AB[sameLeft] == AB[l])
			{
				cntAB++;
				sameLeft++;
			}
			l = sameLeft;

			long long cntCD = 0;
			int sameRight = r;

			while (sameRight >= 0 && CD[sameRight] == CD[r])
			{
				cntCD++;
				sameRight--;
			}
			r = sameRight;
			ret += cntAB * cntCD;
		}
		else if (AB[l] + CD[r] < 0)l++;
		else r--;
	}

	printf("%lld", ret);

	return 0;
}