#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
using namespace std;
#include<ctime>
#define ll long long
int jc(int n){
    if(n==1||n==0)
    return 1;
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
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
void solve(){
    ll h;
    int n;
    ll ans=0;
    cin>>h>>n;
    ll leijia=0;
    vector<int>a(n,0);
    vector<int>cd(n,0);
    vector<int>c(n,0);
    for(int i=0;i<n;i++){
    cin>>a[i];
    leijia+=a[i];
    }
    h-=leijia;
    for(int i=0;i<n;i++){
        cin>>c[i];
        cd[i]=c[i];
    }
    while (h>0)
    {
        int minele=*min_element(c.begin(),c.end());
        int num=count(c.begin(),c.end(),minele);
        int k=-1;
        while(num--){
            auto k1=find(c.begin()+k+1,c.end(),minele);
            k=distance(c.begin(),k1);
            h-=a[k];
            if(h<=0){
                cout<<ans+minele+1;
                return;
            }
            c[k]+=cd[k];
        }
    ans+=(ll)minele;
    if(h<=0)
    break;
    for(int i=0;i<n;i++)
    c[i]-=minele;
    }
    cout<<ans+1;
}
signed main(){
    time_t start=time(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    time_t end=time(0);
    cout<<difftime(end,start)<<'\n';
    return 0;
}