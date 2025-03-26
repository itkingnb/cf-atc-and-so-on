#include<bits/stdc++.h>
using namespace std;
class Integer{
public:
    Integer(int);
    Integer(const Integer&);
    Integer& operator+(Integer);
    Integer& operator+=(int);
    Integer& operator++();
    Integer operator++(int);
    friend ostream& operator<<(ostream&,Integer);
private:
    int value;
};
Integer::Integer(int i){
    value=i;
}
Integer::Integer(const Integer& a){
    value=a.value;
}
Integer& Integer::operator+(Integer a){
    value+=a.value;
    return *this;
}
Integer& Integer::operator+=(int a){
    value+=a;
    return *this;
}
Integer& Integer::operator++(){
    value++;
    return *this;
}
Integer Integer::operator++(int){
    Integer temp=this->value;
    value++;
    return temp;
}
ostream& operator<<(ostream& cout,Integer a){
    cout<<a.value;
    return cout;
}
int main()
{
    Integer i1(10);
    Integer i2 = 24;
    Integer i3(0);
    cout << ++i1 << endl;
    cout << i2++ << endl;
    i3 = i1 + i2;
    cout << i3 << endl;
    i3 += 10;
    cout << i3 << endl;
    return 0;
}