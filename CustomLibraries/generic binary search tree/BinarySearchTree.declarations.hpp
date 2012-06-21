#ifndef BinarySearchTree_declarations_hpp
#define BinarySearchTree_declarations_hpp

#include <vector>
using namespace std;

//TODO: put const whereever needed to be enforced.

template <class Any>
class BinarySearchTree;

#include <BinaryNode.declarations.hpp>

enum REMOVEMETHOD
{
	LAZY,
	HARD
};

template <class Any>		//TODO: add Comparable for comparison of elements.
class BinarySearchTree
{
	public:
		//TODO:
		/*
		class const_iterator
		{

		};

		class iterator : public const_iterator
		{

		};
		*/

		BinarySearchTree();
		BinarySearchTree(const BinarySearchTree& rhs);
		const BinarySearchTree& operator=(const BinarySearchTree& rhs);
		~BinarySearchTree();

		bool isempty();
		bool isempty(BinaryNode<Any>* bn);
		void makeempty();
		void makeempty(BinaryNode<Any>* bn);

		BinaryNode<Any>* clone();
		BinaryNode<Any>* clone(BinaryNode<Any>* bn);

		void allowduplicates(bool t_f/* = true*/);

		const BinaryNode<Any>* insert(const Any& object);
		const BinaryNode<Any>* insert(BinaryNode<Any>*& helper, const Any& object);
		
		void remove(const Any& object, REMOVEMETHOD rm/* = LAZY*/);
		void remove(BinaryNode<Any>*& helper, const Any& object, REMOVEMETHOD rm/* = LAZY*/);
		
		const BinaryNode<Any>* find(const Any& object) const;
		const bool contains(const Any& object) const;
		const Any& findmin() const;
		const Any& findmin(BinaryNode<Any>* helper) const;
		BinaryNode<Any>*& findminbinarynode() const;
		BinaryNode<Any>*& findminbinarynode(BinaryNode<Any>*& helper) const;
		const Any& findmax() const;
		const Any& findmax(BinaryNode<Any>* helper) const;
		const BinaryNode<Any>* findmaxbinarynode() const;
		const BinaryNode<Any>* findmaxbinarynode(BinaryNode<Any>* helper) const;

		BinarySearchTree<Any>* subtree(BinaryNode<Any>* bn);
		
		//TODO: add overloaded functions for the following \
		four functions, to print a subtree.
		const vector<const Any&>& traversalinorder() const;
		void traversalinorder(BinaryNode<Any>* bn, vector<const Any&>& order);
		void printtraversalinorder();
		void printtraversalinorderduplicatesallowed(BinaryNode<Any>* bn);
		void printtraversalinorderduplicatesnotallowed(BinaryNode<Any>* bn);
		const vector<const Any&> traversalpreorder() const;
		const vector<const Any&> traversalpostorder() const;
		const vector<const vector<const Any&> > traversallevelorder() const;
		
		/*
		int getremovelazythreshold() const;
		void setremovelazythreshold(int value/ * = -11* /);
		*/

		Any& operator++();		// move to left child if exists.
		Any& operator++(int);	// move to right child if exists.
	
	private:
		void deletelazy(BinaryNode<Any>*& pBN);
		void deletehard(BinaryNode<Any>*& pBN);

	private:
		struct LevelInfo
		{
			vector<vector<Any&> > levelordering;
			vector<bool> recomputelevelordering;

			LevelInfo(vector<vector<Any&> > lo, vector<bool> rlo)
				: levelordering(lo),
				  recomputelevelordering(rlo)
			{
			}

		};

		BinaryNode<Any>* root;
		bool duplicatesallowed;
		int removelazythresholdduplicatesallowed;
		int removelazythresholdduplicatesnotallowed;
};

#include <BinarySearchTree.definitions.hpp>

#endif
