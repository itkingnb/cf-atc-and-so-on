#include<iostream>
using namespace std;


int solve(){
    int n,i,m,c=0,flag=0;
    cin>>n;
    int b[32]={0};
    int a[32]={0};
    for(i=0;n!=0;i++){
        b[i]=n%2;
        n/=2;
    }
    for(n=0;n<32;n++){
        if(b[n]==1&&b[n+1]!=1){
        a[n]=b[n];
        flag=n+1;
        }
        else{
        if(b[n]==0)
        a[n]=b[n];
        else{
            m=n+2;
            while (b[m]!=0)
            {
                m++;
            }
                a[n]=-1;
                for(n=n+1;n<=m;n++)
                a[n]=0;
                a[m]=1;
                b[m]=1;
                n=m-1;
                flag=m+1;
            }
        }
    }
    cout<<flag<<'\n';
    for(n=0;n<flag;n++){
        cout<<a[n]<<" ";
    }
    return 0;
}

int main(){
    int t,i;
    cin>>t;
    for(i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}