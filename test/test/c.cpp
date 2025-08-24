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
const int N = (int)5e6;
int p[N], vis[N], cnt;
int a[N]; //a[i]记录i的最小质因子的次数
ll d[N]; //d[i]记录i的约数个数

void get_d(int n){ //筛法求约数个数
  d[1] = 1;
  for(int i=2; i<=n; i++){
    if(!vis[i]){
      p[++cnt] = i;
      a[i] = 1;
      d[i] = 2;
    }
    for(int j=1; i*p[j]<=n; j++){
      int m = i*p[j];
      vis[m] = 1;
      if(i%p[j] == 0){
        a[m] = a[i]+1;
        d[m] = d[i]/a[m]*(a[m]+1);
        break;
      } 
      else{
        a[m] = 1;
        d[m] = d[i]*2;
      }
    }
  }
}
void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    // for(int i=0;i<n;i++){
        // cin>>a[i];
    // }
    int ans=0;
    for(int i=2;i<=n;i++){
        cout<<i<<" "<<d[i]<<" "<<i-d[i]<<endl;
        if((i-d[i])&1){
            ans++;
        }
    }
    cout<<endl;
    cout<<ans+1;


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    get_d(N);
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}