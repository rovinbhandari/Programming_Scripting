#include<iostream>
using namespace std;

class Exforsys 
{ 
public: 
virtual void example()=0; //Denotes pure virtual Function Definition
}; 

class Exf1:public Exforsys 
{ 
public: 
void example() 
{ 
cout<<"\n\nWelcome "; 
} 
}; 

class Exf2:public Exforsys 
{ 
public: 
void example() 
{ 
cout<<"To Training\n\n"; 
} 
}; 

int main() 
{ 
Exforsys* arra[2]; 
Exf1 e1; 
Exf2 e2; 
arra[0]=&e1; 
arra[1]=&e2; 
arra[0]->example(); 
arra[1]->example(); 
return 0;
}

