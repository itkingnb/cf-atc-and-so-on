#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    while(1){
        srand(time(0));
    cout<<"10"<<'\n';
    for(int i=0;i<10;i++){
    int n=rand()%3+98;
    cout<<n<<'\n';
    vector<bool>a(n);
    int cnt=0;
    while(cnt<n){
        int m=rand()%n+1;
        if(!a[m])
        cout<<m<<" ",cnt++,a[m]=true;
    }
    cout<<'\n';
    cnt=0;
    vector<bool>b(n);
    while(cnt<n){
        int m=rand()%n+1;
        if(!b[m])
        cout<<m<<" ",cnt++,b[m]=true;
    }
    cout<<'\n';
    }
    system("pause");   
    }
    
    return 0;
}