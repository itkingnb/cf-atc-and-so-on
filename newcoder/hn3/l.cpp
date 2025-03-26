#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pss pair<string,string>
#define fi first
#define se second
#define psss pair<string,vector<string>>
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
    int n,k,q;
    int t=0;
    cin>>n>>k>>q;
    pss sec[n];
    psss ip[k];
    psss users[1000];
    int flag=0;
    for(int i=0;i<n;i++){
        cin>>sec[i].second>>sec[i].first;
    }
    for(int i=0;i<k;i++){
        cin>>ip[i].first;
        int us;
        cin>>us;
        for(int j=0;j<us;j++){
            string user;
            cin>>user;
            users[t].first=user;
            ip[i].second.push_back(user);
            int num;
            cin>>num;
            for(int k=0;k<num;k++){
                string s;
                cin>>s;
                users[t].second.push_back(s);
            }
            t++;
        }
    }
    for(int i=0;i<q;i++){
        flag=0;
        string fy;
        string p,ipp,keyy;
        cin>>p>>ipp>>keyy;
        for(int i=0;i<k;i++){
            if(ipp==ip[i].first){
                for(auto& s:ip[i].second)
                if(s==p){
                    for(auto&[x,y]:sec)
                    if(x==keyy)
                    fy=y;
                    for(int tt=0;tt<t;tt++){
                        if(users[tt].first==p){
                            for(auto&ss:users[tt].second)
                            if(ss==fy)
                            flag++;
                        }
                    }
                }
            }
        }
        if(flag)
        yes();
        else
        no();
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}