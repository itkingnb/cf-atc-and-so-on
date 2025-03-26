#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
    int ans=0;
    int flag=0;
    for(int i=0;i<n;i++){
        flag=0;
        string s;
        cin>>s;
        vector<int>a;
        string b;
        for(int j=0;j<s.size();j++){
            if(s[j]=='.'){
            a.push_back(stoi(b));
            b.clear();
            }
            else{
                b+=s[j];
            }
        }
        a.push_back(stoi(b));
        for(int i=0;i<4;i++){
            if(a[i]>=256)
            flag++;
        }
        if(flag)
        continue;
        else
        ans++;
    }
    cout<<ans;
}
int main(){
    solve();
    return 0;
}