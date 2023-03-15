#include <string>
#include <vector>
#define MAX 105
#define INF 7654321
using namespace std;

int arr[MAX][MAX];

void floyd(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
}


int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = INF;
        }
    }

    for (auto it : results)
    {
        arr[it[0]][it[1]] = 1;
    }

    floyd(n);
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] != INF || arr[j][i] != INF)
            {
                cnt++;
            }
        }
        if (cnt == n - 1)answer++;

    }

    printf("%d", answer);



    return answer;
}