#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b;
int z[20000010],p[20000010];
void get_z(string b){
    z[1]=b.size()-1;
    for(int i=2,l=0,r=0;i<b.size();i++){
        if(i<=r) z[i]=min(r-i+1,z[i-l+1]);
        while(b[1+z[i]]==b[i+z[i]]) z[i]++;
        if(i+z[i]-1>r) l=i,r=i+z[i]-1;
    }
}
void get_p(string b,string a){          //b为主字符串，a为要被匹配的字符串
    for(int i=1,l=0,r=0;i<=a.size();i++){
        if(i<=r)p[i]=min(z[i-l+1],r-i+1);
        while(1+p[i]<b.size()&&a[i+p[i]]==b[1+p[i]]&&i+p[i]<a.size())
        p[i]++;
        if(i+p[i]-1>r) l=i,r=i+p[i]-1;
    }
}
void solve(){
    cin>>a>>b;
    a='#'+a;
    b="#"+b;
    get_z(b);
    get_p(b,a);
    int ans=z[1]+1;
    for(int i=2;i<b.size();i++){
        int m=i*(z[i]+1);
        ans^=m;
    }
    cout<<ans<<'\n';
    ans=p[1]+1;
    for(int i=2;i<a.size();i++){
        int m=i*(p[i]+1);
        ans^=m;
    }
    cout<<ans;
}
signed main(){
    solve();
    system("pause");
    return 0;
}