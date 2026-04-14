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
    cout<<"YES";
}
void no(){
    cout<<"NO";
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
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string>s(n);
    vector<pii>p1,p2;
    for(int i=0;i<n;i++){
        cin>>s[i];
        for(int j=0;j<m;j++){
            if(s[i][j]=='1'){
                p1.push_back({i,j});
            }else if(s[i][j]=='2'){
                p2.push_back({i,j});
            }
        }
    }
    bool ok=0;
    auto check=[&](int x,int y)->bool{
        return x>=0&&y>=0&&x<n&&y<m;
    };
    auto bfs=[&](vector<pii>& a,vector<pii>& b,char ch)->void{
        vector<vector<pii>>nxt(n,vector<pii>(m,{-1,-1}));
        vector<string>t=s;
        queue<pii>q;
        vector<vector<bool>>vis(n,vector<bool>(m));
        q.push(a[0]);
        int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
        while(q.size()){
            auto [x,y]=q.front();q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx==a[1].first&&ny==a[1].second){
                    nxt[nx][ny]={x,y};
                    goto out;
                }
                if(check(nx,ny)&&(s[nx][ny]!='1'&&s[nx][ny]!='2')&&nxt[nx][ny].first==-1&&nxt[nx][ny].second==-1){
                    nxt[nx][ny]={x,y};
                    q.push({nx,ny});
                }
            }
        }
        out:
        int tx=a[1].first,ty=a[1].second;
        if(nxt[tx][ty].first==-1&&nxt[tx][ty].second==-1){
            return ;
        }
        while(tx!=a[0].first||ty!=a[0].second){
            t[tx][ty]=ch;
            int ttx=tx,tty=ty;
            tx=nxt[ttx][tty].first;
            ty=nxt[ttx][tty].second;
        }
        while(q.size()) q.pop();
        q.push(b[0]);
        vis[b[0].first][b[0].second]=1;
        while(q.size()){
            auto [x,y]=q.front();q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx==b[1].first&&ny==b[1].second){
                    ok=1;
                    return ;
                }
                if(check(nx,ny)&&t[nx][ny]=='0'&&!vis[nx][ny]){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }        
    };
    bfs(p1,p2,'1');
    bfs(p2,p1,'2');
    ok?yes():no();
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