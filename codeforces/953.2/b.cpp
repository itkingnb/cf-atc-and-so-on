#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
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
ll leijia(ll a,ll b){
    return (a+b)*(b-a+1)/2;
}
int solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll k=n;
    ll left=0;
    if(b>a){
        left=b-a;
        left++;
        n-=left;
        if(n>=0)
        cout<<n*a+leijia(a,b);
        else
        cout<<leijia(b-k+1,b);
    }
    else{
        cout<<n*a;
    }
    return 0;
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