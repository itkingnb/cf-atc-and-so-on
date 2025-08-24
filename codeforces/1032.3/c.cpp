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
    vector<vector<int>>a(n,vector<int>(m,0));
    vector<int>cnt(101,0);
    vector<vector<int>>cnth(n,vector<int>(101,0));
    vector<vector<int>>cntl(m,vector<int>(101,0));
    int ans=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            cnt[a[i][j]]++;
            ans=max(ans,a[i][j]);
            cnth[i][a[i][j]]++;
            cntl[j][a[i][j]]++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==ans){
                cnt[ans]++;
            }
            if(cnt[ans]-cnth[i][ans]-cntl[j][ans]==0){
                cout<<ans-1;
                return;
            }
            if(a[i][j]==ans){
                cnt[ans]--;
            }
        }
    }
    cout<<ans;
    // if(n*m==1){
    //     cout<<a[0][0]-1;
    //     return;
    // }
    // sort(all(hang));
    // sort(all(lie));
    // int ans=0;
    // if(hang.size()>=2){
    //     ans=max(hang[n-1]-1,hang[n-2]);
    // }
    // if(lie.size()>=2){
    //     ans=max(lie[m-1]-1,lie[m-2]);
    // }
    // cout<<ans;
    // int ans=hang[0]-1;
    // int mx=-1;
    // for(int i=1;i<n;i++){
    //     ans=min(ans,max(mx,hang[i]-1));
    //     mx=(hang[i],mx);
    // }
    // ans=mx;

    // for(int j=1;j<m;j++){
    //     ans=max(mx,lie[j]-1);
    //     mx=max(mx,lie[j]);
    // }
    // cout<<ans;
    // int lo=0,hi=1e6;
    // auto check=[&](int x)->bool{
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){

    //         }
    //     }
    // };
    // while(lo<hi){
    //     int mid=(lo+hi)>>1;
    //     if(check(mid)){
    //         hi=mid-1;
    //     }else{
    //         lo=mid+1;
    //     }
    // }
    // check(hi)?cout<<hi:cout<<hi+1;
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