#include<bits/stdc++.h>
using namespace std;
bool judge(int x){
    int a[5]={0},i=0;
    do{
        a[i]=x%10;
        if(a[i]==4)
        return false;
        x/=10;
        i++;
    }while(x!=0);
    return true;
}
int main(){
    int ans=0;
    for(int i=10000;i<=99999;i++){
        if(judge(i)){
        ans++;
        cout<<i<<" ";
        }
    }
    cout<<ans;
    return 0;
}