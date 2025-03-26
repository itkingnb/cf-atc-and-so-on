#include<bits/stdc++.h>
using namespace std;
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
    int n,m;
    cin>>n>>m;
    int l=max(0,n-m);
    int r=n+m;
    int ans=0;
    int flag=0;
    for(int i=30;i>=0;i--){
        if((r>>i)%2==1||(l>>i)%2==1||(r>>(i+1))!=l>>(i+1)||flag){
            ans+=(1<<i);
            if((r>>(i+1))!=l>>(i+1))
            flag=1;
        }
    }
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }

}