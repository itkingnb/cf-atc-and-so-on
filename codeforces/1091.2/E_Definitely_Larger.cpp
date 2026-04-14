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
    int n;
    cin>>n;
    vector<int>pos(n+1,-1);
    vector<int>p(n),d(n),q(n,-1);
    set<int>s;
    for(int i=0;i<n;i++){
        cin>>p[i];
        pos[p[i]]=i;
        s.insert(i+1);
    }
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    if(d[pos[n]]!=0){
        cout<<-1;
        return ;
    }
    q[pos[n]]=1;
    vector<bool>vis(n+1);
    int idx=1;
    for(int i=n-1;i>=1;i--){
        priority_queue<pii,vector<pii>>pq;
        for(int j=n-1;j>pos[i];j--){
            if(q[j]!=-1){
                pq.push({q[j],j});
            }
        }
        if(pq.size()<d[pos[i]]){
            cout<<-1;
            return ;
        }
        int cnt=d[pos[i]];
        while(cnt--){
            auto [x,y]=pq.top();
            pq.pop();
            q[y]++;
            q[pos[i]]=x;
        }
        fill(vis.begin(),vis.end(),0);
        for(int j=0;j<n;j++){
            if(q[j]!=-1){
                vis[q[j]]=1;
            }
        }
        idx=1;
        while(idx<n&&vis[idx]){
            idx++;
        }
        if(q[pos[i]]==-1){
            q[pos[i]]=idx++;
        }
        assert(q[pos[i]]<=n&&q[pos[i]]>=1);
    }
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=i+1;j<n;j++){
            if(q[j]>q[i]&&p[j]>p[i]){
                cnt++;
            }
        }
        if(cnt!=d[i]){
            cout<<-1;
            return ;
        }
    }
    for(int i=0;i<n;i++){
        cout<<q[i]<<" ";
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