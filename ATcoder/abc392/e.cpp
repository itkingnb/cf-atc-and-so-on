#include<bits/stdc++.h>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define ll long long
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
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
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
    int n,m;
    cin>>n>>m;
    vector<bool>able(m+1,true);
    vector<pii>a(m);
    vector<int>fa(n+1);
    iota(fa.begin(),fa.end(),0);
    vector<int>sz(n+1,1);
    auto findfa=[&](auto &&findfa,int x)->int{
        if(x==fa[x]){
            return x;
        }
        return fa[x]=findfa(findfa,fa[x]);
    };
    auto update=[&](auto &&update,int x,int dad)->void{
        sz[dad]+=sz[x];
        fa[x]=dad;
    };
    for(int i=0;i<m;i++){
        cin>>a[i].first>>a[i].second;
        if(findfa(findfa,a[i].first)==findfa(findfa,a[i].second)){
            continue;
        }else{
            if(sz[findfa(findfa,a[i].first)]<sz[findfa(findfa,a[i].second)]){
                swap(a[i].first,a[i].second);
            }
            update(update,findfa(findfa,a[i].first),findfa(findfa,a[i].second));
            able[i]=false;
        }
    }
    // 修改 set 为 vector
    // set<int>t;
    // vector<array<int,3>>ans;
    // int cnt=0;
    // for (int i = 1; i <= n; i++) {
    //     if (fa[i] == i) {
    //         t.insert(i);
    //     }
    // }

    // for (int i = 0; i < m && t.size() > 1; i++) {
    //     if (able[i]) {
    //         int dad = findfa(findfa, a[i].first);
    //         for (auto it = t.begin(); it != t.end();) {
    //             if (*it != dad) {
    //                 ans.push_back({i + 1, a[i].second, *it});
    //                 update(update, *it, dad);
    //                 it = t.erase(it); // 使用迭代器安全地删除
    //                 cnt++;
    //                 if(sz[dad]==n){
    //                     goto out;
    //                 }
    //                 break; // 找到后跳出
    //             } else {
    //                 ++it; // 继续遍历
    //             }
    //         }
    //     }
    // }

    // vector<int>t;
    set<int>t;
    for(int i=1;i<=n;i++){
        if(fa[i]==i){
            t.insert(i);
        }
    }
    int cnt=0;
    vector<array<int,3>>ans;
    for(int i=0;i<m&&t.size()>1;i++){
        if(able[i]){
            int dad=findfa(findfa,a[i].first);
            for(auto x:t){
                if(x!=dad){
                    // if(sz[x]>sz[dad]){
                    //     swap(x,dad);
                    // }
                    t.erase(t.find(x));
                    ans.push_back({i+1,a[i].second,x});
                    update(update,x,dad);
                    cnt++;
                    if(sz[dad]==n){
                        goto out;
                    }
                    break;
                }
            }
        }
    }
    out:
    cout<<cnt<<'\n';
    for(auto [aa,bb,cc]:ans){
        cout<<aa<<' '<<bb<<' '<<cc<<'\n';
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