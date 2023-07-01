#include<bits/stdc++.h>

using namespace std;

int N, K;
string tmp;
map<string, int>    Smap;
map<int, string>    Imap;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>N>>K;
    for(int i=1; i<=N;i++){
        cin>>tmp;
        Smap[tmp]=i;
        Imap[i]=tmp;
    }
    for(int j=0;j<K;j++){
        cin>>tmp;
        if(atoi(tmp.c_str())==0)
            cout<<Smap[tmp]<<"\n";
        else
            cout<<Imap[atoi(tmp.c_str())]<<"\n";
    }
    
    

    return 0;
}