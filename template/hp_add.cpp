#include<bits/stdc++.h>
using namespace std;
#define ll long long
string hp_add(string a,string b){
    string ans;
    int flag=0;
    while (a.size()&&b.size())
    {
        int i=a.size()-1;
        int j=b.size()-1;
        int add=(b[j]-'0')+(a[i]-'0')+flag;
        if(add>=10){
            flag=1;
            add-=10;
            char aa='0'+add;
            ans=aa+ans;
        }
        else{
            flag=0;
            char aa='0'+add;
            ans=aa+ans;
        }
        a.pop_back();
        b.pop_back();
    }
    while(a.size()){
        int i=a.size()-1;
        int add=(a[i]-'0')+flag;
        if(add>=10){
            flag=1;
            add-=10;
            char aa='0'+add;
            ans=aa+ans;
        }
        else{
            flag=0;
            char aa='0'+add;
            ans=aa+ans;
        }
        a.pop_back();        
    }
    while (b.size())
    {
        int j=b.size()-1;
        int add=(b[j]-'0')+flag;
        if(add>=10){
            flag=1;
            add-=10;
            char aa='0'+add;
            ans=aa+ans;
        }
        else{
            flag=0;
            char aa='0'+add;
            ans=aa+ans;
        }
        b.pop_back();
    }
    
    if(flag){
        ans='1'+ans;
    }
    return ans;
}
int main(){
    string a;
    string b;
    cin>>a>>b;
    cout<<hp_add(a,b);
}