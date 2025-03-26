#include<bits/stdc++.h>
using  namespace std;
#define ll long long
void solve(){
    ll n,lo,hi;
    cin>>n>>lo>>hi;
    vector<ll>a(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(),a.end());
    ll ans=0;
    for(int i=0;i<n;i++){
        if(sum<=lo){
            break;
        }
        ll l=sum-lo-a[i],h=sum-a[i]-hi;
        ans+=max(0LL,(upper_bound(a.begin()+i+1,a.end(),l)-a.begin()-1)-(lower_bound(a.begin()+i+1,a.end(),h)-a.begin())+1);
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