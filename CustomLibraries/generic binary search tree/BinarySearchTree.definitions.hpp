#ifndef BinarySearchTree_definitions_hpp
#define BinarySearchTree_definitions_hpp

#include <vector>
#include <iostream>
#include <BinaryNode.declarations.hpp>
#include <BinarySearchTree.declarations.hpp>
using namespace std;

template <class Any>
BinarySearchTree<Any>::BinarySearchTree()
	: root(NULL),
	  duplicatesallowed(false)
{
}

template <class Any>
const BinarySearchTree<Any>& BinarySearchTree<Any>::operator=(const BinarySearchTree& rhs)
{
	if(this != rhs)
	{
		makeempty();
		root = clone(rhs.root);
	}
}

template <class Any>
BinarySearchTree<Any>::~BinarySearchTree()
{
	makeempty();
}

template <class Any>
bool BinarySearchTree<Any>::isempty()
{
	return isempty(root);
}

template <class Any>
bool BinarySearchTree<Any>::isempty(BinaryNode<Any>* bn)
{
	return (bool) bn;
}

template <class Any>
void BinarySearchTree<Any>::makeempty()
{
	makeempty(root);
}

template <class Any>
void BinarySearchTree<Any>::makeempty(BinaryNode<Any>* bn)
{
	if(bn)
	{
		makeempty(bn->pleftchild);
		makeempty(bn->prightchild);
		delete bn;
	}
	bn = NULL;
}

template <class Any>
BinaryNode<Any>* BinarySearchTree<Any>::clone()
{
	return clone(root);
}

template <class Any>
BinaryNode<Any>* BinarySearchTree<Any>::clone(BinaryNode<Any>* bn)
{
	if(bn)
		return new BinaryNode<Any>(bn->element, clone(bn->pleftchild), clone(bn->prightchild));
	return NULL;
}

template <class Any>
void BinarySearchTree<Any>::allowduplicates(bool t_f)
{
	if(isempty())
		duplicatesallowed = t_f;
	else
		;	// throw BSTnotemptyException;	//TODO
}

template<class Any>
const BinaryNode<Any>* BinarySearchTree<Any>::insert(const Any& object)
{
	return insert(root, object);
}

template<class Any>
const BinaryNode<Any>* BinarySearchTree<Any>::insert(BinaryNode<Any>* helper, const Any& object)
{
	if(!root)	// root is NULL
	{
		root = new BinaryNode<Any>(&object, 1, NULL, NULL);
		return root;
	}
	else if(helper)		// root is not NULL; helper is not NULL
	{
		
		if(object < *helper->element)
			return insert(helper->pleftchild, object);
		else if(object == *helper->element)
		{
			if(duplicatesallowed)
				helper->multiplicity++;
			return helper;
		}
		else
			return insert(helper->prightchild, object);
	}
	else	// root is not NULL; helper is NULL
		return new BinaryNode<Any>(&object, 1, NULL, NULL);
}

template<class Any>
const vector<const Any&>& BinarySearchTree<Any>::traversalinorder() const
{
	vector<const Any&> order;
	traversalinorder(root, order);
	return order;
}

template<class Any>
void BinarySearchTree<Any>::traversalinorder(BinaryNode<Any>* bn, vector<const Any&>& order)
{
	if(!bn)
		return;
	traversalinorder(bn->pleftchild, order);
	order.push_back(bn->element);
	traversalinorder(bn->prightchild, order);
}

template<class Any>
void BinarySearchTree<Any>::printtraversalinorder()
{
	printtraversalinorder(root);
}

template<class Any>
void BinarySearchTree<Any>::printtraversalinorder(BinaryNode<Any>* bn)
{
	if(!bn)
		return;
	printtraversalinorder(bn->pleftchild);
	cout<<"\t"<<*bn->element<<endl;
	printtraversalinorder(bn->prightchild);
}

#endif

