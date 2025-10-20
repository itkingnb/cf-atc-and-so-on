struct ODT {
    const int n;
    map<int, int> mp;
    ODT(int n) : n(n) { mp[-1] = 0 }
    void split(int x) {
        auto it = prev(mp.upper_bound(x)); //找到左端点小于等于x的区间
        mp[x] = it->second; //设立新的区间，并将上一个区间储存的值复制给本区间。
    }
    void assign(int l, int r, int v) { // 注意，这里的r是区间右端点+1
        split(l);
        split(r);
        auto it = mp.find(l);
        while (it->first != r) {
            it = mp.erase(it);
        }
        mp[l] = v;
    }
    void update(int l, int r, int c) { // 其他操作
        split(l);
        split(r);
        auto it = mp.find(l);
        while (it->first != r) {
            // 根据题目需要做些什么
            it = next(it);
        }
    }
};