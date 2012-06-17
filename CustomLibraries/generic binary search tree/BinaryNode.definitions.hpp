#ifndef BinaryNode_definitions_hpp
#define BinaryNode_definitions_hpp

#include <BinaryNode.declarations.hpp>

template <class Any>
BinaryNode<Any>::BinaryNode(const Any* object, int X, BinaryNode* pl, BinaryNode* pr)
	: element(object),
	  multiplicity(X),
	  pleftchild(pl),
	  prightchild(pr)
{
}

#endif

