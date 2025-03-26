#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
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
int qh(int k){
    if(k==1)
    return k;
    else
    return k+qh(k-1);
}
int solve(){
    int n,k,max;
    cin>>n;
    int a[101];
    for(int x=2;x<=n;x++){
        k=n/x;
        a[x]=x*qh(k);
    }
    max=2;
    for(int i=3;i<=n;i++){
        if(a[i]>a[max])
        max=i;
    }
    return max;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<solve()<<'\n';
    }
    return 0;
}