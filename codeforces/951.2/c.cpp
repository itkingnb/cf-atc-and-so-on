#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
using namespace std;
#define int long long
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
int solve(){
    int *a;
    int n,i,k=1;
    int y=-1;
    int t=0;
    cin>>n;
    a=(int*)malloc(8*n);
    for(i=0;i<n;i++){
        cin>>a[i];
        k=lcm(a[i],k);
    }    
    for(i=0;i<n;i++){
        t+=(k/a[i]);
    }
    if(t>=k){
    cout<<y;
    return 0;
    }else{
        for(i=0;i<n;i++){
            cout<<k/a[i]<<" ";
        }
    }
    free(a);
    return 0;
}

signed main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}