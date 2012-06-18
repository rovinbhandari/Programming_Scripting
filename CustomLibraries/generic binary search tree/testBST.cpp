#include <vector>
#include <iostream>
#include <BinarySearchTree.hpp>
using namespace std;

/*
template <class Any>
inline void printtraversal1(const vector<const Any&>& order)
{
	for(vector<const Any&>::const_iterator cit = order.begin(); cit != order.end(); cit++)
		cout<<*cit<<endl;
}
*/

int main(void)
{
	int n;
	int x;
	BinarySearchTree<int> bst;
	cin>>n;
	while(n--)
	{
		cin>>x;
		bst.insert(x);
		bst.printtraversalinorder();
	}
	//printtraversal1(bst.traversalinorder());
	bst.printtraversalinorder();

	return 0;
}

