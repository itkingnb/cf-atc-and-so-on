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
    cout<<"Yes";
}
void no(){
    cout<<"No";
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
#define N 100010
vector<ll>prim;
int ok[N];
int minp[N];
void get_prim(){
    for(ll i=2;i<N;i++){
        if(!ok[i])
        prim.push_back(i);
        for(int j=0;j<prim.size();j++){
            if(i*prim[j]<N){
                ok[i*prim[j]]=true;minp[i*prim[j]]=max(i,prim[j]);
            }
            else
            break;
            if(i%prim[j]==0)
            break;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int>ans(n+10,0);
    ans[1]=1;
    iota(ans.begin(),ans.end(),0);
    for(int i=n;i>=2;i--){
        if(ans[i]==i&&minp[i]){
            swap(ans[i],ans[minp[i]]);
        }else if(ans[i]==i){
            ans[i]=i;
            if(2*i<=n){
                swap(ans[i],ans[i*2]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    get_prim();
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}