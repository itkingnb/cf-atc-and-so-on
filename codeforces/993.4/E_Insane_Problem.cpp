#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll k,l1,r1,l2,r2;
    cin>>k>>l1>>r1>>l2>>r2;
    ll ans=0;
    ll t=1;
    while(t<(ll)2e9){
        ans+=max(0LL,min(r1,r2/t)-max(l1,(l2+t-1)/t)+1);
        t*=k;
    }
    cout<<ans;
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