#include <iostream>
#include <set>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

struct Point
{
	int x, y;
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	void print()
	{
		#ifdef DBG
		printf("(%d, %d) ", x, y);
		#endif
		return;
	}
};

struct Triangle
{
	Point a, b, c;
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
	{
		a = Point(x1, y1);
		b = Point(x2, y2);
		c = Point(x3, y3);
	}
	
	bool isInTriangle(Point p)
	{
		return false;
	}

	void print()
	{
		#ifdef DBG
		printf("Triangle: ");
		a.print();
		b.print();
		c.print();
		printf("\n");
		#endif
		return;
	}
};

struct Square
{
	Point a;
	int l;
	Square(int x, int y, int _l)
	{
		a = Point(x, y);
		l = _l;
	}

	bool isInSquare(Point p)
	{
		return false;
	}

	void print()
	{
		#ifdef DBG
		printf("Square: ");
		a.print();
		printf("%d\n", l);
		#endif
		return;
	}
};

struct Circle
{
	Point c;
	int r;
	Circle(int x, int y, int _r)
	{
		c = Point(x, y);
		r = _r;
	}

	bool isInCircle(Point p)
	{
		return false;
	}

	void print()
	{
		#ifdef DBG
		printf("Circle: ");
		c.print();
		printf("%d\n", r);
		#endif
		return;
	}
};

int main(void)
{
	int t, n;
	scanf("%d", &t);
	char c;
	int q1, q2, q3, q4, q5, q6;
	while(t--)
	{
		vector<Triangle> vt;
		vector<Square> vs;
		vector<Circle> vc;
		scanf("%d", &n);
		//cerr << "err1\tn = " << n << endl;
		while(n--)
		{
			while((c = getchar()) == '\n');
			//cerr << "err11\t c = " << (c - 0) << endl;
			switch(c)
			{
				case 'T':
					//cerr << "err2" << endl;
					scanf("%d %d %d %d %d %d", 
							&q1, &q2, &q3, &q4, &q5, &q6);
					//cerr << "err3" << endl;
					vt.push_back(Triangle(q1, q2, q3, q4, q5, q6));
					//cerr << "err4" << endl;
					break;
				case 'C':
					//cerr << "err5" << endl;
					scanf("%d %d %d", &q1, &q2, &q3);
					//cerr << "err6" << endl;
					vc.push_back(Circle(q1, q2, q3));
					//cerr << "err7" << endl;
					break;
				case 'S':
					//cerr << "err8" << endl;
					scanf("%d %d %d", &q1, &q2, &q3);
					//cerr << "err9" << endl;
					vs.push_back(Square(q1, q2, q3));
					//cerr << "err10" << endl;
					break;
				default:
					break;
			}
		}
		#ifdef DBG
		printf("\n%d %d %d\n", vt.size(), vc.size(), vs.size());
		for(q1 = 0; q1 < vt.size(); q1++)
			vt[q1].print();
		for(q1 = 0; q1 < vc.size(); q1++)
			vc[q1].print();
		for(q1 = 0; q1 < vs.size(); q1++)
			vs[q1].print();
		#endif

		q4 = 0;
		bool isInX;
		for(q1 = 1; q1 <= 50; q1++)
		{
			for(int q2 = 1; q2 <= 50; q2++)
			{
				isInX = false;
				for(int q3 = 0; q3 < vt.size(); q3++)
					if(vt[q3].isInTriangle(Point(q1, q2)))
					{
						isInX = true;
						goto count;
					}
				for(int q3 = 0; q3 < vc.size(); q3++)
					if(vc[q3].isInCircle(Point(q1, q2)))
					{
						isInX = true;
						goto count;
					}
				for(int q3 = 0; q3 < vs.size(); q3++)
					if(vs[q3].isInSquare(Point(q1, q2)))
					{
						isInX = true;
						goto count;
					}
				count:
					if(isInX)
						q4++;
			}
		}

		printf("%d\n", q4);
	}
	return 0;
}
