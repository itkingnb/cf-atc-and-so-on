#include<iostream>
#include<string>
using namespace std;

void solve(){
    char a[200000];
    int i,b[27]={0},j=0,n;
    char c[27];
    cin>>n;
    cin>>a;
    for(i=0;a[i]!='\0';i++){
        b[a[i]-96]++;
    }
    for(i=1;i<27;i++){
        if(b[i]!=0){
        c[j]=i+96;
        j++;
        }
    }
    c[j+1]='\0';
    j--;
    for(i=0;a[i]!=0;i++){
        for(int k=0;k<=j;k++){
            if(a[i]==c[k]){
            a[i]=c[j-k];
            cout<<a[i];
            break;
            }
        }
        
    }
    cout<<'\n';

}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    solve();
    return 0;
}