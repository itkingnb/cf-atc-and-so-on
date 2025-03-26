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
#define N (int)1e7+1
vector<ll>prim;
int ok[N];
void get_prim(){
    for(ll i=2;i<N;i++){
        if(!ok[i])
        prim.push_back(i);
        for(int j=0;j<prim.size();j++){
            if(i*prim[j]<N)
            ok[i*prim[j]]=true;
            else
            break;
            if(i%prim[j]==0)
            break;
        }
    }
}
void solve(){
    int n;
    // cout<<prim.size();
    cin>>n;
    ll idx=upper_bound(prim.begin(),prim.end(),n)-prim.begin();
    idx--;
    ll ans=idx+1;
    for(int i=2;i<=n;i++){
        int idx2=upper_bound(prim.begin(),prim.end(),n/i)-prim.begin();//-(upper_bound(prim.begin(),prim.end(),i)-prim.begin());
        //cerr<<upper_bound(prim.begin(),prim.end(),n/i)-prim.begin()<<" "<<(upper_bound(prim.begin(),prim.end(),i)-prim.begin());
        ans+=idx2;
    }
    cout<<ans;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    get_prim();
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}