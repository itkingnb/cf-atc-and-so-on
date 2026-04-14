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
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>p(k);
    for(int i=0;i<k;i++){
        cin>>p[i];
        // p[i]--;
    }
    a.push_back(a[p[0]-1]);
    a.insert(a.begin(),a[p[0]-1]);
    p.push_back(n+1);
    p.insert(p.begin(),0);
    int sum=0;
    int mx=0;
    for(int i=0;i<p.size()-1;i++){
        int cnt=0;
        for(int j=p[i];j<p[i+1];j++){
            if(a[j]!=a[j+1]){
                cnt++;
            }
        }
        // cerr<<p[i]<<" "<<p[i+1]<<" "<<cnt<<endl;
        mx=max(mx,cnt);
        sum+=cnt;
    }
    cout<<max(mx,sum/2);
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