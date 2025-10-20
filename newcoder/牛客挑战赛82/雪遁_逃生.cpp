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
#define ull unsigned ll
#define inf maxll
template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
    void half(int p, int l, int r) {
        if (info[p].act == 0) {
            return;
        }
        if ((info[p].min + 1) / 2 == (info[p].max + 1) / 2) {
            apply(p, {-(info[p].min + 1) / 2});
            return;
        }
        int m = (l + r) / 2;
        push(p);
        half(2 * p, l, m);
        half(2 * p + 1, m, r);
        pull(p);
    }
    void half() {
        half(1, 0, n);
    }
    
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F &&pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F &&pred) {
        return findLast(1, 0, n, l, r, pred);
    }
    
    void maintainL(int p, int l, int r, int pre) {
        if (info[p].difl > 0 && info[p].maxlowl < pre) {
            return;
        }
        if (r - l == 1) {
            info[p].max = info[p].maxlowl;
            info[p].maxl = info[p].maxr = l;
            info[p].maxlowl = info[p].maxlowr = -inf;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        maintainL(2 * p, l, m, pre);
        pre = std::max(pre, info[2 * p].max);
        maintainL(2 * p + 1, m, r, pre);
        pull(p);
    }
    void maintainL() {
        maintainL(1, 0, n, -1);
    }
    void maintainR(int p, int l, int r, int suf) {
        if (info[p].difr > 0 && info[p].maxlowr < suf) {
            return;
        }
        if (r - l == 1) {
            info[p].max = info[p].maxlowl;
            info[p].maxl = info[p].maxr = l;
            info[p].maxlowl = info[p].maxlowr = -inf;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        maintainR(2 * p + 1, m, r, suf);
        suf = std::max(suf, info[2 * p + 1].max);
        maintainR(2 * p, l, m, suf);
        pull(p);
    }
    void maintainR() {
        maintainR(1, 0, n, -1);
    }
};

struct Tag {
    ull x = 0;
    void apply(const Tag &t) & {
        x += t.x;
    }
};

struct Info {
    ull x = 0;
    void apply(const Tag &t) & {
        x += t.x;
    }
};

Info operator+(const Info &a, const Info &b) {
    return {a.x+b.x};
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>>dp(n+1,vector<int>(2));
    // vector<int>dp(n+10,1);
    // dp[n-1]=1;
    ull p=131;
    // for(int i=n-1;i>=0;i--){
    //     dp[i]=max(1,dp[i]);
    //     ull l=0,r=0;
    //     vector<ull>hashl,hashr;
    //     hashl.push_back(l);
    //     hashr.push_back(r);
    //     int cnt=0;
    //     for(int j=i-1;j>=0;j--){
    //         cnt++;
    //         if(s[j]<s[i]){
    //             dp[j]=max(dp[j],dp[i]+1);
    //         }else if(s[i]==s[j]&&cnt<=n-i&&check(hashl,hashr)){
    //             dp[j]=max(dp[j],dp[i+cnt]+1);
    //         }
    //         if(i+cnt<n){
    //             l=l*p+s[j];
    //             p*=p;
    //             r=r*p+s[i+cnt];
    //             hashl.push_back(l);
    //             hashr.push_back(r);
    //         }
    //     }
    // }
    // cout<<dp[0];
    // vector<int>nxt
    //dp[i][0]:当前位置不为分割点的最大值
    //dp[i][1]：当前位置是分割点的最大值
    dp[1][1]=1;

    auto check=[&](vector<ull>&a, vector<ull>&b)->int{
        int l=0,r=a.size()-1;
        int n=a.size();
        int ans=-1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(a[mid]==b[n-1-mid]){
                l=mid+1;
            }else{
                ans=r;
                r=mid-1;
            }
        }
        if(ans==-1){
            return 2;  //相等
        }
        return a[ans]<b[n-1-ans]; //1是ok 0是不ok
    };
    vector<int>len(n+1);
    for(int i=1;i<n;i++){
        ull l=0,r=0;
        ull pp=1;
        // vector<ull>hashl,hashr;
        LazySegmentTree<Info,Tag>hashl(n),hashr(n);
        int idx=0;
        // hashl.push_back(l);hashr.push_back(r);
        dp[i+1][0]=max(dp[i][0],dp[i][1]);
        int cnt=0;
        for(int j=i-1;j>=0;j--){
            cnt++;
            if(s[i]>s[j]&&j+len[j+1]<i){
                if(dp[j+1][1]+1>dp[i+1][1]){
                    len[i+1]=cnt-1;
                }else if(dp[j+1][1]+1==dp[i+1][1]){
                    len[i+1]=min(len[i+1],cnt-1);
                }
                dp[i+1][1]=max(dp[j+1][1]+1,dp[i+1][1]);
            }else if(s[i]==s[j]){
                int t=check(hashl,hashr);
                if((t==1||t==2&&i+cnt<=n)&&j+len[j+1]<i){
                    if(dp[j+1][1]+1>dp[i+1][1]){
                        len[i+1]=cnt-1;
                    }else if(dp[j+1][1]+1==dp[i+1][1]){
                        len[i+1]=min(len[i+1],cnt-1);
                    }
                    dp[i+1][1]=max(dp[i+1][1],dp[j+1][1]+1);
                }
            }
            if(i+cnt<n){
                l=l*pp+s[j];
                pp*=p;
                r=r*p+s[i+cnt];
                hashl.rangeApply(0,idx+1,l)
                hashl.push_back(hashl.back()+l);
                hashr.push_back(r);
            }
        }
    }
    cout<<max(dp[n][0],dp[n][1]);

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