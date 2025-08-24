#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin>>n;
    vector<ll>a(n);
    vector<ll>pre(n,-2e18);
    ll mn=0,sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        if(i){
            pre[i]=max(pre[i-1],sum-mn);
        }else{
            pre[i]=sum-mn;
        }
        mn=min(mn,sum);
    }
    vector<ll>suf(n,a[n-1]);
    sum=a[n-1];
    mn=min(0LL,sum);
    for(int i=n-2;i>=0;i--){
        sum+=a[i];
        suf[i]=max(suf[i+1],sum-mn);
        mn=min(mn,sum);
    }
    ll ans=-2e18;
    for(int i=0;i<n-1;i++){
        ans=max(ans,pre[i]+suf[i+1]);
    }
    cout<<ans;

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