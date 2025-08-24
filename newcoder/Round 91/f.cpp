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
ll mod=998244353;
#define N 1000010
vector<int>prim;
int ok[N];
int minp[N];
void get_prim(){
    for(int i=2;i<N;i++){
        if(!ok[i])
        prim.push_back(i);
        for(int j=0;j<prim.size();j++){
            if(i*prim[j]<N){
                minp[i*prim[j]]=min(i,prim[j]);    
                ok[i*prim[j]]=true;
            }
            else
            break;
            if(i%prim[j]==0)
            break;
        }
    }
}
vector<int>cnt(N,1);
vector<int>cnt2(N,1);
vector<ll>pre1(N,0);
vector<ll>pre2(N,0);
void init(){
    pre1[1]=1;pre1[2]=1;
    pre2[1]=1;
    for(int i=2;i<N;i++){
        int t=i;
        pre1[i]=pre1[i-1];
        pre2[i]=pre2[i-1];
        while(ok[t]){
            int mp=minp[t];
            if(mp&1){
                pre1[i]*=qpow(cnt[mp]++,mod-2,mod);
                pre1[i]%=mod;
                pre1[i]*=cnt[mp];
                pre1[i]%=mod;
            }
            pre2[i]*=qpow(cnt2[mp]++,mod-2,mod);
            pre2[i]%=mod;
            pre2[i]*=cnt2[mp];
            pre2[i]%=mod;
            t/=mp;
        }
        if(t>1){
            if(t&1){
                pre1[i]*=qpow(cnt[t]++,mod-2,mod);
                pre1[i]%=mod;
                pre1[i]*=cnt[t];
                pre1[i]%=mod;
            }
            pre2[i]*=qpow(cnt2[t]++,mod-2,mod);
            pre2[i]%=mod;
            pre2[i]*=cnt2[t];
            pre2[i]%=mod;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    cout<<(pre1[n]*qpow((pre2[n])%mod,mod-2,mod))%mod<<" ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    get_prim();
    init();
    for(int i=0;i<t;i++){
        solve();
        // cout<<'\n';
    }
    return 0;
}