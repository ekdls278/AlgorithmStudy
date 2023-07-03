#include<bits/stdc++.h>

using namespace std;


int n,m,tmp,y,x;
int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

int main(){
	cin>>n>>m;
	vector<vector<int>> vec(n);
	vector<vector<int>> visited(n,vector<int>(m));
	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			scanf("%1d", &tmp);
			vec[i].push_back(tmp);
		}
	}
	
	queue<pair<int, int>> q;
	q.push({0,0});
	visited[0][0]=1;
	while(q.size()!=0){
		tie(y,x) = q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int ny = y+dy[i];
			int nx = x+dx[i];
			if(ny>=n || nx>=m || ny<0 || nx<0 || visited[ny][nx] || vec[ny][nx]==0)continue;
			if(vec[ny][nx] == 1){
				visited[ny][nx]=visited[y][x]+1;
				q.push({ny,nx});	
			}
		}
	}
	cout<<visited[n-1][m-1];
	return 0;
}

