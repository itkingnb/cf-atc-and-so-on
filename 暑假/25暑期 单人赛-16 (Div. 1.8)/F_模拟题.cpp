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
vector<vector<int>>ans(160,vector<int>(10,-1));
void solve(){
    int n,k;
    cin>>n>>k;
    if(k==0){
        vector<int>stk;
        while(n>=9){
            stk.push_back(9);
            n-=9;
        }
        if(n){
            stk.push_back(n);
        }
        while(stk.size()){
            cout<<stk.back();
            stk.pop_back();
        }
        return ;
    }else if(k==1){
        vector<int>stk;
        while(n%2==0){
            if(n<=9){
                cout<<-1;
                return ;
            }
            n-=9;
            stk.push_back(9);
        }
        if(n>17){
            stk.push_back(8);
            n-=17;
            while(n>=18){
                stk.push_back(9);
                n-=18;
            }
            if(n){
                stk.push_back(n/2);
            }
        }else{
            if(n/2>0){
                stk.push_back(n/2);
            } 
        }
        if(stk.size()==0){
            stk.push_back(0);
        }
        while(stk.size()){
            cout<<stk.back();
            stk.pop_back();
        }
        return ;
    }else{
        cout<<ans[n][k];
        return ;
    }

}

void init(){
    auto cal=[&](int x)->int{
        int res=0;
        while(x){
            res+=x%10;
            x/=10;
        }
        return res;
    };
    for(int i=0;i<1e6;i++){
        int res=0;
        for(int j=0;j<=9;j++){
            res+=cal(i+j);
            if(res<160&&ans[res][j]==-1){
                ans[res][j]=i;
            }else if(res>150){
                break;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    init();
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}