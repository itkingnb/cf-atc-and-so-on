#include<iostream>
#include <cmath>
#include<string>
using namespace std;

int solve(){
    int n,p=0,q=0;
    char a[200000];
    char b[4]={0};
    int c[4]={1,1,1,1};
    cin>>n>>a;
    if(n%2==1){
        cout<<"NO"<<'\n';
        return 0;
    }
    for(int i=0;i<=n;i++){
        if(a[i]=='N'){
            b[0]++;
        }else{
            if(a[i]=='S'){
                b[1]++;
            }
            else{
                if(a[i]=='W'){
                    b[2]++;
                }
                else{
                if(a[i]=='E')
                    b[3]++;
                }
            }
        }
    }
    if(abs(b[0]-b[1])%2!=0||abs(b[2]-b[3])%2!=0){
        cout<<"NO"<<'\n';
        return 0;
    }
    if(b[0]==1&&b[1]==1){
        if(n==2){
        cout<<"NO"<<'\n';
        return 0;
        }
    }
    if(b[2]==1&&b[3]==1){
        if(n==2){
        cout<<"NO"<<'\n';
        return 0;
        }
    }
    for(int i=0;i<=n;i++){
        if(a[i]=='N')
        if(c[0]==1){
            cout<<'R';
            c[0]=-c[0];
            continue;
        }else{
            cout<<'H';
            c[0]=-c[0];
            continue;
        }
        if(a[i]=='S')
        if(c[1]==1){
            cout<<'R';
            c[1]=-c[1];
            continue;
        }else{
            cout<<'H';
            c[1]=-c[1];
            continue;
        }
        if(a[i]=='W')
        if(c[2]==1){
            cout<<'H';
            c[2]=-c[2];
            continue;
        }else{
            cout<<'R';
            c[2]=-c[2];
            continue;
        }
        if(a[i]=='E')
        if(c[3]==1){
            cout<<'H';
            c[3]=-c[3];
            continue;
        }else{
            cout<<'R';
            c[3]=-c[3];
            continue;
        }
        cout<<'\n';
    }
    return 0;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    solve();
    return 0;
}