#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
using namespace std;
   
int main(){
    int n,t=0,zong=0,y,z,left=0;
    cin>>n;
    int a[1000]={0};
    int b[1000]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
        zong+=a[i];
    }
    cin>>y>>z;
    if((2*y+1)>n){
        for(int k=0;k<n;k++){
            if(a[k]>z)
            left+=a[k]-z;
        }
        goto out;
    }
    for(int i =0;i<=n-(2*y+1);i++){
        for(int j=i;j<i+2*y+1;j++){
        if (a[j]<z)
        b[i]+=a[j];
        else{
        b[i]+=z;
        }
    }
        if(b[i]>b[t])
        t=i;
    }
    cout<<zong-b[t]<<'\n';
    return 0;
    out:cout<<left<<'\n';
}