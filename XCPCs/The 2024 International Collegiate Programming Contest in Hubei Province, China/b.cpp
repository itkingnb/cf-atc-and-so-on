#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
ll qpow(ll a,ll x,ll mod){
    ll res=1;
    while(x){
        if(x&1)
            res=res*a%mod;
        a*=a;
        a%=mod;
        x>>=1;
    }
    return res;
}
void solve(){
    int n;
    cin>>n;
    vector<pii>a(n);
    long double ans=1e18;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    auto check=[&](int i,int j,int k)->bool{
        return (a[k].second-a[i].second)*(a[j].first-a[i].first)!=(a[j].second-a[i].second)*(a[k].first-a[i].first);
    };
    auto get=[&](int i,int j,int k)->long double{
        int x1=a[k].first-a[i].first,x2=a[j].first-a[i].first,y=a[k].second-a[i].second,yy=a[j].second-a[i].second;
        return (long double)(1.0/2)*(long double)(abs(x1*yy-x2*y));
    };
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(check(i,j,k)){
                    ans=min(ans,get(i,j,k));
                }
            }
        }
    }
    ans>=1e17?cout<<-1:cout<<ans;
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