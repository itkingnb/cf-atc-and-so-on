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
    int n,a[100001]={0};
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    vector<int> dp(n,0);
    dp[n-1]=a[n-1];
    //int max1=dp[n-1];
    for(int i=n-2;i>=0;i--){
        dp[i]=max(dp[i+1]+1,a[i]);
    }
    sort(dp.begin(),dp.end());
    cout<<dp[n-1];

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