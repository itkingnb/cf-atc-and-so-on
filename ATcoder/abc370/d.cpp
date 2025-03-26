#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#include<numeric>
#include<cstring>
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
    int h,w,q;
    cin>>h>>w>>q;
    int left=h*w;
    vector<set<int>>hs(h+1),ws(w+1);
    for(int i=1;i<h+1;i++){
        for(int j=1;j<w+1;j++){
            hs[i].insert(j);
            ws[j].insert(i);
        }
    }
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;     
        if(hs[a].count(b)){
            left--;
            hs[a].erase(b);
            ws[b].erase(a);
        }else{
            auto it=hs[a].lower_bound(b);
            if(it!=hs[a].begin()){
                int itt=*prev(it);
                left--;
                hs[a].erase(itt);
                ws[itt].erase(a);                
            }
            if(it!=hs[a].end()){
                int itt=*(it);
                left--;
                hs[a].erase(itt);
                ws[itt].erase(a); 
            }
            it=ws[b].lower_bound(a);
            if(it!=ws[b].begin()){
                int itt=*prev(it);
                left--;
                hs[itt].erase(b);
                ws[b].erase(itt);                
            }
            if(it!=ws[b].end()){
                int itt=*(it);
                left--;
                hs[itt].erase(b);
                ws[b].erase(itt);   
            }

        }
    }
    cout<<left;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    //cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}