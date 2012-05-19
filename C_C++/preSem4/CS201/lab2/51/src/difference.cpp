
#include "../include/difference.h"

using std::string;

template <class T> Difference<T>::Difference(const T& fir=0,const T& sec=0)
{
	first=fir;
	second=sec;
}

template <class T> void Difference<T>::reset(const T& fir,const T& sec)
{
	first=fir;
	second=sec;
}


template <class T> int Difference<T>::distance ()
{
	return (first-second);
}



