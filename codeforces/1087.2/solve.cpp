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
string s2="BGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBRBGBRBGBRBGBRBGBRBGBRBGBRBGBRBGBRBGBRBGBRBGBRBGBRBGBRBGBRBGBRBGBRBGBRBGBR"
string s="RGRGRGRGRGRGRGRGRGRGRGRGRGRGRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBGBG";
void solve(){
    vector<int>a(3);
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    vector<int>p(3);
    iota(p.begin(),p.end(),0);
    sort(p.begin(),p.end(),[&](int x,int y){
        return a[x]<a[y];
    });
    char ch[]={'R','G','B'};
    vector<int>ans;
    if(a[p[2]]){
        a[p[2]]--;
        ans.push_back(p[2]);
    }
    if(a[p[1]]){
        a[p[1]]--;
        ans.push_back(p[1]);
    }
    while(1){
        int t=-1;
        for(int i=0;i<3;i++){
            if(a[p[i]]==0){
                continue;
            }
            if(t==-1){
                if(a[p[i]]>0&&(ans.size()<3||ans[ans.size()-3]!=p[i])&&ans.back()!=p[i]){
                    t=p[i];
                }
            }else{
                if(a[p[i]]>0&&(ans.size()<3||ans[ans.size()-3]!=p[i])&&ans.back()!=p[i]){
                    if(a[p[i]]>a[t]&&a[ans[ans.size()-2]]>0){
                        t=p[i];
                    }
                }
            }
        }
        if(t==-1||a[t]==0){
            break;
        }
        a[t]--;
        ans.push_back(t);
    }
    for(int i=0;i<ans.size();i++){
        if(i){
            assert(ans[i]!=ans[i-1]);
        }
        if(i>=3){
            assert(ans[i]!=ans[i-3]);
        }
        cout<<ch[ans[i]];
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