#include<bits/stdc++.h>

using namespace std;

	
int main(){
	string str;
	cin>>str;
	string tmp = str;
	
	reverse(tmp.begin(), tmp.end());
	if(str == tmp)cout<<1;
	else cout<<0;
	
	
	return 0;
}