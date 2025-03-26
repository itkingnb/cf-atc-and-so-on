#include <iostream>
using namespace std;
int solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int max=a;
    if((a+b+c)%2==1)
        return -1;
    if(a<b){
        if(c>b)
        max=c;
        else
        max=b;
    }
    else{
        if(c>a)
        max=c;
    }
    if(a+b+c-max>=max){
        return (a+b+c)/2;
    }
    else
        return a+b+c-max;
}
int main(){
    int i,t=0;
    cin>>t;
    for(i=0;i<t;i++){
        cout<<solve()<<"\n";

    }
}