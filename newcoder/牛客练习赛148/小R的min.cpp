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
int n,q;
#define sqrtn sqrt(n)
struct Q{
    int l,r;
    int id;
};
bool cmp(Q a,Q b){
    if(a.l/sqrtn!=b.l/sqrtn)
        return a.l<b.l;
    return a.r<b.r;
}
// void solve(){
//     int n,w;
//     priority_queue<int>a;
//     priority_queue<int,vector<int>,greater<int>>b;
//     cin>>n>>w;
//     for(int i=0;i<n;i++){
//         int x;
//         cin>>x;
//         if(b.empty()||x>b.top())
//         b.push(x);
//         else
//         a.push(x);
//         int k=max(1,w*(i+1)/100);
//         while(b.size()>k) a.push(b.top()),b.pop();
//         while(b.size()<k) b.push(a.top()),a.pop();
//         cout<<b.top()<<" ";
//     }
// }

void solve(){
    cin>>n>>q;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<Q>qs(q);
    for(int i=0;i<q;i++){
        cin>>qs[i].l>>qs[i].r;
        qs[i].l--;
        qs[i].r--;
        qs[i].id=i;
    }
    sort(qs.begin(),qs.end(),cmp);
    priority_queue<int>q1;
    priority_queue<int,vector<int>,greater<int>>q2;
    multiset<int>ms;
    auto add=[&](int x)->void{
        ms.insert(x);
    };
    auto sub=[&](int x)->void{
        ms.erase(x);
    };
    vector<int>ans(q);
    for(int i=0,l=1,r=0;i<q;i++){
        while(qs[i].l<l) add(a[--l]);
        while(qs[i].r>r) add(a[++r]);
        while(qs[i].l>l) sub(a[l++]);
        while(qs[i].r<r) sub(a[r--]);
        ans[qs[i].id]=*ms.begin();
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<"\n";
    }


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