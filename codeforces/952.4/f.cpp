#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
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
    int h,n;
    cin>>h>>n;
    ll ans=0;
    ll leijia=0;
    set<pair<ll,int>>m;
    vector<int>a(n,0);
    vector<int>c(n,0);
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        m.insert({1,i});
    }
    while (h>0)
    {
        auto [i,j]=*m.begin();
        ans=i;
        h-=a[j];
        m.erase({i,j});
        m.insert({i+c[j],j});
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