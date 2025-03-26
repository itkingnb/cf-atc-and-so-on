#include<bits/stdc++.h>
using namespace std;
int main(){
    ofstream os;
    os.open("data.in",ios::out);
    os<<2000<<endl;
    int now=999990000;
    for(int i=0;i<2000;i++){
        os<<now--<<endl;
    }
    cout<<now;
    os.close();
}