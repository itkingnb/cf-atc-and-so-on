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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0')
        cnt++;
    }
    if(n==2){
        cout<<stoi(s);
        return ;
    }
    if((n==3&&(s[0]=='0'||s[2]=='0'))||n>3&&cnt){
        cout<<0;
        return ;
    }
    int ans=1e9;
    for(int i=1;i<n;i++){
        int res=0;
        for(int j=0;j<i-1;j++){
            if(s[j]!='1')
            res+=s[j]-'0';
        }
        if((int)(s[i-1]-'0')*10+(int)(s[i]-'0')!=1)
        res+=(int)(s[i-1]-'0')*10+(int)(s[i]-'0');
        for(int j=i+1;j<n;j++)
        if(s[j]!='1')
        res+=s[j]-'0';
        if(res==0)
        res=1;
        ans=min(ans,res);
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