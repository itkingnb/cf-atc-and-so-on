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
    queue<int>q;
    map<int,int>mp;
    q.push(n);
    if(n==k){
        cout<<0;
        return ;
    }
    if(n<k){
        cout<<-1;
        return ;
    }
    while(q.size()){
        auto x=q.front();q.pop();
        // if(mp[x]){
        //     continue;
        // }
        int y=x>>1;
        int z=(x+1)>>1;
        if(k==y||z==k){
            cout<<mp[x]+1;
            return ;
        }
        if(2*k<=y+1&&!mp[y]){
            mp[y]=mp[x]+1;
            q.push(y);
        }
        if(2*k<=z+1&&!mp[z]){
            mp[z]=mp[x]+1;
            q.push(z);
        }
    }
    cout<<-1;
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