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
void sc(int i,int x){
    cout<<x;
    switch (i)
    {
    case 0:
        cout<<'C';
        break;
    case 1:
        cout<<'D';
        break;
    case 2:
        cout<<'H';
        break;
    case 3:
        cout<<'S';
        break;
    default:
        break;
    }
}
void solve(){
    int n;
    cin>>n;
    char king;
    cin>>king;
    vector<string>a(n*2);
    vector<int>aa[4];
    for(int i=0;i<n*2;i++){
        cin>>a[i];
        switch (a[i][1])
        {
        case 'C':
            aa[0].push_back(a[i][0]-'0');
            break;
        case 'D':
            aa[1].push_back(a[i][0]-'0');
            break;
        case 'H':
            aa[2].push_back(a[i][0]-'0');
            break;
        case 'S':
            aa[3].push_back(a[i][0]-'0');
            break;
        default:
            break;
        }
    }
    int idx=0;
    switch (king)
    {
    case 'C':
        idx=0;
        break;
    case 'D':
        idx=1;
        break;
    case 'H':
        idx=2;
        break;
    case 'S':
        idx=3;
        break;
    default:
        break;
    }
    int all=0;
    for(int i=0;i<4;i++){
        sort(aa[i].begin(),aa[i].end());
        if(i!=idx)
        all+=aa[i].size()%2;
    }
    if(all>aa[idx].size()){
        cout<<"IMPOSSIBLE"<<'\n';
    }else{
        int pos=0;
        for(int i=0;i<4;i++){
            if(i!=idx){
                for(int j=0;j<aa[i].size();j+=2){
                    sc(i,aa[i][j]);
                    cout<<" ";
                    if(j+1<aa[i].size()){
                        sc(i,aa[i][j+1]);
                    }else{
                        sc(idx,aa[idx][pos++]);
                    }
                    cout<<'\n';
                }
            }
        }
        for(int i=pos;i<aa[idx].size();i+=2){
            sc(idx,aa[idx][i]);
            cout<<" ";
            sc(idx,aa[idx][i+1]);
            cout<<'\n';
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
        //cout<<'\n';
    }
    return 0;
}