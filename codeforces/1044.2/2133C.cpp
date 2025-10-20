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

    // vector<vector<int>>adj
    vector<int>length(n+1);
    auto query=[&](int x)->int{
        cout<<"? "<<x<<" "<<n<<" ";
        for(int i=1;i<=n;i++){
            cout<<i<<" ";
        }
        cout<<endl;
        int res;
        cin>>res;
        return res;
    };
    int mx=0;
    for(int i=1;i<=n;i++){
        length[i]=query(i);
        mx=max(mx,length[i]);
    }
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(mx==length[i]){
            ans.push_back(i);
            break;
        }
    }
    auto query2=[&](int a,int b)->int{
        int res;
        cout<<"? "<<a<<" "<<2<<" "<<a<<" "<<b<<endl;
        cin>>res;
        return res;
    };
    // cout<<mx<<"1111 "<<endl;
    while(mx!=1){
        for(int i=1;i<=n;i++){
            if(length[i]==mx-1){
                int res=query2(ans.back(),i);
                if(res==2){
                    ans.push_back(i);
                    mx--;
                    break;
                }
            }
        }
    }
    cout<<"! "<<ans.size()<<" ";
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
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