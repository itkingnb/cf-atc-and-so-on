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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n+1,vector<int>(m+1,0));
    vector<pii>pos(n*m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            pos[a[i][j]].first=i;
            pos[a[i][j]].second=j;
        }
    }
    int l=1e9,r=0;
    int u=1e9,d=0;
    ll ans=0;
    for(int i=0;i<n*m;i++){
        l=min(l,pos[i].second);
        r=max(r,pos[i].second);
        u=min(u,pos[i].first);
        d=max(d,pos[i].first);
        ans+=1LL*l*u*(n-d+1)*(m-r+1);
    }
    cout<<ans;
//     vector<vector<int>>a(n+10,vector<int>(m+10,n*m));
//     vector<vector<int>>pre(n+10,vector<int>(m+10,n*m));
//     vector<vector<int>>suf(n+10,vector<int>(m+10,n*m));
//     vector<vector<int>>up(n+10,vector<int>(m+10,n*m));
//     vector<vector<int>>down(n+10,vector<int>(m+10,n*m));
//     int pi=-1,pj=-1;
//     ll sum=0;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             cin>>a[i][j];
//             // sum+=(n-i+1)*(m-j+1);
//             pre[i][j]=min(pre[i][j-1],a[i][j]);
//             if(a[i][j]==0){
//                 pi=i;pj=j;
//                 // sum-=(n-i+1)*(m-j+1);
//             }
//         }
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=m;j>=1;j--){
//             suf[i][j]=min(suf[i][j+1],a[i][j]);
//         }
//     }
//     for(int j=1;j<=m;j++){
//         for(int i=1;i<=n;i++){
//             up[i][j]=min(up[i-1][j],a[i][j]);
//         }
//     }
//     for(int j=1;j<=m;j++){
//         for(int i=n;i>=1;i--){
//             down[i][j]=min(down[i+1][j],a[i][j]);
//         }
//     }
//     // for(int i=0)
//     // int res=min({})
//     map<int,int>u,d,l,r;
//     for(int i=pi;i<=n;i++){
//         for(int j=pj;j<=m;j++){
//             u[j]=max(u[j],up[pi-1][j]);
//             if(j>pj){
//                 u[j]=min(u[j],u[j-1]);
//             }
//             d[j]=max(d[j],down[i+1][j]);
//             if(j>pj){
//                 d[j]=min(d[j],d[j-1]);
//             }
//             l[i]=max(l[i],pre[i][pj-1]);
//             if(i>pi){
//                 l[i]=min(l[i],l[i-1]);
//             }
//             r[i]=max(r[i],suf[i][j+1]);
//             if(i>pi){
//                 r[i]=min(r[i],r[i-1]);
//             }
//             sum+=min({u[j],d[j],l[i],r[i]});
//         }
//     }
//     u.clear();d.clear();l.clear();r.clear();
//     for(int i=pi;i>=1;i--){
//         for(int j=pj;j>=1;j--){
//             u[j]=max(u[j],up[i-1][j]);
//             if(j<pj){
//                 u[j]=min(u[j],u[j+1]);
//             }
//             d[j]=max(d[j],down[pi+1][j]);
//             if(j<pj){
//                 d[j]=min(d[j],d[j+1]);
//             }
//             l[i]=max(l[i],pre[i][j-1]);
//             if(i<pi){
//                 l[i]=min(l[i],l[i+1]);
//             }
//             r[i]=max(r[i],suf[i][pj+1]);
//             if(i<pi){
//                 r[i]=min(r[i],r[i+1]);
//             }
//             sum+=min({u[j],d[j],l[i],r[i]});
//         }
//     }
//     cout<<sum;
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