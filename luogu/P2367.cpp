#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n,p;
    cin>>n>>p;
    vector<int>a(n+1,0);
    vector<int>d(n+2,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d[i]=a[i]-a[i-1];
    }
    for(int i=0;i<p;i++){
        int l,r,k;
        cin>>l>>r>>k;
        d[l]+=k;
        d[r+1]-=k;
    }
    int ans=1e9;
    for(int i=1;i<=n;i++)
    ans=min(ans,d[i]+d[i-1]),d[i]=d[i]+d[i-1];
    cout<<ans;
}
int main(){
    solve();
    return 0;
}