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
#define int ll
void solve(){
    int x,y;
    bool debug=0;
    int xx,yy;
    cin>>x>>y;
    if(debug){
        cin>>xx>>yy;
    }
    int ans1=0,ans2=0;
    int sum=0,sum1=0,sum2=0,sum0=0;
    bool ok=0;
    bool sw=0;
    for(int i=0;i<32;i++){
        if(((x>>i)&1)&&((y>>i)&1)){
            sum+=(1<<i);
            ok=1;
        }else{
            if(!((x>>i)&1)&&!((y>>i)&1)&&ok){
                bool f1=0,f2=0,f3=0;
                if((1<<i)-sum1<=sum){
                    f1=1;
                }
                if((1<<i)-sum2<=sum){
                    f2=1;
                }
                if((1<<i)-sum1>=sum0||(1<<i)-sum2>=sum0){
                    ans1+=sum0;
                    ans2+=sum;
                    sum=0;
                    sum0=0;
                    sum1+=(((x>>i)&1)<<i);
                    sum2+=(((y>>i)&1)<<i);
                    ok=0;
                    continue;
                }
                if(f1&&f2){
                    if(abs((1<<i)-sum1)>abs((1<<i)-sum2)){
                        swap(ans1,ans2);
                        swap(sum1,sum2);
                        sw=1;
                    }
                }else if(f2){
                    swap(ans1,ans2);
                    swap(sum1,sum2);
                    sw=1;
                }
                if(f1||f2){
                    ans1=(1<<i);
                    ans2=sum2;
                }
                ok=0;
                if(sw){
                    swap(ans1,ans2);
                    swap(sum1,sum2);
                    sw=0;
                }
                sum=0;
                sum0+=(1<<i);
                sum1+=(((x>>i)&1)<<i);
                sum2+=(((y>>i)&1)<<i);
                continue;
            }else if(!((x>>i)&1)&&!((y>>i)&1)){
                sum0+=(1<<i);
            }
            ans1+=(((x>>i)&1)<<i);
            ans2+=(((y>>i)&1)<<i);
        }
        sum1+=(((x>>i)&1)<<i);
        sum2+=(((y>>i)&1)<<i);
    }
    cout<<ans1<<" "<<ans2;
    cerr<<abs(x-ans1)+abs(y-ans2)<<endl;
    if(debug){
        cerr<<abs(x-xx)+abs(y-yy)<<endl;
    }
}
/*
0
1
2
3
4
65
1073741822
*/
/*
0
1
2
3
1
5
1

*/
signed main(){
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