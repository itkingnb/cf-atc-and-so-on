/*
#include<iostream>
using namespace std;
class CRoot{
public:
	int small;
	CRoot(int n=2){small=n;}
	void showsmall(){
		cout<<"small="<<small<<endl;	
	}
};
class CDer1:public CRoot
{
public:	
	CDer1(int m):CRoot(m){}
};
class CDer2:public CRoot{
public:
	int small;	
	CDer2(int n=0){small=n;}
};
int main(){
	CRoot A;
	CDer1 B(3);
	CDer2 C;
	A.showsmall();
	B.showsmall();
	C.showsmall();
	return 0;
}
*/
/*
结果：
small=2
small=3
small=2
这个代码定义了一个CRoot的基类，构造函数包含使其成员初始化为2，并有一个函数输出其成员small的值
两个由CRoot继承出来的派生类CDer1，CDer2，其中CDer2也有个成员small构造函数赋值的是他自己的small；
CDer1构造函数中调用基类的构造函数
A展示的是基类的small B展示的是派生类继承基类后基类的成员small C构造函数给派生类的成员赋初值0 但是调用的是基类的函数所以显示基类的small值
*/
#include<bits/stdc++.h>
using namespace std;
class CPerson{
private:
    string name;int id;string sex;
public:
    void inputname(){cin>>name;};
    void inputid(){cin>>id;};
    void inputsex(){cin>>sex;};
    string getname(){return name;};
    int getid(){return id;};
    string getsex(){return sex;};
};
class CStudent:public CPerson{
private:
    int grade;
public:
    void inputgrade(){cin>>grade;};
    int getgrade(){return grade;};
    void input(){inputname();inputid();inputsex();inputgrade();};
    void print(){cout<<"学生姓名："<<getname()<<" 编号："<<getid()<<" 性别："<<getsex()<<" 成绩："<<getgrade()<<endl;};
};
class CTeacher:public CPerson{
private:
    int teach_year;
public:
    void inputteach_year(){cin>>teach_year;};
    int getteach_year(){return teach_year;};
    void input(){inputname();inputid();inputsex();inputteach_year();};
    void print(){cout<<"老师姓名："<<getname()<<" 编号："<<getid()<<" 性别："<<getsex()<<" 教龄："<<getteach_year()<<endl;};
};
int main(){
    int n,m;
    cout<<"几个学生，几个老师？"<<endl;
    cin>>n>>m;
    vector<CStudent>stu(n);vector<CTeacher>teacher(m);
    cout<<"请分别输入学生的姓名，编号，性别，成绩"<<endl;
    for(int i=0;i<n;i++){
        stu[i].input();
    }
    cout<<"请分别输入老师的姓名，编号，性别，教龄"<<endl;
    for(int i=0;i<m;i++){
        teacher[i].input();
    }
    cout<<"学生信息："<<endl;
    for(int i=0;i<n;i++){
        stu[i].print();
    }
    cout<<"老师信息："<<endl;
    for(int i=0;i<m;i++){
        teacher[i].print();
    }
    return 0;
}
/*
2 3
Alice 1 female 90
Bob 2 male 100
Tom 1 male 10
Peter 2 male 15
Lucy 3 female 20
*/