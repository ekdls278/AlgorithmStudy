#include<bits/stdc++.h>

using namespace std;

int cnt[26];

int main(){
	string str;
	cin>>str;
	for(auto it : str){
		cnt[it-'a']++;
	}
	for(auto it : cnt){
		cout<<it<<' ';
	}
}