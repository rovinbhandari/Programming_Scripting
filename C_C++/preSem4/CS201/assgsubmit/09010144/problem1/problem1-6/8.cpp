#include<iostream>
#include<cmath>
using namespace std;

class Complex
{
        float real, imaginary;
        public:
        Complex ( float r=0, float i=0 );
        float operator-( Complex );
        float modulus();
        friend ostream& operator<<( ostream&, Complex );
};

Complex :: Complex( float r, float i )
{
        real = r;
        imaginary = i;
}

float Complex :: modulus()
{
        return sqrt( real*real + imaginary*imaginary );
}

float Complex :: operator-( Complex c )
{
        Complex diff( real - c.real, imaginary - c.imaginary );
        return diff.modulus();
}

ostream& operator<<( ostream& dout, Complex c )
{
        dout<<c.real<<" + i"<<c.imaginary;
        return dout;
}

float string :: operator-( string second )
{
	string common, unique;
	int check=0, i,j;
	//getting unique
	for( i=0; i< length(); i++ )
	{
		for( j=0; j< unique.length(); j++ )
		{
			if( at(i) == unique[j] )
			{
				check=1; break;
			}
		}
		if(check==0) unique.append(1,at(i));
		check = 0;
	}//cout<<"Unique = "<< unique.length();
//              int u = unique.length();
	for( i=0; i< second.length(); i++ )
	{
		for( j=0; j< unique.length(); j++ )
		{
			if( second[i]== unique[j] )
			{
				check=1; break;
			}
		}
		if(check==0) unique.append(1,second[i]);
		check = 0;
	}
//              cout<<"Unique = "<< unique.length();
	int u = unique.length();
	//getting common
	for( i=0; i< length(); i++ )
	{
		for( j=0; j< common.length(); j++ )
		{
			if( at(i)== common[j] )
			{
				check=1; break;
			}
		}
		if( check==0 )
		{
			for( int k=0; k<second.length(); k++ )
			{
				if( at(i) == second[k] )
				{
					common.append(1,at(i));
					break;
				}
			}
		}
	}//cout<<"Common="<<common.length();
	int c = common.length();
	int d = u-c;
//              cout<<"Difference="<< d;
	return (float)d;
}
                                                       
template<class T>
class Difference
{
        T first;
        T second;
        public:
        Difference( T a, T b ){ first = a; second = b;}
        template<U> friend float distance( Difference<U>& c); //OBSERVE HOW TO USE FRIEND FUNCTION IN TEMPLATE CLASS
};

template<class U>
float distance( Difference<U>& c )
{
	return c.first - c.second;
}
int main()
{
 	cout<<"\nWelcome to the distance calculator:\n";
        int a,b;
        float e,f;
        char c,d;
        string g,h;
        cout<<"Enter 2 integers :";
        cin >> a >> b;
        Difference<int>  integer( a, b );
        cout<<"Their difference is "<< (int)distance(integer);
        cout<<"\nEnter 2 floats :";
        cin >> e >> f;
        Difference<float>  floating( e, f );
        cout<<"Their difference is "<< distance(floating);
        cout<<"\nEnter 2 characters : ";
        cin >> c >> d;
        Difference<char> character( c, d );
        cout<<"Difference in their ASCII codes is "<<(int)distance(character);
/*        cout<<"\nEnter 1st string :";
//      string g,h;
//      g.clear();
//      h.clear();
        cin.ignore();
        getline( cin, g );
        cout<<"\nEnter 2nd string :";
        getline( cin, h );
//      cout<<"first string length= "<< g.length()<<endl;
        Difference<string> Strings( g, h );
        cout<<"Difference in number of unique and common characters is "<<(int)distance(Strings);*/
        cout<<"\nFor 1st complex no. enter real & imaginary part";
        cin >> e >> f;
        Complex c1( e, f );
        cout<<"\nFor 2nd complex no. enter real & imaginary part";
        cin >>  e >> f;
        Complex c2( e, f );
        Difference<Complex> comp( c1, c2 );
        cout<<" Distance between them is "<< distance(comp)<<endl;
        return 0;
}      											














                         