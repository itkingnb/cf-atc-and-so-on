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
    ll ans=0;
    vector<pii>a(n);
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    priority_queue<pii>pq2;
    // vector<int>b()
    map<int,int>mp;
    for(int i=0;i<n;i++){    
        cin>>a[i].first>>a[i].second;
        ans+=a[i].second-a[i].first;
        // mp[a[i].first]++;
        // mp[a[i].second]++;
        // pq.push({a[i].first,i});
        // pq2.push({a[i].second,i});
    }
    // sort(all(a));
    // int l=0,r=n-1;
    // int cnt=0;
    vector<bool>vis(n,0);
    // while(cnt<n-1){
        
    // }
    while(pq.size()&&pq2.size()){
        while(pq.size()&&vis[pq.top().second]) pq.pop();
        bool ok=0;
        if(pq.size()){
            auto [x,y]=pq.top();pq.pop();
            vis[y]=1;
            while(pq2.size()&&vis[pq2.top().second]){
                if(pq2.top().second==y){
                    ok=1;
                }
                pq2.pop();  
            } 
            if(!ok&&pq2.size()){
                auto [xx,yy]=pq2.top();pq2.pop();
                vis[yy]=1;
                ans+=xx-x;
            }else if(ok&&pq2.size()){
                auto [xx,yy]=pq2.top();pq2.pop();
                // vis[yy]=1;
                auto [xxx,yyy]=pq.top();
                if(a[y].second-xxx>xx-x){
                    ans+=a[y].second-xxx;
                    vis[yyy]=1;
                    pq2.push({xx,yy});
                }else{
                    vis[yy]=1;
                    ans+=xx-x;
                }
                
            }

        }
    }
    cout<<ans;
    // while()

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