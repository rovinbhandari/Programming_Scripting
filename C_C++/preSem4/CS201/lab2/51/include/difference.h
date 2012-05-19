#include <iostream>
#include <string>
using namespace std;

template <class T> class Difference
{
	private:
		T first, second;
	public:		
		Difference(const T& fir, const T& sec);
		void reset(const T& fir,const T& sec);
		int distance();
		
}; 


template <>class Difference <string> 
{
	private:
		string first,second;
	public:
		Difference(const string& a="", const string& b="")
		{
			first = a;
			second = b;
		}
		void reset(const string& a, const string& b)
		{
			first = a;
			second = b;
		}
		int distance()
		{
			int i, j;
			string tuc, cc;
			for(i = 0; i < first.length(); i++)
			{
				if(tuc.find(first[i]) == string::npos)
					tuc=tuc+first[i];
			}
			
			for(i=0;i<second.length();i++)
			{
				if(tuc.find(second[i]) == string::npos)
					tuc=tuc+second[i];
			}				
			for(i=0;i<first.length();i++)
			{
				if(second.find(first[i])!=string::npos)
					if(cc.find(first[i]))
						cc=cc+first[i];
			}
			
			for(i=0;i<second.length();i++)
			{
				if(first.find(second[i])!=string::npos)
					if(cc.find(second[i]))
						cc=cc+second[i];
			}				
			
			
			return (tuc.length()-cc.length());
		}
};
