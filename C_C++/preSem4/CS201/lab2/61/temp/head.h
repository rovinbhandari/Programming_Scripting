class Exforsys 
{ 
public: 
virtual void example()=0; //Denotes pure virtual Function Definition
}; 

class Exf1:public Exforsys 
{ 
public: 
void example();
}; 

class Exf2:public Exforsys 
{ 
public: 
void example(); 
}; 

