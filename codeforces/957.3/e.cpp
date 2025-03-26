#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#include<queue>
#include<map>
#define int long long
using namespace std;
int jc(int n){
    if(n==1||n==0)
    return 1;
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
void solve(){
    int n;
    cin>>n;
    pair<int,int>ans[10000];
    int idx=0;
    if(n<10){
        for(int i=1;i<=10000;i++){
            int c=min(i*n,(long long)10000);
            for(int j=1;j<=c;j++){
                if(n*(9*i+1-pow(10,i-j))==9*j){
                ans[idx].first=i;
                ans[idx].second=j;
                idx++;
                }
            }
        }
    }
    if(n>9&&n<100){
        int limit=n+100*n+n*10000;
        for(int i=1;i<=10000;i++){
            int c=min(i*n,(long long)10000);
            if(n*i-c>limit)
                continue;
            for(int j=1;j<=c;j++){
                if(n*(99*i+1-pow(100,i-j))==99*j){
                ans[idx].first=i;
                ans[idx].second=j;
                idx++;
                }
            }
        }
    }
    if(n==100){
        for(int i=1;i<=10000;i++){
            int c=min(i*n,(long long)10000);
            for(int j=1;j<=c;j++){
                if(n*(999*i+1-pow(1000,i-j))==999*j){
                ans[idx].first=i;
                ans[idx].second=j;
                idx++;
                }
            }
        }
    }
    cout<<idx<<'\n';
    for(int i=0;i<idx;i++)
    cout<<ans[i].first<<" "<<ans[i].second<<'\n';

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        //cout<<'\n';
    }
    return 0;
}