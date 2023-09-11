#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> egyption_fraction(int a, int b)
{
	vector<int> result;
	int newD;
	while (true)
	{
		if (a == 1)
		{
			result.push_back(b);
			return result;
		}
		newD = b / a + 1;
		result.push_back (newD);
		a = a * newD - b;
		b = b * newD;
	}
}	

/*
bool myfunc(vector<pair <int, int> > a, vector<pair <int. int> > b)
{
	vector<pair <int, int> >::iterator ita, itb;
	if ( a.size() < b.size() )
	{
		for ( ita = a.begin(), itb = b.begin(); ita != a.end(); ita++, itb++ )
		{
			if ( (*ita).first < (*itb).first )
				return true;
			else  if ( (*ita).first > (*itb).first )
				return false;
		}
		return true;
	}

	if ( b.size() < a.size() )
	{
		for ( ita = a.begin(), itb = b.begin(); itb != b.end(); ita++, itb++ )
		{
			if ( (*ita).first < (*itb).first )
				return true;
			else  if ( (*ita).first > (*itb).first )
				return false;
		}
		return false;
	}

}
*/

int main()
{
	int a, b;
	scanf("%d %d",&a, &b);
	while (!(a == 1 &&  b == 1))
	{
		vector<int> result = egyption_fraction(a, b);
		sort(result.begin(), result.end());
		vector<int>::iterator it;
		for (it = result.begin(); it != result.end(); it++)
		{
			printf("%d ",*it);
		}
		printf("\n");	
		scanf("%d %d",&a, &b);
	}	


}	
