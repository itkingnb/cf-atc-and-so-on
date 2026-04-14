#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define all(x) (x).begin(), (x).end()
using namespace std;
int maxint = INT_MAX;// 2147483647
int minint = INT_MIN;// -2147483648
long long maxll = LLONG_MAX;// 9223372036854775807
long long minll = LLONG_MIN;// -9223372036854775808
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
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
template <typename T, typename F>
class DisjointSparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  F func;

  DisjointSparseTable(const vector<T>& a, const F& f) : n(int(a.size())), func(f) {
    mat.push_back(a);
    for (int p = 1; (1 << p) < n; p++) {
      mat.emplace_back(n);
      for (int mid = 1 << p; mid < n; mid += 1 << (p + 1)) {
        mat[p][mid - 1] = a[mid - 1];
        for (int j = mid - 2; j >= mid - (1 << p); j--) {
          mat[p][j] = func(a[j], mat[p][j + 1]);
        }
        mat[p][mid] = a[mid];
        for (int j = mid + 1; j < min(n, mid + (1 << p)); j++) {
          mat[p][j] = func(mat[p][j - 1], a[j]);
        }
      }
    }
  }

  T Query(int l, int r) const {
    assert(0 <= l && l < r && r <= n);
    if (r - l == 1) {
      return mat[0][l];
    }
    int p = bit_width(unsigned(l ^ (r - 1))) - 1;
    return func(mat[p][l], mat[p][r - 1]);
  }
};
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1,r=n-1;
    int ans=0;
    bool ok=0;
    if(count_if(a.begin(),a.end(),[](int x){
        return x>0;
    })<=k){
        cout<<0;
        return ;
    }
    vector<int>nxt(n+1);
    for(int i=1;i<=n;i++){
        nxt[i]=max(nxt[i-1],a[i]+i);
    }
    auto check=[&](int mid)->bool{
        int i=1;
        while(i<=n&&a[i]==0){
            i++;
        }
        int ans=1;
        int tim=0;
        while(i<=n){
            tim++;
            i=nxt[i];
            if(i>=n) break;
            if(i==nxt[i]){
                while(i<=n&&i==nxt[i]){
                    i++;
                }
                if(i<=n){
                    tim=0;
                    ans++;
                }
            }else{
                if(tim==mid){
                    i++;
                while(i<=n&&a[i]==0){
                    i++;
                }
                if(i<=n){
                    tim=0;
                    ans++;
                }
            }
        }
    }
        return ans<=k;
    };
    check(0);
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ok=1;
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    ok?cout<<ans:cout<<-1;
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