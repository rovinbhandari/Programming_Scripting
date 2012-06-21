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
	//bst.allowduplicates();
	cin>>N;
	
	cout<<"Insertions:"<<endl;
	n = N;
	while(n--)
	{
		cin>>x;
		bst.insert(x);
		bst.printtraversalinorder();
		cout<<"\t---"<<endl;
	}

	cout<<"\t---"<<endl;
	cout<<"\t---"<<endl;

	//ASSERT(false, "GG!");

	cout<<"Deletions:"<<endl;
	n = N;
	while(n--)
	{
		cin>>x;
		bst.remove(x, HARD);
		bst.printtraversalinorder();
		cout<<"\t---"<<endl;
	}
	//printtraversal1(bst.traversalinorder());
	//bst.printtraversalinorder();

	return 0;
}
