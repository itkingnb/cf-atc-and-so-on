#include<bits/stdc++.h>
using namespace std;
#define PI 3.141592
void solve(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int x,y;
    cin>>x>>y;
    int t=(a[x]+a[y]+1)>>1;
    int mn=1e9;
    int ans=-1;
    for(int i=1;i<=n;i++){
        if(abs(t-a[i])<mn){
            mn=abs(t-a[i]);
            ans=i;
        }
    }
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while (t--){
        solve();
    }
    
}