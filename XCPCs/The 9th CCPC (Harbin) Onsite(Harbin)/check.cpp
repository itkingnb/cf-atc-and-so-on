#include<bits/stdc++.h>
using namespace std;
void check(){
    int n;
    cin>>n;
    vector<int>a(n*10000),b(n*10000);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    string op;
    cin>>op;
    int i,j,t=0;
    for(i=0,j=0;i<op.size();i++){
        while(a[j]==0)
        {
            j++;
        }
        if(op[i]=='1'){
            a[n+t]=a[j];
            a[j]=0;
            t++;
        }
        else{
            a[n+t]=a[j+1];
            a[j+1]=0;
            t++;
        }
    }
    int m=0;
    for(t-n,m;m<n;m++,t++){
        if(a[t]!=b[m]){
            cout<<"WA"<<'\n';
            system("pause");
            return ;
        }
    }
    cout<<"AC"<<'\n';
}
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    while(1){
    int t;
    cin>>t;
    while(t--){
        check();
    }  
    }

}