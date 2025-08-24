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
    int cnt=2;
    string s;
    vector<int>aa;
    aa.push_back(a[0]);
    aa.push_back(a[1]);
    s.push_back('L');
    s.push_back('L');
    int l=2,r=n-1;
    while(cnt<n){
        if(aa.back()>aa[aa.size()-2]){
            if(a[l]<aa.back()){
                aa.push_back(a[l]);
                s.push_back('L');
                l++;
                cnt++;
            }else{
                if(a[r]<aa.back()){
                    aa.push_back(a[r]);
                    s.push_back('R');
                    r--;
                    cnt++;
                }else{
                    aa.pop_back();
                    s.pop_back();
                    s.push_back('R');
                    aa.push_back(a[r]);
                    r--;
                    s.push_back('L');
                    aa.push_back(a[l-1]);
                    cnt++;
                }
            }
        }else{
            if(a[l]>aa.back()){
                aa.push_back(a[l]);
                s.push_back('L');
                l++;
                cnt++;
            }else{
                if(a[r]>aa.back()){
                    aa.push_back(a[r]);
                    s.push_back('R');
                    r--;
                    cnt++;
                }else{
                    aa.pop_back();
                    s.pop_back();
                    s.push_back('R');
                    aa.push_back(a[r]);
                    r--;
                    s.push_back('L');
                    aa.push_back(a[l-1]);
                    cnt++;
                }
            }
        }
        // cerr<<aa<<'\n';
    }
    cout<<s;
    assert(s.size()==n);
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