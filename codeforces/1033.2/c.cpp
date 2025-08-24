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
    ll n,m;
    cin>>n>>m;
    if(m>(n+1)*n/2||m<n){
        cout<<-1;
        return ;
    }
    if(n==1){
        cout<<1;
        return ;
    }
    vector<ll>pre(n,0);
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+i-1;
    }
    // m+=n+1;
    // n++;
    int nn=n;
    vector<bool>vis(n+1,0);
    vector<pii>ans;
    int last=n+1;
    int cnt=n-1;
    while(m){
        if(n+cnt>m){
            n--;
        }else if(n+cnt<m){
            ans.push_back({last,n});
            m-=n;
            last=n;
            vis[n]=1;
            n--;
            cnt--;
        }else{
            ans.push_back({last,n});
            vis[n]=1;
            last=n;
            for(int i=1;i<=nn;i++){
                if(!vis[i]){
                    ans.push_back({last,i});
                    last=i;
                }
            }
            break;
        }
    }
    cout<<ans[0].second<<'\n';
    for(int i=1;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
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