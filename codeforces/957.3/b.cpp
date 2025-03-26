#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
int jc(int n){
    if(n==1||n==0)
    return 1;
    else
    return n*jc(n-1);
}
void yes(){
    cout<<"Yes";
}
void no(){
    cout<<"No";
}
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(k,0);
    int mx=0;
    int ii=0;
    for(int i=0;i<k;i++){
    cin>>a[i];
    mx=max(mx,a[i]);
    if(a[i]==mx)
    ii=i;
    }
    ll ans=n-mx;
    for(int i=0;i<k;i++){
        if(i!=ii)
        ans+=(a[i]-1);
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