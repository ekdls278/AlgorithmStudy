#include<bits/stdc++.h>

using namespace std;

int cnt[26];
vector<char> vec;
int N;
string str;

int main(){
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>str;
		cnt[str[0]-'a']++;
	}
	for(int i=0; i<26; i++){
		if(cnt[i]>=5)vec.push_back(i+'a');
	}
	if(vec.empty())cout<<"PREDAJA";
	else{
		for(auto it : vec){
			cout<<it;
		}
	}
	
	
	return 0;
}