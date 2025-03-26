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
    int n,m,k;
    int ans=0;
    char a[50];
    cin>>n>>m;
    int b[7]={m,m,m,m,m,m,m};
    for(int i=0;i<n;i++){
        cin>>a[i];
        k=a[i]-65;
        if(b[k]!=0)
        b[k]--;
        else
        continue;
    }
    for(int j=0;j<7;j++)
    ans+=b[j];
    return ans;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<solve()<<'\n';
    }
    return 0;
}