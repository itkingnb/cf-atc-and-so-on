#include<bits/stdc++.h>
using namespace std;


int a[4][10];
int b[8];
void solve()
{
    string s;cin>>s;
    int num=0;
    bool f=1;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=9;j++){
            a[i][j]=0;
        }
    }
    for(int i=1;i<=7;i++)b[i]=0;
    for(int i=0;i<14;i++){
        if(s[i*2+1]=='z'){
            b[s[i*2]-'0']++;
            if(b[s[i*2]-'0']==2)num++;
        }
        else if(s[i*2+1]=='p'){
            a[1][s[i*2]-'0']++;
            if(a[1][s[i*2]-'0']==2)num++;
        }
        else if(s[i*2+1]=='s'){
            a[2][s[i*2]-'0']++;
            if(a[2][s[i*2]-'0']==2)num++;
        }
        else{
            a[3][s[i*2]-'0']++;
            if(a[3][s[i*2]-'0']==2)num++;
        }
    }
    for(int i=1;i<=3;i++){
        if(a[i][1]==0||a[i][9]==0)f=0;
    }
    for(int i=1;i<=7;i++){
        if(b[i]==0)f=0;
    }
    // cout<<num<<'\n';
    if(num==7){
        cout<<"7 Pairs"<<'\n';
    }
    else if(f==1){
        cout<<"Thirteen Orphans"<<'\n';
    }
    else cout<<"Otherwise"<<'\n';

}
int main()
{
    ios::sync_with_stdio();cin.tie(0);cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
// 6
// 1s9s1p9p1m9m1z2z3z4z5z6z7z9s
// 1s9s1p9p1s9s1p9p2s2p2s2p3s3s
// 1s1s1s2s3s4s5s6s7s8s9s9s9s5s
// 9s1p1s1m1z7z6z5z4z9p9m2z3z2z
// 1p2p3p1p2p3p7s8s9s7s8s9s1z1z
// 1p1p1p1p2p2p2p2p3p3p3p3p4p4p