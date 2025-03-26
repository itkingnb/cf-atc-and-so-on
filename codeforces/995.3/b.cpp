#include<bits/stdc++.h>
using  namespace std;
#define ll long long
void solve(){
    ll n,a,b,c;
    cin>>n>>a>>b>>c;
    ll sum=a+b+c;
    ll ans=n/sum*3;
    sum=n/sum*sum;
    if(sum<n){
        ans++;
        sum+=a;
    }
    if(sum<n){
        ans++;
        sum+=b;
    }
    if(sum<n){
        ans++;
        sum+=c;
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