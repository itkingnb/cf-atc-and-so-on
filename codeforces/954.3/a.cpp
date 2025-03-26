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
    int x1,x2,x3;
    cin>>x1>>x2>>x3;
    int a[11]={0};
    for(int i=1;i<=10;i++){
        a[i]=fabs(x1-i)+fabs(x2-i)+fabs(x3-i);
    }
    sort(a,a+11);
    cout<<a[1];
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