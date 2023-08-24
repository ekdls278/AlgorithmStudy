#include <iostream>


#define MAX 100000 + 2
#pragma warning(disable:4996)

using namespace std;

int N, M;
int arr[MAX];


void Input()
{
	cin >> N >> M;
	int tmp = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		arr[i] = arr[i-1] + tmp;
	}
}

void Solution()
{
	int s, e;
	for (int i = 0; i < M; i++)
	{
		cin >> s >> e;
		cout << arr[e] - arr[s-1]<<"\n";
	}
}


int main(int argc, char** argv)
{
#ifdef _DEBUG
	freopen("C:\\Users\\ekdls\\Desktop\\study\\1249.txt", "r", stdin);
#endif

    cin.tie(NULL);
	cin.sync_with_stdio(false);
	Input();
	Solution();


	
	return 0;
}