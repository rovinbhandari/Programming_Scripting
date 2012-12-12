#include<iostream>
#include<stdio.h>
#include<math.h>
#include <stdlib.h>

using namespace std;
#define getcx getchar_unlocked

int t,n,l,h,a[1005],countx,count1,count2,loc,totCount;
struct element {
	int sum;
	int index1;
	int index2;
}aux[1000005];
long long ret;

inline long long inp()
{
    ret=0;
    int ch=getcx();
    while( ch < '0' || ch > '9' ){ ch=getcx();}
	
    while(  ch >= '0' && ch <= '9' )
	{ret = (ret*10)+ ( ch-'0'); ch=getcx();}
	return ret;
}

int compare (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}


void binSearch(int beg,int mid,int last,int toSearch,bool flag)
{
//	cout << "\na[" << beg <<"]="<< a[beg]<< " a["<<mid<<"] = " << a[mid] << "a["<<last<<"] = " << a[last] << " toSearch = " << toSearch;

	if(last >= n || beg >= n || mid>=n)
		return ;
	if(last<0 || beg < 0 || mid < 0)
		return ;
	if(a[beg] < toSearch && beg > loc)
	{
		loc = beg;
	}
	if(a[mid] < toSearch && mid > loc)
	{
		loc = mid;
	}
	if(a[last] < toSearch && last > loc)
	{
		loc = last;
	}
	
	if(a[beg] == toSearch && beg > loc && flag)
	{
		loc = beg;
	}
	if(a[mid] == toSearch && mid > loc && flag)
	{
		loc = mid;
	}
	if(a[last] == toSearch && last > loc && flag)
	{
		loc = last;
	}
	
	if(beg == mid)
	{
		return;
	}
	
	if(a[mid] > toSearch)
	{
		last = mid-1;
		mid = (beg+last)/2;
		binSearch(beg,mid,last,toSearch,flag);
		return ;
	}
	else if(a[mid] <= toSearch)
	{
		beg = mid+1;
		mid = (beg+last)/2;
		binSearch(beg,mid,last,toSearch,flag);
		return;
	}
}

int getCount(int x,int toSearch,bool flag)
{
//	int tCount = 0;
//	cout << "\nTo Search = " << toSearch;
	if(toSearch <=0)
		return -1;
		//return aux[x].index2;
	loc = -1;
	binSearch((aux[x].index2)+1,(n+aux[x].index2)/2,n-1,toSearch,flag);
//	cout << " loc = " << loc;
//	int index = loc;
//	if(index <aux[x].index2)
//		return aux[x].index2;
//	tCount = index;
	return loc;
}

int main()
{
	t = inp();
	while(t--)
	{
		countx = 0;
		totCount = 0;
		n = inp();
		l = inp();
		h = inp();
		for(int xx =0;xx<n;xx++)
			a[xx] = inp();
		qsort (a, n, sizeof(int), compare);		
		for(int xx =0;xx<n-1;xx++)
		{
			for(int yy =xx+1;yy<n;yy++)
			{
				aux[countx].index1 = xx;
				aux[countx].index2 = yy;
				aux[countx].sum = a[xx]+a[yy];
				countx++;
			}
		}
		for(int xx =0;xx<countx;xx++)
		{
			count1 = getCount(xx,l-aux[xx].sum-1,true);
			count2 = getCount(xx,h-aux[xx].sum,true);
			if(count1 == -1 && count2 == -1)
			{
				
			}
			else if(count1 == -1 && count2 != -1)
			{
				totCount += (count2 - aux[xx].index2);
			}
			else
			{
				count1 -= (aux[xx].index2);
				count2  -= (aux[xx].index2);
				totCount += (count2 - count1 );
			}
			
		}
		cout << totCount << "\n";
	}
	return 0;
}