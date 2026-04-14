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
    vector<int>a(3);
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    char ch[]={'R', 'G', 'B'};
    vector<int>ans;
    while(1){
        int sz=ans.size();
        vector<int>tmp;
        for(int i=0;i<3;i++){
            if(a[i]>0&&(sz<1||ans.back()!= i)&&(sz<3||ans[sz-3]!=i)){
                tmp.push_back(i);
            }
        }
        if(!tmp.size()){
            break;
        }
        int t=-1;
        if(tmp.size()==1){
            t=tmp[0];
        } else {
            if(sz<2){
                t=tmp[0];
                for(int i=1;i<tmp.size();i++){
                    if(a[tmp[i]]>a[t]){
                        t=tmp[i];
                    }
                }
            }else{
                int x=ans[sz-1]; 
                int y=ans[sz-2]; 
                int z=(tmp[0]==y?tmp[1]:tmp[0]);
                if(a[z]>a[y]&&a[x]>0){
                    t=z;
                } else {
                    t=y;
                }
            }
        }
        a[t]--;
        ans.push_back(t);
    }
    for(int i=0;i<ans.size();i++){
        if(i >= 1) assert(ans[i]!=ans[i-1]);
        if(i >= 3) assert(ans[i]!=ans[i-3]);
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