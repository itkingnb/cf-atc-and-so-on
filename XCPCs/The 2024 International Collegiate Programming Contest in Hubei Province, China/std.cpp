#include<bits/stdc++.h>
using ll=long long;
using LL=long long;
#define int ll
const int N=110;
const int mod=998244353;
int c[N];
int k=0;
int g[N][N];
 
ll lcm(ll a,ll b)
{
    return (ll)a/std::__gcd(a,b)*b;
}
void floyd()
{
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i==j) g[i][j]=0;
            else g[i][j]=lcm(c[i],c[j]);
        }
    }
    for(int p=1;p<=k;p++)
    {
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=k;j++)
            {
                g[i][j]=std::min(g[i][j],g[i][p]+g[p][j]);
            }
        }
    }
}
void solve()
{
    memset(c,0,sizeof c);
    k=0;
    int a,b;
    std::cin>>a>>b;
    c[++k]=a,c[++k]=b,c[++k]=2;
    if(std::__gcd(a,b)!=1)
    {
        c[++k]=std::__gcd(a,b);
    }
 
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)
        {
            c[++k]=i;
            break;
        }
    }
    for(int i=2;i*i<=b;i++)
    {
        if(b%i==0)
        {
            c[++k]=i;
            break;
        }
    }
    std::sort(c+1,c+1+k);
    k=std::unique(c+1,c+1+k)-c-1;
    int aa=0;
    for(int i=1;i<=k;i++)
    {
        //std::cout<<c[i]<<" ";
        if(c[i]==a)
        {
            aa=i;
            break;
        }
    }
    //std::cout<<'\n';
    floyd();
    std::cout<<g[aa][k]<<'\n';
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    std::cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}