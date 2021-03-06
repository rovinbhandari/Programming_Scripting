#ifndef BinarySearchTree_definitions_hpp
#define BinarySearchTree_definitions_hpp

#include <BinaryNode.declarations.hpp>
#include <BinarySearchTree.declarations.hpp>

template <class Any>
BinarySearchTree<Any>::BinarySearchTree()
	: root(NULL),
	  duplicatesallowed(false),
	  removelazythresholdduplicatesallowed(-11),
	  removelazythresholdduplicatesnotallowed(-3)
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
	return !((bool) bn);
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
void BinarySearchTree<Any>::allowduplicates(bool t_f = true)
{
	ASSERT(isempty(), "BST not empty.");
	duplicatesallowed = t_f;
	
}

template<class Any>
const BinaryNode<Any>* BinarySearchTree<Any>::insert(const Any& object)
{
	return insert(root, object);
}

template<class Any>
const BinaryNode<Any>* BinarySearchTree<Any>::insert(BinaryNode<Any>*& helper, const Any& object)
{
	if(!helper)
	{
		helper = new BinaryNode<Any>(object, 1, NULL, NULL);
		return helper;
	}
	else
	{
		
		if(object < helper->element)
			return insert(helper->pleftchild, object);
		else if(helper->element < object)
			return insert(helper->prightchild, object);
		else if(duplicatesallowed)
		{
			helper->multiplicity++;
			return helper;
		}
		else
			return helper;
	}
}

template<class Any>
void BinarySearchTree<Any>::remove(const Any& object, REMOVEMETHOD rm = LAZY)
{
	remove(root, object, rm);
}

template<class Any>
void BinarySearchTree<Any>::remove(BinaryNode<Any>*& helper, const Any& object, REMOVEMETHOD rm = LAZY)
{
	if(!helper)
		return;
	else if(object < helper->element)
		remove(helper->pleftchild, object, rm);
	else if(helper->element < object)
		remove(helper->prightchild, object, rm);
	else if(duplicatesallowed
			&& rm == LAZY
			&& helper->multiplicity > removelazythresholdduplicatesallowed)
		deletelazy(helper);
	else if(duplicatesallowed
			&& rm == HARD
			&& helper->multiplicity > 1)
		deletelazy(helper);
	else if(!duplicatesallowed
			&& rm == LAZY
			&& helper->multiplicity > removelazythresholdduplicatesnotallowed)
		deletelazy(helper);
	else
		deletehard(helper);
}

template<class Any>
void BinarySearchTree<Any>::deletelazy(BinaryNode<Any>*& pBN)
{
	pBN->multiplicity--;
}

template<class Any>
void BinarySearchTree<Any>::deletehard(BinaryNode<Any>*& pBN)
{
	if(pBN->isfullnode())
	{
		BinaryNode<Any>*& temp = findminbinarynode(pBN->prightchild);
		pBN->element = temp->element;
		pBN->multiplicity = temp->multiplicity;
		deletehard(temp);
	}
	else
	{
		BinaryNode<Any>* temp = pBN;
		pBN = pBN->pleftchild ? pBN->pleftchild : pBN->prightchild;
		delete temp;
	}
}

template<class Any>
BinaryNode<Any>*& BinarySearchTree<Any>::findminbinarynode() const
{
	BinaryNode<Any>*& temp = root;
	return findminbinarynode(temp);
}

template<class Any>
BinaryNode<Any>*& BinarySearchTree<Any>::findminbinarynode(BinaryNode<Any>*& helper) const
{
	ASSERT(helper, "Node not found.");
	if(!helper->pleftchild)
		return helper;
	else
		return findminbinarynode(helper->pleftchild);
}

/*
template<class Any>
int BinarySearchTree<Any>::getremovelazythreshold() const
{
	return removelazythreshold;
}

template<class Any>
void BinarySearchTree<Any>::setremovelazythreshold(int value = -11)
{
	if(value > 0)
		return;		//TODO: throw ValueTooBigException
	else
		removelazythreshold = value;
}
*/

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
	if(duplicatesallowed)
		printtraversalinorderduplicatesallowed(root);
	else
		printtraversalinorderduplicatesnotallowed(root);
}

template<class Any>
void BinarySearchTree<Any>::printtraversalinorderduplicatesallowed(BinaryNode<Any>* bn)
{
	if(!bn)
		return;
	printtraversalinorderduplicatesallowed(bn->pleftchild);
	if(bn->multiplicity > 0)
		cout<<"\t"<<bn->element<<"\tx\t"<<bn->multiplicity<<endl;
	printtraversalinorderduplicatesallowed(bn->prightchild);
}

template<class Any>
void BinarySearchTree<Any>::printtraversalinorderduplicatesnotallowed(BinaryNode<Any>* bn)
{
	if(!bn)
		return;
	printtraversalinorderduplicatesnotallowed(bn->pleftchild);
	cout<<"\t"<<bn->element<<endl;
	printtraversalinorderduplicatesnotallowed(bn->prightchild);
}

#endif
