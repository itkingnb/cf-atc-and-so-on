#include<bits/stdc++.h>
using namespace std;
class CStudent{
    public:
    void STC(float s){
        score=s;
        total+=s;
        ++count;
    }
    static float Sum(){
        return total;
    }
    static float Average(){
        return total/count;
    }
    private:
    float score=0;
    static float total;
    static int count;
};
float CStudent::total=0;
int CStudent::count=0;
int main(){
    int n;
    cout<<"有几位学生"<<'\n';
    cin>>n;
    CStudent stu;
    cout<<"请输入他们的成绩"<<'\n';
    for(int i=0;i<n;i++){
        float s;
        cin>>s;
        stu.STC(s);
    }
    cout<<"总分是："<<stu.Sum()<<'\n';
    cout<<fixed<<setprecision(2)<<"平均分是："<<stu.Average()<<'\n';
    return 0;
}