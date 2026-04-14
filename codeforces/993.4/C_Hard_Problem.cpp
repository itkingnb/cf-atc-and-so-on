#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int m,a,b,c;
    cin>>m>>a>>b>>c;
    // cerr<<m<<a<<b<<c;
    int ans=0;
    int mx=min(a,m);
    int m1=m;
    a-=mx;
    m1-=mx;
    ans+=mx;
    mx=min(b,m);
    m-=mx;
    b-=mx;
    ans+=mx;
    mx=min(c,m1);
    ans+=mx;
    c-=mx;
    mx=min(c,m);
    ans+=mx;
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        cout<<'\n';
    }
}