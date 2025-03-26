#include<bits/stdc++.h>
#define N 1000010
using namespace std;
string A,a;
int ne[N];//表示最长匹配前后缀长度，并且由于加了井号，所以该值也可以表示为下标
void getnext(string a){
    for(int i=2,j=0;i<a.size();i++){
        while (j&&a[i]!=a[j+1])
        {
            j=ne[j];
        }
        if(a[j+1]==a[i])
        j++;
        ne[i]=j;
    }
}
void KMP(string a,string A){
    getnext(a);
    for(int i=1,j=0;i<A.size();i++){
        while (j==a.size()-1||j&&A[i]!=a[j+1])
        {
            j=ne[j];
        }
        if(A[i]==a[j+1])
        j++;
        if(j==a.size()-1)
        cout<<i-j+1<<'\n';
        
    }
}
void solve(){
    cin>>A>>a;
    A='#'+A;
    a='#'+a;
    KMP(a,A);
    for(int i=1;i<a.size();i++){
        cout<<ne[i]<<" ";
    }
}
int main(){
    solve();
    return 0;
}