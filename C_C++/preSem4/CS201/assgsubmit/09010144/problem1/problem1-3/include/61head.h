class xyz
{
	public :
		float x, y, z;
		xyz();
		xyz * input(int);
};

class shape
{
	public :
		virtual float area(xyz []) = 0;
};

class line : public shape
{
	public :
		float area(xyz *);
};

class triangle : public shape
{
	public :
		float area(xyz []);
};

class rectangle : public shape
{
	public :
		float area(xyz []);
};

