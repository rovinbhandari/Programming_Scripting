#include <iostream>
#include "difference.cpp"

template class Difference<int>;
template class Difference<string>;
template class Difference<float>;
template class Difference<char>;

int main()
{
	std::cout<<"Please enter the choice" <<std::endl;
	std::cout<<"Test with : \n 1. Strings\n 2. Integer \n 3. Float\n 4. Character"<<std::endl;
	
	int choice;
	std::cin>>choice;
	int a,b;
	char c,d;
	string e,f;
	float g,h;
	
	Difference<int> diff_int;
	Difference<char> diff_char;
	Difference<string> diff_str;
	Difference<float> diff_float;
	
	switch(choice)
	{
		case 2: 
			
			std::cout<<"Enter the two values\n";
			std::cin>>a>>b;
			diff_int.reset(a,b);
			std::cout<<"Distance is "<<diff_int.distance()<<std::endl;
			break;
			
		case 4: 
			
			std::cout<<"Enter the two values\n";
			std::cin>>c>>d;
			diff_char.reset(c,d);
			std::cout<<"Distance is "<<diff_char.distance()<<std::endl;
			break;
			
		case 1: 
			
			std::cout<<"Enter the two values\n";
			std::cin>>e>>f;
			diff_str.reset(e,f);
			std::cout<<"Distance is "<<diff_str.distance()<<std::endl;
			break;
			
		case 3: 
			
			std::cout<<"Enter the two values\n";
			std::cin>>g>>h;
			diff_float.reset(g,h);
			std::cout<<"Distance is "<<diff_float.distance()<<std::endl;
			break;
		default:
			std::cout<<"Invalid Choice";
			break;
	}
	
	
	return 0; 
}


