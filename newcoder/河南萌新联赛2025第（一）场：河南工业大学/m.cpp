#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=n+n-1;
    vector<bool>vis(n,0);
    auto check=[&](int x)->bool{
        vector<int>dp1(4,1),dp2(4,1);
        vector<int>t={a[x-3],a[x-2],a[x-1],a[x]};
        int mx=0;
        for(int i=1;i<4;i++){
            for(int j=i-1;j>=0;j--){
                if(t[i]>=t[j]){
                    dp1[i]=max(dp1[i],dp1[j]+1);
                    mx=max(mx,dp1[i]);
                }
                if(t[i]<=t[j]){
                    dp2[i]=max(dp2[i],dp2[j]+1);
                    mx=max(mx,dp2[i]);
                }
            }
        }
        return mx<3;
    };
    for(int i=2;i<n;i++){
        if(a[i]>=a[i-1]&&a[i-1]>=a[i-2]||a[i]<=a[i-1]&&a[i-1]<=a[i-2]){
            vis[i]=1;
        }else{
            // cout<<i<<'\n';
            ans++;
        }
    }
    for(int i=3;i<n;i++){
        if(vis[i]){
            continue;
        }else{
            ans+=check(i);
        }
    }
    cout<<ans;
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