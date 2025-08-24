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
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=1e9+10;
    auto check=[&](int xx)->bool{
        stack<int>st;
        for(int i=0;i<n;i++){
            // st.push(a[i]<x);
            if(st.size()>=2){
                auto x=st.top(); st.pop();
                auto y=st.top(); st.pop();
                if((x==0)+(y==0)+(a[i]<xx)==3||(a[i]>=xx&&x==0&&y==0)){
                    st.push(0);
                }else{
                    st.push(y);st.push(x);st.push(a[i]>=xx);
                }
            }else{
                st.push(a[i]>=xx);
            }
        }
        while(st.size()>1){
            auto x=st.top(); st.pop();
            auto y=st.top(); st.pop();
            auto z=st.top(); st.pop();
            if((x==0)+(y==0)+(z==0)>1){
                st.push(0);
            }else{
                st.push(1);
            }
        }
        return st.top();
    };
    int ans=0;
    check(9);
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
}
/*
6
1
1
3
1 2 2 
5
1 3 4 5 2
7
1 2 3 5 6 7 4
9
9 9 8 2 4 4 3 5 3
9
4 4 9 2 9 5 8 3 3 
*/
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