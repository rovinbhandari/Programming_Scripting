#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <iostream>
#include <cstdlib>
using namespace std;

#define ASSERT(COND, MSG)	\
		do	\
		{	\
			if(!(COND))	\
			{	\
				cerr		<< "Assertion `" #COND "` failed"		\
							<< endl		\
							<< "in file `" << __FILE__ << "`"	\
							<< endl		\
							<< "at line `" << __LINE__ << "`"	\
							<< endl		\
							<< "Error Message: " << MSG		\
							<< endl;	\
				exit(-1);	\
			}	\
		}	\
		while(false)

#include <BinarySearchTree.declarations.hpp>

#endif
