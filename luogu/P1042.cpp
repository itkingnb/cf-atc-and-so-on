#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
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

void solve(){
    string s;
    queue<pii>q;
    int i=0;
    int a[4]={0};
    while(1){
        if(i==s.size()){
            cin>>s;
            i=0;
        }
        else{
            for(i=0;i<s.size();i++){
                if(s[i]=='W'){
                    a[0]++;
                    a[2]++;
                }
                else{
                    if(s[i]=='L'){
                    a[1]++;
                    a[3]++;
                    }
                    else{
                    cout<<a[0]<<":"<<a[1]<<'\n';
                    q.push({a[2],a[3]});
                    goto out;
                    }
                }
                if((a[0]>=11||a[1]>=11)&&abs(a[0]-a[1])>=2){
                    cout<<a[0]<<":"<<a[1]<<'\n';
                    a[0]=0;
                    a[1]=0;
                }
                if((a[2]>=21||a[3]>=21)&&abs(a[2]-a[3])>=2){
                    q.push({a[2],a[3]});
                    a[2]=0;
                    a[3]=0;
                }
            }
        }
    }
    out:
    cout<<'\n';
    while (!q.empty())
    {
        auto u=q.front();
        q.pop();
        cout<<u.first<<":"<<u.second<<'\n';
    }
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}