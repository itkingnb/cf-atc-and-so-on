#include<bits/stdc++.h>
using  namespace std;
#define ll long long
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>asks(m),know(k);
    int now=1;
    int tag=0;
    for(int i=0;i<m;i++){
        cin>>asks[i];
    }
    for(int i=0;i<k;i++){
        cin>>know[i];
        if(!tag&&know[i]!=now){
            tag=now;
        }
        now++;
    }
    if(!tag&&k<n){
        tag=now;
    }
    string ans;
    for(int i=0;i<m;i++){
        if(k<n-1||(tag&&tag!=asks[i])){
            ans.push_back('0');
        }else{
            ans.push_back('1');
        }
    }
    cout<<ans;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}