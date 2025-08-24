#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n,m;
    cin>>n>>m;
    cout<<n*(n-1)-m;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
    
}