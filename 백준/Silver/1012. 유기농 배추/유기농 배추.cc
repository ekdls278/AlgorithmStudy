#include<bits/stdc++.h>

using namespace std;

int t;
int m,n,k;
int a,b;
int arr[54][54];
bool visited[54][54];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int y, int x){
	visited[y][x]=1;
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny<0||ny>=n||nx<0||nx>=m)continue;
		if(arr[ny][nx]==1 && !visited[ny][nx]){
			dfs(ny,nx);
		}
	}
	return;
	
}

int main(){
	cin>>t;
	for(int i=0; i<t; i++){
		cin>>m>>n>>k;
		int ret=0;
		memset(arr,0,sizeof(arr));
		memset(visited,false,sizeof(visited));
		for(int j=0; j<k; j++){
			cin>>a>>b;
			arr[b][a]=1;
		}
		for(int q=0;q<n;q++){
			for(int w=0;w<m;w++){
				if(arr[q][w]==1 && !visited[q][w]){
				
				ret++; dfs(q,w);
				}
			}
		}
		cout<<ret<<'\n';
		
	}
	
	
	return 0;
}