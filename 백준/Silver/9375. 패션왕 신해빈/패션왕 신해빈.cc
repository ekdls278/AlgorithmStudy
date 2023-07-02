#include<bits/stdc++.h>

using namespace std;
int T;
int N;
string item;
string kind;
map<string, int> mp;
int main(){
	cin>>T;
	for(int i=0; i<T; i++){
		int sum = 1;
		mp.clear();
		cin>>N;
		for(int j=0; j<N; j++){
			cin>>item>>kind;
			mp[kind]++;
		}
		for(auto it : mp){
			sum = sum * (it.second + 1 );
		}
		cout<<sum-1<<'\n';
		
	}
	
	return 0;
}