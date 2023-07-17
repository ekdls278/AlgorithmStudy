#include<bits/stdc++.h>
using namespace std;
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int a[104][104];
bool visited[104][104];
int m,n,k;
int X,Y,X2,Y2;
int tmp;
int ret;
vector<int> vec;
int area;
void dfs(int y, int x){
	visited[y][x]=1;
	for(int i=0; i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny < 0|| ny >=m || nx < 0 || nx>=n)continue;
		if(a[ny][nx]==0&&!visited[ny][nx]){
			dfs(ny,nx); area++;
		}
	}	
	return;
	
}
int main(){
	cin>>m>>n>>k;
	for(int i=0; i<k;i++){
		cin>>X>>Y;
		cin>>X2>>Y2;
		for(int j=Y; j<Y2;j++){
			for(int u=X;u<X2;u++){
				a[j][u]=1;
			}
		}
 }	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==0 && !visited[i][j]){
				area=1;
				dfs(i,j);
				ret++;
				vec.push_back(area);
			}	
		}
	}
	cout<<ret<<'\n';
	sort(vec.begin(),vec.end());
	for(auto it : vec){
		cout<<it<<" ";
	}
	
	return 0;
}