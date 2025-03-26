#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n,m,s;
    cin>>n>>m>>s;
    int left=0,right=0;
    vector<int>w(n);
    vector<int>v(n);
    for(int i=0;i<n;i++){
    cin>>w[i]>>v[i];
    right=max(right,w[i]);   
    }
    ll ans=9223372036854775807;
    vector<int>l(m);
    vector<int>r(m);
    for(int i=0;i<m;i++){
        cin>>l[i]>>r[i];
    }
    while (left<=right)
    {
        int mid=(left+right)>>1;
        vector<ll>pre1(n+1);
        vector<ll>pre2(n+1);
        for(int i=0;i<n;i++){
            pre1[i+1]=pre1[i]+(w[i]>=mid?1:0);
            pre2[i+1]=pre2[i]+(w[i]>=mid?v[i]:0);
        }
        ll res=0;
        for(int i=0;i<m;i++){
            res+=(pre1[r[i]]-pre1[l[i]-1])*(pre2[r[i]]-pre2[l[i]-1]);
        }
        ans=min(ans,abs(res-s));
        if(res>s)
            left=mid+1;
        if(res==s)
            break;
        if(res<s)
            right=mid-1;
    }
    cout<<ans<<'\n';
    
}
int main(){
    solve();
    return 0;
}