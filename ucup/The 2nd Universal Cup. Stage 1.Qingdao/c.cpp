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
    cout<<"Yes";
}
void no(){
    cout<<"No";
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
    vector<string>info(n+1);
    vector<array<int,2>>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>info[i];
        if(info[i]=="add"){
            cin>>a[i][0];
        }else{
            cin>>a[i][0]>>a[i][1];
        }
    }
    int now=0;
    int t=1;
    int mod=256;
    for(int i=1;i<=300*n;i++){
        if(t==n+1){
            yes();
            return ;
        }
        if(info[t]=="add"){
            now+=a[t][0];
            now%=mod;
            t++;
        }else if(info[t]=="beq"){
            if(now==a[t][0]){
                t=a[t][1];
            }else{
                t++;
            }
        }else if(info[t]=="bne"){
            if(now!=a[t][0]){
                t=a[t][1];
            }else{
                t++;
            }
        }else if(info[t]=="blt"){
            if(now<a[t][0]){
                t=a[t][1];
            }else{
                t++;
            }
        }else{
            if(now>a[t][0]){
                t=a[t][1];
            }else{
                t++;
            }
        }
    }
    no();
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