#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll a,b;
    cin>>a>>b;
    ll ans=0;
    for(int i=31;i>=0;i--){
        if(((a>>i)&1)&&((b>>i)&1))
        ans+=1<<i;
    }
    ans==0?cout<<1<<'\n':cout<<ans<<'\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
    solve(); 
    }
    return 0;
}