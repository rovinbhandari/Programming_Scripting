class node
{
	private :
		int i;
		float c;
		node * n;
	public :
		node();
		node * ret_list(int, bool);
		void output();
		int degree_of();
		node * add(node *);
		node * multiply();
};
