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
    int l,r;
    cin>>l>>r;
    int n=r-l+1;
    vector<int>ans(n);
    iota(ans.begin(),ans.end(),l);
    auto work=[&](auto &&self,int l,int r,int x)->void{
        for(int i=x;i>=0;i--){
            for(int j=l+1;j<r;j++){
                if((((ans[j])>>i)&1)!=(((ans[j-1])>>i)&1)){
                    int left=j-l,right=r-j;
                    if(left>right){
                        reverse(ans.begin()+j-right,ans.begin()+j+right);
                        self(self,l,j-right,i-1);
                        return ;
                    }
                    if(right>left){
                        reverse(ans.begin()+j-left,ans.begin()+j+left);
                        self(self,j+left,r,i-1);
                        return ;
                    }
                    reverse(ans.begin()+l,ans.begin()+r);
                    return ;
                }
            }
        }
    };
    work(work,0,n,31);
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=(i+l)|ans[i];
    }
    cout<<sum<<'\n';
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
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