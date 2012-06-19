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
	int n, N;
	int x;
	BinarySearchTree<int> bst;
	bst.allowduplicates();
	cin>>N;
	n = N;
	while(n--)
	{
		cin>>x;
		bst.insert(x);
		bst.printtraversalinorder();
	}
	n = N;
	while(n--)
	{
		cin>>x;
		bst.removehard(x);
		bst.printtraversalinorder();
	}
	//printtraversal1(bst.traversalinorder());
	//bst.printtraversalinorder();

	return 0;
}
