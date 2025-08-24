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
    int n;
    cin>>n;
    int idx=1;
    vector<array<int,3>>a(n);
    vector<array<int,3>>b(n);
    // vector<array<int,3>>c(n);
    // vector<tuple<int,int,int>>b(n);
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1];a[i][2]=i+1;
        b[i][0]=a[i][0];b[i][1]=a[i][1];b[i][2]=i+1;
    }
    sort(a.begin(),a.end(),[](array<int,3>x,array<int,3>y){
        // if(x[0]+x[1]==y[0]+y[1]){
        //     return x[0]>y[0];
        // }
        // return x[0]+x[1]<y[0]+y[1];
        // if(x[0]==y[0]){
        //     return x[1]>y[1];
        // }
        return x[0]+x[1]<y[0]+y[1];
    });
    sort(b.begin(),b.end(),[](array<int,3>x,array<int,3>y){
        // if(x[0]==y[0]){
        //     return x[1]>y[1];
        // }
        return x[0]-x[1]<y[0]-y[1];
        // if(x[0]+x[1]==y[0]+y[1]){
        //     return x[0]<y[0];
        // }
        // return x[0]-x[1]<y[0]-y[1];
    });
    // ll sum1=0,sum2=0;
    // for(int i=0;i<n/2;i++){
    //     sum1+=abs(b[i][0]-b[n-1-i][0])+abs(b[i][1]-b[n-1-i][1]);
    // }
    // cout<<sum;
    // int cnt=0;
    // ll sum=0;
    // int lb=0,rb=n-1,la=0,ra=n-1;
    // vector<bool>vis(n,0);
    // vector<pii>ans;
    // while(cnt<n/2){
    //     while(vis[a[la][2]]) la++;
    //     while(vis[b[lb][2]]) lb++;
    //     while(vis[a[ra][2]]) ra--;
    //     while(vis[b[rb][2]]) rb--;
    //     ll x=abs(a[la][0]-a[ra][0])+abs(a[la][1]-a[ra][1]);
    //     ll y=abs(b[lb][0]-b[rb][0])+abs(b[lb][1]-b[rb][1]);
    //     sum+=max(x,y);
    //     if(x>=y){
    //         ans.push_back({a[la][2],a[ra][2]});
    //         vis[a[la++][2]]=1;
    //         vis[a[ra--][2]]=1;
    //     }else{
    //         ans.push_back({b[lb][2],b[rb][2]});
    //         vis[b[lb++][2]]=1;
    //         vis[b[rb--][2]]=1;
    //     }
    //     cnt++;
    // }
    // cerr<<sum<<'\n';
    // for(int i=0;i<n/2;i++){
    //     cout<<ans[i].first<<" "<<ans[i].second<<'\n';
    // }
    vector<pii>ans1,ans2;
    ll sum1=0,sum2=0;
    for(int i=0;i<n/2;i++){
        ans1.push_back({a[i][2],a[n-1-i][2]});
        sum1+=abs(a[i][0]-a[n-1-i][0])+abs(a[i][1]-a[n-1-i][1]);
        // cerr<<sum1<<'\n';
        ans2.push_back({b[i][2],b[n-1-i][2]});
        sum2+=abs(b[i][0]-b[n-1-i][0])+abs(b[i][1]-b[n-1-i][1]);
    }
    cerr<<sum1<<" "<<sum2<<'\n';
    if(sum1>=sum2){
        for(int i=0;i<ans1.size();i++){
            cout<<ans1[i].first<<" "<<ans1[i].second<<'\n';
        }
    }else{
        for(int i=0;i<ans2.size();i++){
            cout<<ans2[i].first<<" "<<ans2[i].second<<'\n';
        }
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