#include<iostream>
#include<cmath>
#include<string>
#include <algorithm>
#include<vector>
using namespace std;
int bin(char a){
    int aa;
    int ans=0;
    int n=1;
    int i;
    int b[8]={0};
    aa = (int)a;          //97
    for(i=7;i>=0;i--){
        b[i]+=(aa%2);
        aa/=2;
    }
    for(i=7;i>0;i--){
        ans+=(n*b[i]);
        n*=10;
    }
    return ans;
}
int bian(string a){
    int ans=0;
    int k;
    int m;
    int n;
    int flag=8;
    k=a.length();
    m=(k-1)*8;
    //cout<<m<<'\n';
    for(int i=0;a[i]!='\0';i++){
        n=bin(a[i]);
        do{
            flag--;
            //cout<<n<<'\n';
            ans+=(n%10*pow(2,m));
            m++;
            n/=10;
        }while(flag>0);
        flag=8;
        k--;
        m=(k-1)*8;
    }
   return ans;
}
int main(){
    string a;
    int c;
    cin>>a;
    c=bian(a);
    switch (c)
    {
    case 'abc':
        printf("1");
        break;
    
    default:
        printf("2");
        break;
    }
    return 0;
}