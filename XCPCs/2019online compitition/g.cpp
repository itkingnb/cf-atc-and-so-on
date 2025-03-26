#include<bits/stdc++.h>
using namespace std;
#define ll long long
char tu[1030][1030];
void pr(int k){
    if(k==1){
        tu[0][0]=tu[0][1]=tu[1][1]='C';
        tu[1][0]='P';
    }
    if(k>1){
        k--;
        pr(k);
        for(int i=0;i<pow(2,k);i++){
            for(int j=pow(2,k);j<pow(2,k+1);j++){
                tu[i][j]=tu[i][j-(int)pow(2,k)];
            }
        }
        for(int i=pow(2,k);i<pow(2,k+1);i++){
            for(int j=0;j<pow(2,k+1);j++){
                tu[i][j]=tu[i-(int)pow(2,k)][j];
                if(j<pow(2,k)&&tu[i][j]=='C'){
                tu[i][j]='P';
                continue;                    
                }
                if(j<pow(2,k)&&tu[i][j]=='P')
                tu[i][j]='C';
            }
        }
    }
}
void solve(){
    int k;
    cin>>k;
    pr(k);
    for(int i=0;i<pow(2,k);i++){
        for(int j=0;j<pow(2,k);j++){
            cout<<tu[i][j];
        }
        cout<<'\n';
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
    solve(); 
    }
    return 0;
}