#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin>>n;
    vector<ll>a(n);
    ll mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    cout<<mx;
    return ;
    vector<bool>vis(n,false);
    ll ans=0;
    for(int i=40;i>=0;i--){
        for(int j=0;j<n;j++){   
            if(!vis[a[j]]&&((a[j]>>i)&1)){
                // ans+=
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}