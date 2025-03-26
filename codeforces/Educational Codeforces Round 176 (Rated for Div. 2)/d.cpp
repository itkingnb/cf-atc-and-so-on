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
ll qpow(ll a, ll k, ll p=maxll)
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
    vector<ll>a;
    ll t=2;
    while(t<(ll)1e17+10){
        a.push_back(t);
        t*=2LL;
    }
    ll x,y;
    cin>>x>>y;
    if(x==y){
        cout<<0;
        return ;
    }
    vector<ll>yx,yy;
    int i=0;
    yx.push_back(x);
    while(x/a[i]){
        yx.push_back(x/a[i++]);
    }
    yx.push_back(0);
    i=0;
    yy.push_back(y);
    while(y/a[i]){
        yy.push_back(y/a[i++]);
    }
    yy.push_back(0);
    i=0;int j=0;
    ll tx=-1,ty=-1;
    while(yx[i]!=yy[j]){
        // cerr<<yx[i]<<" "<<yy[j]<<'\n';
        if(yx[i]>yy[j]){
            i++;
        }else{
            j++;
        }
    }
    tx=i;ty=j;
    ll ans=maxll;
    ll res=0;
    auto dfs=[&](auto dfs,ll tx,ll ty,ll res,int x)->void{
        if(x>25){
            return ;
        }
        if(tx==0&&ty==0){
            ans=min(ans,res);
            // cout<<ans;
            return ;
        }
        if(tx>=x){
            tx-=x;
            res+=a[x-1];
            dfs(dfs,tx,ty,res,x+1);
            tx+=x;
            res-=a[x-1];
        }
        if(ty>=x){
            ty-=x;
            res+=a[x-1];
            dfs(dfs,tx,ty,res,x+1);
            ty+=x;
            res-=a[x-1];
        }
        if(tx>=x+1||ty>=x+1)
            dfs(dfs,tx,ty,res,x+1);
    };
    dfs(dfs,tx,ty,res,1);
    cout<<ans;
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