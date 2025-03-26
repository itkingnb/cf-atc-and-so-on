#include<fstream>
using namespace std;
int main(){
    ofstream ofs;
    ofs.open("a.txt",ios::out);
    for(int i=200000;i>=1;i--)
        ofs<<i<<" ";
    ofs<<'\n';
    ofs.close();
    return 0;
}