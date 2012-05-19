#include "head.h"
#include <iostream>
using namespace std;

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

