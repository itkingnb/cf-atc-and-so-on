#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#define ll long long
using namespace std;
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
    int n,l,r;
    cin>>n>>l>>r;
    vector<int>a(n+1,0);
    vector<int>dp(n+1,0);
    vector<ll>leijia(n+1,0);
    for(int i=1;i<=n;i++){
    cin>>a[i];
    leijia[i]=leijia[i-1]+a[i];
    }
    if(a[1]>=l&&a[1]<=r)
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1];
        if(a[i]>=l&&a[i]<=r){
            dp[i]=dp[i-1]+1;
            continue;
        }
        if(a[i]<l){
            //int k=a[i];//目的是找到leijia[i]-leijia[?]表示了从？-i这一段加起来可以赢
            int z=0;
            int y=i;
            if(leijia[i]-leijia[0]<l)
            continue;
            if(leijia[i]-leijia[0]==l)
            dp[i]=max(1,dp[i]);
            else{
                do{
                int mid=(z+y)/2;
                //if(leijia[i]-leijia[mid]>r)
                //z=mid;
                if(leijia[i]-leijia[mid]<l)
                y=mid;
                else
                z=mid;
                }while(y-z!=1);
                if(leijia[i]-leijia[z]>=l&&leijia[i]-leijia[z]<=r)
                dp[i]=max(dp[z]+1,dp[i]);
            }
        }
    }
    cout<<dp[n];
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
    return 0;
}