#include<bits/stdc++.h>
using namespace std;
#define N 10001
char s[2*N];
int n;
int min_string(char *s){
    for(int i=0;i<n;i++)
    s[n+i]=s[i];
    int i=0,j=1;
    while (i<n&&j<n)
    {
        int k=0;
        for(k=0;k<n&&s[i+k]==s[j+k];k++);
        s[i+k]>s[j+k]?i+=k+1:j+=k+1;
        if(i==j) j++;
    }
    return min(i,j);
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    int m=min_string(s);
    for(int i=m;i<m+n;i++){
        cout<<s[i];
    }
}
int main(){
    solve();
    return 0;
}