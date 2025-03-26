#include<iostream>
#include<cmath>
using namespace std;


int solve(){
    int n,m;
    cin>>n>>m;
    if(abs(m-n)%2==0&&n>=m)
    {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}

int main(){
    int t,i;
    cin>>t;
    for(i-0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}