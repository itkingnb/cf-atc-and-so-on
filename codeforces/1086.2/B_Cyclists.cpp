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
    int n,k,p,m;
    cin>>n>>k>>p>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    queue<int>q;
    auto cmp=[&](int x, int y){
        return a[x]>a[y];
    };
    if(a[p-1]>m){
        cout<<0;
        return ;
    }
    priority_queue<int, vector<int>,decltype(cmp)>pq(cmp);
    bool in=(p<=k);
    for(int i=0;i<k;i++){
        if(i==p-1){
            continue;
        }
        pq.push(i);
    }
    for(int i=k;i<n;i++){
        q.push(i);
    }
    int ans=0;
    while(pq.size()&&m>=a[pq.top()]||in){
        if(in){
            in=0;
            if(m>=a[p-1]){
                ans++;
                m-=a[p-1];
                q.push(p-1);
            }else{
                break;
            }
        }else{
            m-=a[pq.top()];
            auto x=pq.top();pq.pop();
            q.push(x);
        }
        if(q.front()==p-1){
            in=1;
            q.pop();
        }else{
            pq.push(q.front());
            q.pop();
        }
    }
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