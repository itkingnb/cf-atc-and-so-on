#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n,k;
    cin>>n>>k;
    ll ans=0;
    // vector<int>a={1,2,3,4,5};
    // vector<int>a={2,4,7,9,11};
    // for(int i=0;i<5;i++){
    //     for(int j=i+1;j<5;j++){
    //         ans+=gcd(abs(a[j]-a[i]),12);
    //     }
    // }
    // cout<<ans;
    for(int i=1;i<=k;i++){
        cout<<i<<" ";
    }
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