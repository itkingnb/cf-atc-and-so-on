#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int ll
void yes(){
    cout<<"YES";
}
void no(){
    cout<<"NO";
}
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    int lowbit(int x)
    {
        return x & -x;
    }
    void init(int n_) {
        n = n_;
        a.assign(n+1, T{});
    }
    
    void add(int x, const T &v)
    {
        ++x;
        while (x <= n) {
            a[x] = (a[x] + v);
            x += lowbit(x);
        }
    }
    T sum(int x)
    {
        T ans{};
        ++x;
        while (x >= 1) {
            ans = (ans + a[x]);
            x -= lowbit(x);
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return (sum(r) - sum(l - 1));
    }
    
    
    int select(const T &k) {
        int l=1,r=n;
        int ans=0;
        // cerr<<sum(2)<<" "<<sum(3)<<'\n';

        while(l<=r){
            int mid=(l+r)>>1;
            if(sum(mid)>=k){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
        // int x = 0;
        // T cur{};
        // for (int i = 1 << std::__lg(n); i; i /= 2) {
        //     if (x + i <= n && cur + a[x + i - 1] <= k) {
        //         x += i;
        //         cur = cur + a[x - 1];
        //     }
        // }
        // return x;
    }
};
void AUTO_AC_MACHINE(){
    int n;
    cin>>n;
    vector<ll>b(n+1);
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    Fenwick<int> fen(n+10);
    vector<int>ans(n+1);
    ans[1]=1;
    fen.add(1,1);
    int cnt=1;
    vector<int>lst(n+1,-1);
    lst[1]=1;
    for(int i=2;i<=n;i++){
        int d=b[i]-b[i-1];
        if(d==i){
            ans[i]=++cnt;
            fen.add(i,1);
        }else{
            ans[i]=ans[fen.select(cnt+1-d)];
            fen.add(lst[ans[i]],-1);
            fen.add(i,1);
        }
        lst[ans[i]]=i;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        AUTO_AC_MACHINE();
        cout<<'\n';
    }
}
