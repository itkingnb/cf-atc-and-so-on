template <typename T>
struct Fenwick
{
    int n;
    vector <T> a;

    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n + 1, T{});
    }

    int lowbit(int x)
    {
        return x & -x;
    }

    void add(int x, const T &v)
    {
        while (x <= n) {
            a[x] += v;
            x += lowbit(x);
        }
    }

    T sum(int x)
    {
        T ans{};
        while (x >= 1) {
            ans += a[x];
            x -= lowbit(x);
        }
        return ans;
    }

    T rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << __lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};