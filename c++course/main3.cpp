#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s(100,' ');
    bool flag=true;
    stack<string>st;
    //cout<<'\n';
    while (cin>>s)
    {
        if(s=="#")
        break;
        else{
            for(int i=0;i<s.size();i++){    
                if(s[i]=='/'){
                    if(s[i+1]=='/'){
                        break;
                    }else if(s[i+1]=='*'){
                        st.push("/*");
                        flag=false;
                    }
                }
                if(flag){
                    cout<<s[i];
                }
                if(s[i]=='*'){
                    if(s[i+1]=='/'){
                        flag=true;
                        st.pop();
                        i++;
                    }
                }
            }
        }
        if(flag&&s[s.size()-1]==';')
        cout<<'\n';
        else if(flag){
            cout<<" ";
        }
    }
}