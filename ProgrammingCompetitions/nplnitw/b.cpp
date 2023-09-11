#include<iostream>
using namespace std;
class A{
public:
virtual void foo()
{
cout<<"In a";
}
};
class B
{
public:
void foo2()
{
cout<<"In b";
}
};
class C : public A, public B
{
void foo2()
{
cout<<"In c";
}
void foo()
{
cout<<"In c";
}
};
int main()
{
A* obj1 = new C;
B* obj2 = new C;
obj2->foo2();
obj1->foo();
}
