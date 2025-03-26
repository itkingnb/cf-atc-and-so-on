#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
#define ll long long
using namespace std;
int jc(int n){
    if(n==1||n==0)
    return 1;
    else
    return n*jc(n-1);
}
void yes(){
    cout<<"Yes";
}
void no(){
    cout<<"No";
}
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
void solve(){
    int m,n;
    int flag=0;
    string a[510];
    string b[510];
    cin>>m>>n;
    int diff=0;
    for(int i=0;i<m;i++)
    cin>>a[i];
    for(int i=0;i<m;i++)
    cin>>b[i];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            flag=0;
        if(j==n-1||i==m-1||diff>0){
            if(diff){
                no();
                return;
            }
            if(a[i][j]!=b[i][j]){
            no();
            return;
            }
        }
        else{
            if(a[i][j]!=b[i][j]){
                diff++;
                for(int x=m-1;x>i;x--){
                    if(flag==1)
                    break;
                    for(int y=n-1;y>j;y--){
                        if(a[x][y]!=b[x][y]){
                            if((a[i][j]=='0'&&b[i][j]=='2')||(a[i][j]=='1'&&b[i][j]=='0')||(a[i][j]=='2'&&b[i][j]=='1')){
                            a[i][j]=(((int)a[i][j]-48)+2)%3+48;
                            a[x][y]=(((int)a[x][y]-48)+2)%3+48;
                            a[x][j]=(((int)a[x][j]-48)+1)%3+48;
                            a[i][y]=(((int)a[i][y]-48)+1)%3+48;
                            flag=1;
                            diff=0;
                        }
                        else{
                            a[i][j]=(((int)a[i][j]-48)+1)%3+48;
                            a[x][y]=(((int)a[x][y]-48)+1)%3+48;
                            a[x][j]=(((int)a[x][j]-48)+2)%3+48;
                            a[i][y]=(((int)a[i][y]-48)+2)%3+48;
                            flag=1;
                            diff=0;
                            }
                            if(flag==1)
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    yes();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve();
        cout<<'\n';
    }
    return 0;
}