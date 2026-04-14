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
    auto ask=[&](int l,int r)->int{
        cout<<"? "<<r-l+1<<" ";
        for(int i=l;i<=r;i++){
            cout<<i<<" ";
        }
        cout<<endl;
        int res=0;
        cin>>res;
        return res;
    };
    int n;
    cin>>n;
    int l=1,r=2*n+1;
    int ans=-1;
    int cnt=0;
    vector<int>p;
    while(l<=r){
        int mid=(l+r)>>1;
        cnt++;
        if((mid-ask(1,mid))&1){
            r=mid-1;
            ans=mid;
        }else{
            l=mid+1;
        }
    }
    p.push_back(ans);
    ans=-1;
    l=1,r=2*n+1;
    while(l<=r){
        int mid=(l+r)>>1;
        cnt++;
        if((2*n+1-mid+1-ask(mid,2*n+1))&1){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    p.push_back(ans);
    l=p[1]+1,r=p[0]-1;
    auto ask2=[&](int l,int r)->int{
        int res;
        cout<<"? "<<r-l+3<<' ';
        for(int i=l;i<=r;i++){
            cout<<i<<" ";
        }
        cout<<p[0]<<' '<<p[1]<<endl;
        cin>>res;
        return res;
    };
    ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        cnt++;
        if(ask2(l,mid)%2!=(mid-l+3)%2){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    p.push_back(ans);
    // assert(cnt<=33);
    cout<<"! "<<p[0]<<" "<<p[1]<<" "<<p[2]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        // cout<<'\n';
    }
    return 0;
}