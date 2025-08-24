#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;
void solve(){
    ll t;
    cin>>t;
    vector<ll>ansa(t+10),ansb(t+10);
    ansa[0]=1;ansa[1]=1;ansa[2]=3;
    ansb[0]=0;ansb[1]=1;ansb[2]=2;
    for(int i=3;i<=t;i++){
        ansa[i]=((ansa[i-1]*ansa[i-1])%mod+(2*ansa[i-1]*ansb[i-1])%mod)%mod;
        ansb[i]=((ansa[i-1]*ansa[i-1])%mod+(ansb[i-1]*ansb[i-1])%mod)%mod;
    }
    cout<<ansa[t]<<" "<<ansb[t]<<'\n';
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