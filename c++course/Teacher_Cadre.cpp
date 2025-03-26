#include<bits/stdc++.h>
using namespace std;
class Teacher{
    private:
    string name;int age;string sex,address,phone;string title;
    public:
    Teacher(string name1,int age1,string sex1,string address1,string phone1,string title1);
    void display();
};
Teacher::Teacher(string name1,int age1,string sex1,string address1,string phone1,string title1){
    name=name1;age=age1;sex=sex1;address=address1;phone=phone1;title=title1;
}
void Teacher::display(){
    cout<<"姓名："<<name<<endl;
    cout<<"年龄："<<age<<endl;
    cout<<"性别："<<sex<<endl;
    cout<<"地址："<<address<<endl;
    cout<<"电话："<<phone<<endl;
    cout<<"职称："<<title<<endl;
}
class Cadre{
    private:
    string name;int age;string sex,address,phone;string post;
    public:
    string getpost();
    Cadre(string name1,int age1,string sex1,string address1,string phone1,string post1);
};
string Cadre::getpost(){return post;};
Cadre::Cadre(string name1,int age1,string sex1,string address1,string phone1,string post1){
    name=name1;age=age1;sex=sex1;address=address1;phone=phone1;post=post1;
}
class Teacher_Cadre:public Teacher,public Cadre{
    private:
    double wage;
    public:
    void show();
    Teacher_Cadre(string name1,int age1,string sex1,string address1,string phone1,string title1,string post1,double wage1):Teacher(name1,age1,sex1,address1,phone1,title1),Cadre(name1,age1,sex1,address1,phone1,post1),wage(wage1){};
};
void Teacher_Cadre::show(){
    Teacher::display();
    cout<<"职务："<<Cadre::getpost()<<endl;
    cout<<"工资："<<wage<<endl;
}
int main(){
    Teacher_Cadre Tom("Tom",30,"male","abc","13812345678","professor","teacher",10000);
    Tom.show();
    return 0;
}