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
    // vector<vector<string>>op(n,vector<string>(4));
    const int N=n+1;
    char op[N][4];
    ll a[N][4]={0};
    for(int i=0;i<n;i++){
        cin>>op[i][0]>>a[i][1]>>op[i][2]>>a[i][3];
    }
    ll ans=0;
    ll l=1,r=1;
    function<void(int)>dfs=[&](int x)->void{
        if(x==n){
            ans=max(ans,l+r);
            return;
        }
        ll sum=0;
        if(op[x][0]=='+'){
            sum+=a[x][1];
        }else{
            sum+=(a[x][1]-1)*l;
        }
        if(op[x][2]=='+'){
            sum+=a[x][3];
        }else{
            sum+=(a[x][3]-1)*r;
        }
        // cerr<<sum<<'\n';
        l+=sum;
        dfs(x+1);
        l-=sum;
        r+=sum;
        dfs(x+1);
        r-=sum;
    };
    dfs(0);
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