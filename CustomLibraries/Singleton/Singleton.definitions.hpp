#ifndef Singleton_definitions_hpp
#define Singleton_definitions_hpp

#include <Singleton.declarations.hpp>

template<class Any>
Singleton<Any>* Singleton<Any>::pSingleton = NULL;

template<class Any>
Singleton<Any>::Singleton()
	: data(NULL)
{
}

template<class Any>
Singleton<Any>::Singleton(Any d)
	: data(d)
{
}

template<class Any>
Singleton<Any>* Singleton<Any>::new_Singleton(Any d = (Any) NULL)
{
	if(!Singleton<Any>::pSingleton)
		Singleton<Any>::pSingleton = new Singleton(d);
	return Singleton<Any>::pSingleton;
}

template<class Any>
void Singleton<Any>::output()
{
	cout<<endl<<"object at: "<<(void*) this
		<<endl<<"\tref:  "<<Singleton<Any>::pSingleton
		<<endl<<"\tdata: "<<data<<endl
		<<endl;
}

#endif
