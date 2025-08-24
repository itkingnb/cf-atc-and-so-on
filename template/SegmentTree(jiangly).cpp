#include <bits/stdc++.h>

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
    int ans = 0;
    int sum = 0;
    int pre = 0;
    int suf = 0;
};

Info operator+(const Info &l, const Info &r) {
    Info x;
    x.ans = std::max({l.ans, r.ans, l.suf + r.pre});
    x.sum = l.sum + r.sum;
    x.pre = std::max(l.pre, l.sum + r.pre);
    x.suf = std::max(r.suf, r.sum + l.suf);
    return x;
}

void solve() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    
    std::vector<std::vector<std::array<int, 3>>> op(n);
    for (int i = 0; i < n; i++) {
        op[a[i]].push_back({0, i, 1});
    }
    for (int i = 0; i < q; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        op[a[x]].push_back({i, x, -1});
        a[x] = y;
        op[a[x]].push_back({i, x, 1});
    }
    for (int i = 0; i < n; i++) {
        op[a[i]].push_back({q, i, -1});
    }
    
    SegmentTree<Info> seg(n);
    for (int i = 0; i < n; i++) {
        seg.modify(i, {0, -1, 0, 0});
    }
    
    std::vector<std::vector<std::array<int, 2>>> e(q);
    for (int v = 0; v < n; v++) {
        int lst = 0;
        for (auto [i, x, t] : op[v]) {
            int res = seg.rangeQuery(0, n).ans;
            if (lst < i) {
                e[lst].push_back({res / 2, 1});
                if (i < q) {
                    e[i].push_back({res / 2, -1});
                }
            }
            lst = i;
            seg.modify(x, {std::max(0, t), t, std::max(0, t), std::max(0, t)});
        }
    }
    
    std::multiset<int> S;
    for (int i = 0; i < q; i++) {
        for (auto [x, t] : e[i]) {
            if (t == 1) {
                S.insert(x);
            } else {
                S.extract(x);
            }
        }
        
        assert(!S.empty());
        std::cout << *S.rbegin() << " \n"[i == q - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}