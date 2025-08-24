#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void yes(){
    cout<<"yes"<<'\n';
}
void no(){
    cout<<"no"<<'\n';
}
void AUTO_AC_MACHINE(){
    int n,m;
    cin>>n>>m;
    vector<ll>a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int i=0,j=0;
    while(i<n&&j<m){
        if(a[i]>=b[j]){
            i++;
            j++;
        }else{
            i++;
        }
    }
    if(j==m){
        cout<<0<<'\n';
        return ;
    }
    auto check=[&](ll x)->bool{
        vector<vector<ll>>dp(m+1,vector<ll>(2,1e9));
        int idx=0;
        dp[0][0]=0;dp[0][1]=0;
        for(int i=0;i<m;i++){
            for(idx;idx<n;idx++){
                if(a[idx]>=b[i]){
                    dp[i+1][0]=++idx;
                    break;
                }
            }                
            if(x>=b[i]){
                dp[i+1][1]=dp[i][0];
            }
            for(ll j=dp[i][1];j<n;j++){
                if(a[j]>=b[i]){
                    if(x>=b[i]){
                        dp[i+1][1]=min({dp[i][0],j+1,dp[i+1][1]});
                    }else{
                        dp[i+1][1]=min(dp[i+1][1],j+1);
                    }
                    break;
                }
            }
        }
        return dp[m][1]<=n+1;
    };
    ll lo=0,hi=1e10;
    while(lo<hi){
        ll mid=(lo+hi)>>1;
        // mid=3;
        if(check(mid)){
            // lo=mid+1;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    if(hi>1e9){
        cout<<-1<<'\n';
    }else{
        check(hi)?cout<<hi<<'\n':cout<<hi+1<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        AUTO_AC_MACHINE();
    }
}
