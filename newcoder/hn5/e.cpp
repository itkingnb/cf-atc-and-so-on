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
int prime[50010];
vector<int>p;
ll k;
bool pr[50010];
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<p.size();i++){
        for(int j=i;j<p.size();j++){
            if(n-p[i]-p[j]>0&&pr[n-p[i]-p[j]]){
            cout<<p[i]<<" "<<p[j]<<" "<<n-p[i]-p[j];
            return ;    
            }
        }
    }
    cout<<-1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    memset(prime,1,sizeof(prime));
    for(int i=2;i<50010;i++){
        if(prime[i]){
        p.push_back(i);   
        pr[i]=true;
        }
        for(int j=0;j<p.size();j++){
            k=p[j]*i;
            if(k<50000)
            prime[k]=0;
            else
            break;
            if(i%p[j]==0)
            break;
        }
    }
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}