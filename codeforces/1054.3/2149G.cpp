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
    int n,q;
    cin>>n>>q;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    // vector<int>b=a;
    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    // map<int,int>id;
    int idx=1;
    for(int i=0;i<n;i++){
        idx++;
    }
    vector<vector<int>>mp(idx);
    for(int i=0;i<n;i++){
        auto x=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        mp[x].push_back(i);
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;r--;
        vector<int>ans;
        uniform_int_distribution<ll> r1(l, r);
        for(int i=0;i<80;i++){
            int x=r1(rng);
            int idd=lower_bound(b.begin(),b.end(),a[x])-b.begin();;
            auto lx=lower_bound(mp[idd].begin(),mp[idd].end(),l)-mp[idd].begin();
            auto rx=upper_bound(mp[idd].begin(),mp[idd].end(),r)-mp[idd].begin();
            rx--;
            if(rx-lx+1>(r-l+1)/3&&!count(ans.begin(),ans.end(),a[x])){
                ans.push_back(a[x]);
            }
        }
        sort(ans.begin(),ans.end());
        // ans.erase(unique(ans.begin(),ans.end()),ans.end());
        if(!ans.size()){
            cout<<-1<<"\n";
            continue;
        }
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<'\n';
    }
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