#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<malloc.h>
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
    int n,f,k;
    cin>>n>>f>>k;
    vector<int>a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    f=a[f-1];
    if(n==1||n==k){
    yes();
    return 0;
    }
    sort(a.begin(),a.end());
    if(a[n-k-1]<f){
        yes();
    }else{
        if(a[n-k]==f&&a[n-k-1]==f)
        cout<<"maybe";
        else
        no();
    }
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