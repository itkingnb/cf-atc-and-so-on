#include<iostream>
using namespace std;
int jc(int n){
    if(n==1||n==0)
    return 1;
    else
    return n*jc(n-1);
}
int c(int a,int b){
    return jc(a)/(jc(b)*jc(a-b));
}

int main(){
    int n,b[21],i=1,left,kong,all=0,j,ans=0;
    char a;
    cin>>n;
    do{
        cin>>a;
        if(a=='Q')
        break;
        cin>>b[i];
        left=n-b[i];
        all+=b[i];
        i++;
    }while (a!='Q');
    //cout<<i<<'\n';
    i--;
    kong=i-1;
    left=n-kong-all;
    //cout<<left;
    kong+=2;
    //cout<<kong;
    ans+=c(left+kong-1,kong-1);
    /*for(j=1;j<=left;j++){
        ans+=c(kong,j);
    }*/
    ans*=jc(i);
    cout<<ans;
    return 0;
}