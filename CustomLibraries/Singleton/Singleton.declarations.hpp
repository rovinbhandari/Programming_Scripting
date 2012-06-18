#ifndef Singleton_declarations_hpp
#define Singleton_declarations_hpp

#include <iostream>
using namespace std;

template<class Any>
class Singleton
{
	private:
		Any data;
		static Singleton* pSingleton;
		Singleton();
		Singleton(Any d);

	public:
		static Singleton* new_Singleton(Any d /*= (Any) NULL*/);

		void output();
		// other public methods to interact with data.
};

#include <Singleton.definitions.hpp>

#endif
