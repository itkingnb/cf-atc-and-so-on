#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
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
    int n;
    int cnt=0;
    cin>>n;
    vector<int>a(n,0);
    vector<int>b(n+1,0);
    for(int i=0;i<n;i++){
    cin>>a[i];
    b[a[i]]++;
    }
    vector<int>c;
    for(int i=0;i<n;i++){
        if(b[i]){
            cnt++;
            c.push_back(b[i]);
        }
    }
    vector<vector<int>>dp(cnt,vector<int>(n+1,0));
    //int k=c[0];
    for(int i=1;i<cnt;i++){
        //k+=c[i];
        for(int j=1;j<n+1;j++){
            dp[i][j]=dp[i-1][j];
            if(j>c[i])
            dp[i][j]=max(dp[i][j],dp[i-1][j-c[i]-1]+1);
        }
    }
    cout<<n-dp[cnt-1][n];
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