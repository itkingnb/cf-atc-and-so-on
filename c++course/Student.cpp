#include<bits/stdc++.h>
#include <unistd.h>
#define MAX_NAME_SIZE 100
using namespace std;
class grade {
    private:
    double OPP,Principles_of_Computer_Organization,Digital_Logic;
    public:
    grade():OPP(0),Principles_of_Computer_Organization(0),Digital_Logic(0){};
    ~grade();
    void init();
    double get_OPP();
    double get_Principles_of_Computer_Organization();
    double get_Digital_Logic();
};
grade::~grade(){}
void grade::init(){
    OPP=rand()%100;//正常应该是这样进行输入cin>>OPP>>Principles_of_Computer_Organization>>Digital_Logic;
    Principles_of_Computer_Organization=rand()%100;
    Digital_Logic=rand()%100;//这里为了方便采用随机数
}
double grade::get_OPP(){
    return OPP;
}
double grade::get_Principles_of_Computer_Organization(){
    return Principles_of_Computer_Organization;
}
double grade::get_Digital_Logic(){
    return Digital_Logic;
}
class Student{
    private:
    int ID;
    char* name;
    grade _grade;
    public:
    Student();
    ~Student();
    void init(int id,char*nstr);
    void grade_init();
    void show();
};
Student::Student(){}
Student::~Student(){
    delete name;
}
void Student::init(int id,char* nstr){
    ID=id;
    name=new char[strlen(nstr)+1];
    strcpy_s(name,strlen(nstr)+1,nstr);
}
void Student::grade_init(){
    _grade.init();
}   
void Student::show(){
    double OPP=_grade.get_OPP(),Principles_of_Computer_Organization=_grade.get_Principles_of_Computer_Organization(),Digital_Logic=_grade.get_Digital_Logic();
    double average=(OPP+Principles_of_Computer_Organization+Digital_Logic)/3.0;
    cout<<"这名学生的学号是："<<ID<<endl;
    cout<<"这名学生的名字是："<<name<<endl;
    cout<<"他的OPP成绩是: "<<OPP<<endl;
    cout<<"他的Principles_of_Computer_Organization成绩是: "<<Principles_of_Computer_Organization<<endl;
    cout<<"他的Digital_Logic成绩是: "<<Digital_Logic<<endl;
    cout<<"他三门课的平均分：是"<<fixed<<setprecision(2)<<average<<endl;
}
int main(){
    srand(time(0));
    int n;
    cout<<"请输入有几个学生"<<endl;
    cin>>n;
    Student* stu;
    stu=new Student[n];
    for(int i=0;i<n;i++){
        int id;char* name;
        name=new char[MAX_NAME_SIZE];
        cout<<"请输入学号"<<endl;
        cin>>id;
        cout<<"请输入姓名"<<endl;
        cin>>name;
        stu[i].init(id,name);
        cout<<"请输入他的三门课的成绩"<<endl;
        stu[i].grade_init();
        sleep(2);//模拟输入过程停留的时间因为这里输入成绩我用了随机数处理如果想输入把上面注释里的替换随机数即可
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        stu[i].show();
        cout<<endl;
    }
    delete[] stu;
}