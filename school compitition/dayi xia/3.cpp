#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
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
    int n,a[100000],b[100000],c[100000]={0},i,max,min,k;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        if(i==0)
        {max=b[i]; min=b[i];}
        else
        {max=a[0]; min=a[0];}
        for(int j=0;j<n;j++){

        if(i==j)
        k=b[j];
        else
        k=a[j];
        c[i]+=k;
        if(k>max)
        max=k;
        if(k<min)
        min=k;
        }
        c[i]=c[i]-max-min;
    }
    max=c[0];
    for(i=1;i<n;i++){
        if(c[i]>max)
        max=c[i];
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