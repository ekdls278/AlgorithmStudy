#include<iostream>
#include<algorithm>

using namespace std;
int N, K;
int arr[100003];
int tmp;
int MAX = -10000;
int main() {
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> tmp;
        arr[i] = tmp + arr[i - 1];
    }
    for (int j = K; j <= N; j++) {
        MAX = max(MAX, arr[j] - arr[j - K]);
    }
    
    cout << MAX;
    return 0;
}