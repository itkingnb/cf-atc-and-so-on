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
int solve(){
    char a[3],b[3];
    char m,n;
    for(int i=0;i<3;i++)
    cin>>a[i];
    for(int i=0;i<3;i++)
    cin>>b[i];
    m=a[0];
    n=b[0];
    a[0]=n;
    b[0]=m;
    for(int i=0;i<3;i++)
    cout<<a[i];
    cout<<" ";
    for(int i=0;i<3;i++)
    cout<<b[i];
    return 0;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}