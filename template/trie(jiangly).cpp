
constexpr int N = 200000 * 31;

int tot;

int trie[N][2];
int cnt[N];

int newNode() {
    int x = ++tot;
    trie[x][0] = trie[x][1] = 0;
    cnt[x] = 0;
    return x;
}

void init() {
    tot = 0;
    newNode();
}

void add(int x, int t) {
    int o = 1;
    for (int i = 29; i >= 0; i--) {
        int &p = trie[o][x >> i & 1];
        if (!p) {
            p = newNode();
        }
        o = p;
        cnt[o] += t;
    }
}

int query(int x) {
    int o = 1;
    int ans = 0;
    for (int i = 29; i >= 0; i--) {
        int d = x >> i & 1;
        if (cnt[trie[o][d ^ 1]]) {
            d ^= 1;
            ans |= 1 << i;
        }
        o = trie[o][d];
    }
    return ans;
}