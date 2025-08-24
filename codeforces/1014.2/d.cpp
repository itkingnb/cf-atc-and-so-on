#include<bits/stdc++.h>
#define pii pair<int,int>
#define mii map<int,int>
#define msi map<string,int>
#define ll long long
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int c[3]={0};
    auto get=[&](char ch)->int{
        if(ch=='I'){
            return 0;
        }else if(ch=='L'){
            return 1;
        }
        return 2;
    };
    auto get1=[&](int sum)->int{
        return 3-sum;
    };
    vector<int>op;
    int mx=0;
    for(int i=0;i<n;i++){
        c[get(s[i])]++;
        mx=max(mx,c[get(s[i])]);
    }
    int bia=1;
    for(int i=0;i<n-1;i++){
        int cnt=0;
        if(s[i]==s[i+1]){
            continue;
        }else if(c[get1(get(s[i])+get(s[i+1]))]!=mx){
            c[get1(get(s[i])+get(s[i+1]))]++;
            op.push_back(i+bia);
            cnt++;
            while(c[get(s[i+1])]!=mx||c[get1(get(s[i])+get(s[i+1]))]!=mx){
                if(c[get(s[i+1])]!=mx){
                    op.push_back(i+bia);c[get(s[i+1])]++;
                    cnt++;
                }
                else{
                    break;
                }
                if(c[get1(get(s[i])+get(s[i+1]))]!=mx){
                    c[get1(get(s[i])+get(s[i+1]))]++;
                    op.push_back(i+bia);
                    cnt++;
                }
                else{
                    break;
                }
            }
            bia+=cnt;
            while(c[get(s[i])]!=mx||c[get1(get(s[i])+get(s[i+1]))]!=mx){
                if(c[get(s[i])]!=mx){
                    op.push_back(i+bia);c[get(s[i])]++;
                    bia++;
                }
                else{
                    break;
                }
                if(c[get1(get(s[i])+get(s[i+1]))]!=mx){
                    c[get1(get(s[i])+get(s[i+1]))]++;
                    op.push_back(i+bia);
                    bia++;
                }
                else{
                    break;
                }
            }
        }
    }
    auto check=[&]()->bool{
        return c[0]==c[1]&&c[1]==c[2]&&op.size()<=2*n;
    };
    // assert(op.size()<=2*n);

    if(check()){
        cout<<op.size()<<'\n';
        for(auto x:op){
            cout<<x<<'\n';
        }
    }else{
        cout<<-1;
    }
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