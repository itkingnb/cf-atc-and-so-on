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
    int *a,*b,n,k=0,flag=1,t=0;
    cin>>n;
    a=(int*)malloc(4*n);
    b=(int*)malloc(4*n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(j==i)
            continue;
            else{
                if(j+1==i&&j+2>n-1)
                continue;
                if((j+1)==i){
                b[k]=gys(a[j],a[j+2]);
                k++;
                }
                else{
                b[k]=gys(a[j],a[j+1]);
                k++;
                }
            }
        }
            for(int j=0;j<n-3;j++){
            if(b[j]>b[j+1])
            flag=0;
        }
        if(flag==1){
        yes();
        t=1;
        break;
        }
        else{
            flag=1;
            k=0;
            continue;
        }
    }
    if(t==0)
    no();
    free(a);
    free(b);
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