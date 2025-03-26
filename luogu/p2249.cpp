#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll jc(ll n){
    if(n==1||n==0)
    return (ll)1;
    else
    return n*jc(n-1);
}
void yes(){
    cout<<"Yes\n";
}
void no(){
    cout<<"No\n";
}
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
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

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int>a(n,0);
    vector<int>b(m,0);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(int i=0;i<m;i++){
    scanf("%d",&b[i]);
    int l=0,r=n-1;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if(a[mid]>=b[i])
        r=mid;
        else
        l=mid+1;
    }
    if(a[l]==b[i])
    b[i]=l+1;
    else
    b[i]=-1;
}
    for(int i=0;i<m;i++)
    printf("%d ",b[i]);
}