#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll qpow(ll a,ll k,ll mod){
    ll res=1;
    while(k){
        if(k&1){
            res=(ll)res*a%mod;
        }
        a=a*a%mod;
        k>>=1;
    }     
    return res;
}
// ll fac[100];
// ll c(ll n,ll m){
//     return fac[n]/(fac[m]*fac[n-m]);
// }
void solve(){
    vector<pair<int,int>>a={{1,0},{1,1},{4,2},{5,3},{1,4},{4,5}};
    vector<int>cnt(6,0);
    vector<pair<int,int>>t;
    auto dfs=[&](auto &&self,int x)->void{
        if(x==6){
            vector<pair<int,int>>tmp=t;
            sort(tmp.begin(),tmp.end());
            // int num=1;
            for(int i=0;i<tmp.size();i++){
                cnt[tmp[i].second]+=max(i,1);
                // num++;
            }  
            
            return ;
        }
        self(self,x+1);
        t.push_back(a[x]);
        self(self,x+1);
        t.pop_back();
    };
    t.push_back(a[0]);
    dfs(dfs,1);
    t.pop_back();
    dfs(dfs,1);
    
    int res=0;
    for(int i=0;i<6;i++){
        cout<<cnt[i]<<" ";
        res+=a[i].first*cnt[i];
    }
    cout<<res;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    // fac[0]=1;
    // for(int i=1;i<100;i++){
    //     fac[i]=fac[i-1]*i;
    // }
    while(t--){
        solve();
        cout<<'\n';
    }
}