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
    int n,i,m=0,ii=0,zuida=0,zuixiao=0,s=0,p,flag=0,iii=0;               //p小2
    int a[1000]={0},d[1000]={0},c[1000]={0};
    cin>>n;
    cin>>a[0];
    zuida=a[0];
    zuixiao=a[0];
    s+=a[0];
    for(i=1;i<n;i++){
        cin>>a[i];
        if(a[i]>zuida)
        zuida=a[i];
        if(a[i]<zuixiao)
        zuixiao=a[i];
    }
    for(i=0;i<n;i++){
        cin>>d[i];
        c[i]=d[i]-a[i];
    }
    do{
        p=c[0];
        ii=0;
        for(i=1;i<n;i++){
            if(c[i]>p){
                p=c[i];
                ii=i;//pmax
            }
        }
        if(a[ii]==zuida){
        c[ii]=0;
        continue;
        }
        if(a[ii]==zuixiao){
            for(i=0;i<n;i++){
                if(a[i]<=d[ii]&&ii!=i){
                flag++;
                iii=i;                       //flag=0 改后的也还是最小            flag不等于0 有比最小的改后大的
            }
        }
            if(flag==0){
                c[ii]=0;
            }else{
                a[ii]=d[ii];
                break;
            }
    }
    if(a[ii]<zuida&&a[ii]>zuixiao){
        
    }
    }while(1);
    zuida=a[0];
    zuixiao=a[0];
    s=0;
    s+=a[0];
    for(i=1;i<n;i++){
        if(a[i]>zuida){
            zuida=a[i];
        }
        if(a[i]<zuixiao){
            zuixiao=a[i];
        }
        s+=a[i];
    }

    return s-zuida-zuixiao;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<solve()<<'\n';
    }
    return 0;
}