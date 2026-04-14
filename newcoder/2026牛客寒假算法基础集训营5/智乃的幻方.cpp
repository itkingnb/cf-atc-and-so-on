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
    int a[3][3];
    map<int,int>mp;
    vector<int>row(3);
    vector<int>col(3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>a[i][j];
            row[i]+=a[i][j];
            col[j]+=a[i][j];
            mp[a[i][j]]++;
        }
    }
    auto check=[&]()->bool{
        int t1=a[0][0]+a[1][1]+a[2][2];
        int t2=a[0][2]+a[1][1]+a[2][0];
        return mp.size()==9&&row==vector<int>(3,row[0])&&col==vector<int>(3,col[0])&&row[0]==col[0]&&t1==t2&&row[0]==col[0];
    };
    check()?yes():no();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    // cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}