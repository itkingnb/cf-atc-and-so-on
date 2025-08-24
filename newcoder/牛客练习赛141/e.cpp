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
    int n;
    cin>>n;
    vector<int>a(n+1);
    vector<pii>b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i].first=a[i];
        b[i].second=i;
    }
    if(n<5){
        cout<<0;
        return ;
    }
    vector<int>cnt1(n+1,0),cnt2(n+1,0),cnt3(n+1,0),ft(n+1,0),bt(n+1,0);
    auto lowbit=[](int x)->int{
        return x & -x;
    };
    auto get=[&](int x)->ll{
        int xx=x-1;
        ll ans1=0;
        while(xx){
            ans1+=ft[xx];
            xx-=lowbit(xx);
        }
        ll ans2=0;
        xx=x+1;
        while(xx<=n){
            ans2+=bt[xx];
            xx+=lowbit(xx);
        }
        return ans1*ans2;
    };
    auto upd2=[&](int x)->void{
        int xx=x;
        while(xx<=n){
            bt[xx]-=cnt2[xx]--;
            cnt2[xx]=max(cnt2[xx],0);
            xx+=lowbit(xx);
            
        }
    };
    auto upd1=[&](int x)->void{
        int xx=x;
        while(xx){
            ft[xx]+=cnt3[xx]++;
            xx-=lowbit(xx);
        }
        cnt1[x]++;
    };
    // vector<int>b=a;
    sort(b.begin()+1,b.end(),greater<pii>());
    for(int i=1;i<=n;i++){
        int xx=b[i].second;
        while(xx<=n){
            bt[b[i].first]+=;
            xx+=lowbit(xx);
        }
        cnt2[b[i].second]++;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        upd2(i);
        ans+=get(i);
        upd1(i);
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}