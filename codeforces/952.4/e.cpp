#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#define ll long long
using namespace std;
int jc(int n){
    if(n==1||n==0)
    return 1;
    else
    return n*jc(n-1);
}
void yes(){
    cout<<"Yes\n";
}
void no(){
    cout<<"No\n";
}
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
void solve(){
    ll x,y,z,k;
    cin>>x>>y>>z>>k;
    ll ans=0;
    for(ll i=1;i<=x;i++){
        for(ll j=1;j<=y;j++){
            if(k%(i*j)||k/(i*j)>z)
            continue;
            ll m=(ll)(x-i+1)*(y-j+1)*(z-(k/(i*j))+1);
            ans=max(ans,m);
        }
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}