#include<bits/stdc++.h>
using namespace std;
int main(){
    ofstream ofs;
    ofs.open("test.txt",ios::out);
    ofs<<1<<'\n';
    ofs<<200000<<" "<<100000<<'\n';
    for(int i=1;i<=100000;i++)
    ofs<<1<<" ";
    ofs<<'\n';
    for(int i=1;i<=100000;i++)
    ofs<<i<<" ";
    ofs.close();
}