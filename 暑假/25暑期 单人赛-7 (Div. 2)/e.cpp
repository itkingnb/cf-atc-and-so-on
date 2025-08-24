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
#define N 500010
map<int,int>mp;
int idx,tree[N][62];
//cnt[x]代表以x为结点结束的个数，tree[x][y]指从节点x通过字符y指向的下一个节点，y是字符的数字映射

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m,0));
    vector<int>b(m,0);
    auto build=[&](vector<int>&s)->void{
        int p=0;
        for(int i=0;i<s.size();i++){
            int m=s[i];
            if(!tree[p][m]) tree[p][m]=++idx;
            p=tree[p][m];   
        }
    };
    auto query=[&](vector<int> &s)->int{
        int p=0,m=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            m=s[i];
            if(!tree[p][m])
            return ans;
            p=tree[p][m];
            ans++;
        }
        return ans;
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            b[a[i][j]-1]=j+1;
        }
        build(b);
    }
    for(int i=0;i<n;i++){
        cout<<query(a[i])<<' ';
    }
    for(int i=0;i<=idx;i++)
        memset(tree[i],0,sizeof(tree[i]));
    idx=0;

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