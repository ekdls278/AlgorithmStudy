#include<bits/stdc++.h>

using namespace std;

int cnt[103];
int A,B,C;
int st;
int et;
int ret=0;
int main(){
    cin>>A>>B>>C;
    for(int i=0;i<3;i++){
        cin>>st>>et;
        for(int j=st;j<et;j++)cnt[j]++;
    }
    for(int it : cnt){
        if(it==1)ret+=A;
        else if(it==2)ret= ret + B*2;
        else if(it==3)ret= ret + C*3;
    }
    
    cout<<ret;
    
    
    return 0;
}