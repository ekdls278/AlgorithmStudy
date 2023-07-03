#include<bits/stdc++.h>

using namespace std;
int N;
string input;
int ret;
int main(){
    cin>>N;
    for(int i=0; i<N ; i++){
        stack<char> stc;
        cin>>input;
        for(auto it : input){
            if(stc.size() && stc.top()==it)stc.pop();
            else stc.push(it);
        }
        if(stc.size()==0)ret++;
    }
    cout<<ret;
    return 0;
}