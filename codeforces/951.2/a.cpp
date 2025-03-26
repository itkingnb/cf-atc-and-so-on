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
int gys(int a,int b){
    int c;
    if(b>a){
        a=a+b;
        b=a-b;
        a=a-b;
    }
    do{
        c=a%b;
        a=b;
        b=c;
    }while (c!=0);
    return a;
}
int gbs(int a,int b){
    return a*b/gys(a,b);
}

int solve(){
    int*a;
    int n,i,k=0;
    cin>>n;
    a=(int*)malloc(4*n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    k=max(a[0],a[1]);
    for(i=1;i<n-1;i++)
    if(max(a[i],a[i+1])<k){
        k=max(a[i],a[i+1]);
    }
    cout<<k-1;
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