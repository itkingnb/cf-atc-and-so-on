#include<bits/stdc++.h>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define ll long long
#define all(x) (x).begin(), (x).end()
#define int ll
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
    int n,q;
    cin>>n>>q;
    auto dfs1=[&](auto dfs1,ll l,ll r,int pi,int pj)->ll{
        if(l==r){
            return l;
        }
        ll d=r-l+1;
        // ll dd=(ll)log2(d)/2;
        ll dd;
        for(dd=0;;dd++){
            if(1LL<<(2*dd)==d){
                break;
            }
        }
        if(pi-dd>=1&&pj-dd>=1){
            return dfs1(dfs1,l+d/4,l+d/2-1,pi-dd,pj-dd);
        }else if(pi-dd>=1){
            return dfs1(dfs1,l+d/2,l+d*3/4-1,pi-dd,pj);
        }else if(pj-dd>=1){
            return dfs1(dfs1,l+d*3/4,r,pi,pj-dd);
        }
        return dfs1(dfs1,l,l+d/4-1,pi,pj);
    };
    auto dfs2=[&](auto&&dfs2,ll x,ll l,ll r,int ansi,int ansj)->pii{
        if(l==r){
            return {ansi+1,ansj+1};
        }
        ll d=r-l+1;
        ll dd;
        for(dd=0;;dd++){
            if(1LL<<(dd)==d/4){
                break;
            }
        }
        if(x>=l&&x<d/4+l){
            return dfs2(dfs2,x,l,l+d/4-1,ansi,ansj);
        }else if(x>=l+d/4&&x<d/2+l){
            return dfs2(dfs2,x,l+d/4,l+d/2-1,ansi+dd,ansj+dd);
        }else if(x>=l+d/2&&x<l+d*3/4){
            return dfs2(dfs2,x,l+d/2,l+d*3/4-1,ansi+dd,ansj);
        }
        return dfs2(dfs2,x,l+d*3/4,r,ansi,ansj+dd);
    };
    while(q--){
        string op;
        cin>>op;
        if(op=="->"){
            int a,b;
            cin>>a>>b;
            cout<<dfs1(dfs1,1,1LL<<(2*n),a,b)<<'\n';

        }else{  
            ll x;
            cin>>x;
            pii ans=dfs2(dfs2,x,1,1LL<<(2*n),0,0);
            cout<<ans.first<<" "<<ans.second<<'\n';
        }
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        // cout<<'\n';
    }
    return 0;
}