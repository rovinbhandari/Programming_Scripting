#ifndef BinaryNode_declarations_hpp
#define BinaryNode_declarations_hpp

template <class Any>
class BinaryNode
{
	protected:
		Any element;
		int multiplicity;

		BinaryNode* pleftchild;
		BinaryNode* prightchild;
		
		BinaryNode(const Any object, int X, BinaryNode* pl, BinaryNode* pr);
		bool isleafnode();
		bool isfullnode();
	friend class BinarySearchTree<Any>;
};

#include <BinaryNode.definitions.hpp>

#endif
