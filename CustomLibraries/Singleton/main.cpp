#include <Singleton.hpp>

int main(void)
{
	Singleton<bool>* s1 = Singleton<bool>::new_Singleton();
	s1->output();
	s1 = Singleton<bool>::new_Singleton(true);
	s1->output();
	
	Singleton<int>* s2 = Singleton<int>::new_Singleton(5);
	s2->output();
	s2 = Singleton<int>::new_Singleton();
	s2->output();
	s2 = Singleton<int>::new_Singleton(55);
	s2->output();

	return 0;
}
