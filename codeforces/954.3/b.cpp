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
    int s[110][110]={0};
    int i,j;
    int n,m;
    cin>>n>>m;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            cin>>s[i][j];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(s[i][j]>s[i-1][j]&&s[i][j]>s[i+1][j]&&s[i][j]>s[i][j-1]&&s[i][j]>s[i][j+1]){
                int max1=max(s[i-1][j],s[i+1][j]);
                int max2=max(s[i][j-1],s[i][j+1]);
                s[i][j]=max(max1,max2);    
            }
            cout<<s[i][j]<<" ";
        }
        cout<<'\n';
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
    return 0;
}