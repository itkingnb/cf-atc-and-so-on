#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]=='p'){
            cout<<'q';
        }else if(s[i]=='q'){
            cout<<'p';
        }else{
            cout<<s[i];
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}