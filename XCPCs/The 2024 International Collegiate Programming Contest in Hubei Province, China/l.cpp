#include<bits/stdc++.h>
#define ll long long
#define int ll
#define N (int)1e7+10
using namespace std;
vector<int>prim;
bool ok[N];
int minp[N];
void init(){
    for(int i=2;i<N;i++){
        if(!ok[i]){
            prim.push_back(i);
        }
        for(int j=0;j<prim.size();j++){
            if(i*prim[j]<N){
                ok[i*prim[j]]=true;
                minp[i*prim[j]]=min(i,prim[j]);
            }else{
                break;
            }
            if(i%prim[j]==0){
                break;
            }
        }
    }
}
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
    ll a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0;
        return ;
    }
    if(__gcd(a,b)>1){
        if((a*b)/__gcd(a,b)!=a&&(a*b)/__gcd(a,b)!=b)
            cout<<a+b;
        else
            cout<<max(a,b);
        return ;
    }
    if(!ok[a]&&!ok[b]){
        cout<<min(a*b,2*(a+b));
        return ;
    }
    ll ans=1e18;
    if(ok[a]){
        ans=min(ans,a+minp[a]*b);
        if(minp[a]!=2){
            if(minp[b]==2)
                ans=min(ans,2*minp[a]+a+b);
            else{
                ans=min({ans,2*minp[a]+a+2*(minp[b]?minp[b]:(ll)1e18)+b,2*minp[a]+a+2*b});
            }
        }
    }
    if(ok[b]){
        ans=min(ans,b+minp[b]*a);
        if(minp[b]!=2){
            if(minp[a]==2){
                ans=min(ans,2*minp[b]+b+a);
            }else{
                ans=min({ans,2*minp[b]+b+2*(minp[a]?minp[a]:(ll)1e18)+a,2*minp[b]+b+2*a});
            }
        }
    }
    if(ok[a]&&ok[b]){
        ans=min(ans,a+b+minp[a]*minp[b]);
    }
    ans=min(2*(a+b),ans);
    ans=min(ans,a*b);
    cout<<ans;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    init();
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}