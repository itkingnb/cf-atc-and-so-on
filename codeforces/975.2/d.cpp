#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#include<cstring>
#include<bits/stdc++.h>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;// 2147483647
int minint = INT_MIN;// -2147483648
long long maxll = LLONG_MAX;// 9223372036854775807
long long minll = LLONG_MIN;// -9223372036854775808
ll jc(ll n){
    if(n==1||n==0)
    return (ll)1;
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
ll qpow(ll a, ll k, ll p)
{
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = (ll)res * a % p;
        a = (ll)a * a % p;
        k >>= 1;
    }
    return res;
}
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    deque<pii>q,p;
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]-=i;
        if(q.empty()||a[i]<=q.front().first){
            q.push_front({a[i],i});
        }
        a[i]+=i;
    }
    int ans=0;
    if(a[0]>0&&q.front().first>0){
        ans++;
        if(a[0]==q.front().first&&q.front().second==0){
            q.pop_front();
        }
    }
    p.push_front({a[0],0});
    for(int i=1;i<n;i++){
        int d=min(abs(i-q.front().second),abs(i-p.front().second));
        if(q.front().first+(q.front().second-i)>=0&&p.front().first-(i-p.front().second)>=0&&d+abs(p.front().second-i-q.front().second)<=max(a[p.front().second],a[q.front().second])){
            ans++;
        }
        if(p.front().first-i>=a[i]){
            p.push_front({a[i],i});
        }
        while(!q.size()&&q.front().second<i){
            q.pop_front();
        }
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}