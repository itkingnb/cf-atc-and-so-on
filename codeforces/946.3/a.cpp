#include<iostream>
using namespace std;

int solve(int x,int y){
    int ans=0;
    ans=y/2;
    x=x-ans*7;
    if((y-ans*2)==1){
        if(x-11<=0)
        return ans+1;
        else 
        return ans+1+(x-11)/15.1+1;  
    }
    else{
        if(x<=0)
        return ans;
        else
        return ans+x/15.1+1;
    }
    return 0;
}
int main(){
    int t,x,y;
    cin>>t;
    for(int i=0;i<t;i++){
    cin >> x >> y;
    cout<<solve(x,y)<<'\n';
}
    return 0;
}