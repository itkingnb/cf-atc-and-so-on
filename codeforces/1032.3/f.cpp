#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
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
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b){
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
const int MAX_LEN =2e5+10 ;
int seg_tree[MAX_LEN << 2];
int Lazy[MAX_LEN << 2];
int arr[MAX_LEN];
//从下往上更新 节点
void push_up (int root) {
    seg_tree[root] = max(seg_tree[root << 1], seg_tree[root << 1 | 1]);      //最小值改min
}
//从上向下更新，左右孩子
void push_down (int root, int L, int R) {
    if(Lazy[root]){
        Lazy[root << 1] += Lazy [root];
        Lazy[root << 1 | 1] += Lazy[root];
        int mid = (L + R) >> 1;
        seg_tree[root << 1] +=  Lazy[root] * (mid - L + 1);
        seg_tree[root << 1 | 1] += Lazy[root] * (R - mid);
        Lazy[root] = 0;
    }
}
//建树
//[L,R]就是对应arr数组里面的数
void build (int root, int L, int R) {
    Lazy[root] = 0;
    if(L == R) {
        seg_tree[root] = arr[L];
        return ;
    }
    int mid = (L + R) >> 1;
    build(root << 1, L, mid);
    build(root << 1 | 1, mid + 1, R);
    push_up(root);
}

//区间查询
//查找区间[LL,RR]的最大/小值
int query (int root, int L, int R, int LL, int RR) {
    if (LL <= L && R <= RR) return seg_tree[root];
    push_down(root, L, R);     //每次访问都去检查Lazy 标记
    int Ans = 0;
    int mid = (L + R) >> 1;
    if(LL <= mid) Ans = max(Ans, query(root << 1, L, mid, LL, RR));    //最小值改min
    if(RR > mid) Ans = max(Ans, query(root << 1 | 1, mid + 1, R, LL, RR)); //最小值改min
    return Ans;
}
//区间修改 +-某值
//使得区间[LL,RR]的值都加上val
void update_Interval(int root, int L, int R, int LL, int RR, int val){
     if (LL <= L && R <= RR) {
         Lazy[root] += val;
         seg_tree[root] += val * (R - L + 1);
        return ;
     }
     push_down(root, L, R);
     int mid = (L + R) >> 1;
     if (LL <= mid) update_Interval(root << 1, L, mid, LL, RR, val);
     if (RR > mid) update_Interval(root << 1 | 1, mid + 1, R, LL , RR, val);
     push_up(root);
}
//单点修改 可以改为某值，或者+-某值
//把pos位置的值改成val
void update(int root, int L, int R, int pos, int val) {
    if(L == R){
        seg_tree[root] = val;    //点直接变为某值
        return ;
    }
    int mid = (L + R) >> 1;
    if(pos <= mid) update(root << 1, L, mid, pos, val);
    else update(root << 1 | 1, mid + 1, R, pos, val);
    push_up(root);
}
void solve(){
    int n;
    ll s,x;
    cin>>n>>s>>x;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll ans=0;
    bool ok=false;
    ll now=0;
    map<ll,ll>mp;
    ll mx=-1e10;
    for(int i=0;i<n;i++){
        now+=a[i];
        mx=max(mx,a[i]);
        if(a[i]>x){
            mx=-1e10;
            now=0;
            ok=false;
            mp.clear();
            continue;
        }else if(mx==x){
            ok=true;
        }
        mp[now]++;
        if(!ok){
            continue;
        }
        if(now-s==now){
            ans+=mp[now-s]-1;
        }else{
            ans+=mp[now-s];
        }
    }
    cout<<ans;
    // for(int i=1;i<=n;i++){
    //     cin>>arr[i];
    // }
    // ll ans=0;
    // build(1,1,n);
    // ll now=0;
    // for(int i=1,j=1;j<n;j++){
    //     now+=arr[i];
    //     if(now>)
    // }

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