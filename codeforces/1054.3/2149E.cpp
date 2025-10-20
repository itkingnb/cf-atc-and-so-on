#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void yes(){
    cout<<"yes"<<'\n';
}
void no(){
    cout<<"no"<<'\n';
}
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;
template<class Info>
struct SegmentTree {
    int n;
    std::vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
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
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
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
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
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
};

struct Info {
    int mx=1e9;
};

Info operator+(const Info &l, const Info &r) {
    Info x;
    x.mx=min(l.mx,r.mx);
    return x;
}
void AUTO_AC_MACHINE(){
    int n,k,l,r;
    cin>>n>>k>>l>>r;
    vector<int>a(n);
    map<int,int>mp;
    int idx=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(!mp[a[i]]){
            mp[a[i]]=idx++;
        }
    }
    // idx--;
    vector<Info>aa(idx,{(int)1e9});
    SegmentTree<Info>seg(aa);
    map<int,int>cnt;
    int now=0;
    ll ans=0;
    for(int i=0,j=0;j<n;j++){
        // cerr<<seg.rangeQuery(0,idx+1).mx<<'\n';
        if(++cnt[a[j]]==1){
            now++;
        }        
        // cerr<<seg.rangeQuery(0,idx+1).mx<<'\n';
        seg.modify(mp[a[j]],{j});
        // cerr<<seg.rangeQuery(0,idx+1).mx<<'\n';
        // cerr<<mp[a[j]]<<" "<<j<<'\n';
        // bool ok=0;
        while(now>k){
            // ok=1;
            int mxl=seg.rangeQuery(0,idx+1).mx;
            // cerr<<seg.rangeQuery(1,2).mx;
            for(i;i<=mxl;i++){
                if(--cnt[a[i]]==0){
                    now--;
                }
            }
            seg.modify(mp[a[mxl]],{(int)1e9});
            // i++;
        }
        // i+=ok;
        while(j-i+1>r){
            if(--cnt[a[i]]==0){
                seg.modify(mp[a[i]],{(int)1e9});
                now--;
            }
            i++;
        }
        if(now==k&&j-i+1>=l&&j-i+1<=r){
            ans++;
            // cerr<<seg.rangeQuery(0,1).mx<<" "<<seg.rangeQuery(1,2).mx<<" "<<seg.rangeQuery(2,3).mx<<'\n';
            int mxl=seg.rangeQuery(0,idx+1).mx;
            if(j-mxl+1>=l){
                ans+=max(0,mxl-i);
            }else{
                ans+=max(0,j-l+1-i);
            }
            // for(i;i<=min(mxl,j-l+1);i++){
            //     if(--cnt[a[i]==0]){
            //         now--;
            //     }
            // }
        }
    }
    cout<<ans<<'\n';
    

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        AUTO_AC_MACHINE();
    }
}
