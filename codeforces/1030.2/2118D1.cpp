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
#define ll long long
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
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
    cout<<"YES\n";
}
void no(){
    cout<<"NO\n";
}
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b){
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
    int n,k;
    cin>>n>>k;
    vector<ll>p(n);
    vector<int>d(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    vector<vector<vector<int>>>st(n,vector<vector<int>>(k,vector<int>(2,0)));
    int q;
    cin>>q;
    while(q--){
        ll x;
        cin>>x;
        int idx=lower_bound(p.begin(),p.end(),x)-p.begin();
        ll t=0;
        bool ok=1;
        ll now=x;
        bool co=false;
        while(idx<n&&idx>=0){
            if(ok){
                t+=p[idx]-now;
                now=p[idx];
                if(t>=d[idx]){
                    if(st[idx][(t-d[idx])%k][ok]==q+1){
                        no();
                        co=1;
                        break;
                    }else{
                        if((t-d[idx])%k!=0){
                            st[idx][(t-d[idx])%k][ok]=q+1;
                            idx++;
                        }else if((t-d[idx])%k==0){
                            st[idx][(t-d[idx])%k][ok]=q+1;
                            ok=!ok;
                            idx--;
                        }
                    }
                }else if(t<d[idx]){
                    idx++;
                }
            }else{
                t+=now-p[idx];
                now=p[idx];
                if(t>=d[idx]){
                    if(st[idx][(t-d[idx])%k][ok]==q+1){
                        no();
                        co=1;
                        break;
                    }else{
                        if((t-d[idx])%k!=0){
                            st[idx][(t-d[idx])%k][ok]=q+1;
                            idx--;
                        }else if((t-d[idx])%k==0){
                            st[idx][(t-d[idx])%k][ok]=q+1;
                            ok=!ok;
                            idx++;
                        }
                    }
                }else if(t<d[idx]){
                    idx--;
                }
            }
        }
        if(!co){
            yes();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        // cout<<'\n';
    }
    return 0;
}