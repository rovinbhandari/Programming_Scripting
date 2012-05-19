#include<iostream>
using namespace std;

/*static*/ int size=0, tail=0;


void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void insert(int * &a, int d)
{
	++tail;
	a[tail] = d;
	int pos = tail;
	while((a[pos / 2] > a[pos]) && pos > 0)
	{
		swap(a[pos / 2], a[pos]);
		pos /= 2;
	}
}

void output(int * a)
{
	int i = 1;
	cout<<"\n";
	while(i <= tail)
	{
		cout<<"\t\t"<<a[i]<<"\n";
		i++;
	}
	cout<<"\n";
}

int delmin(int *a)
{
	int hole = 1;
	int min = a[hole];
	int last = a[tail];
	tail--;
	int child = 2 * hole;
	a[hole] = last;
	while(child <= tail)
	{
		if(child != tail && a[child] > a[child + 1])
			child++;
		if(a[hole] > a[child])
			swap(a[hole], a[child]);
		hole = child;
		child = 2 * hole;
	}
}

int main()
{
	int i, d;
	i = d = 0;
	int * a;
	cout<<"Enter size of heap-array : ";
	cin>>size;
	a = new int[size];
	a[0] = -8484;
	while(++i <= size)
	{
		cout<<"\n\tEnter data : ";
		cin>>d;
		if(d == 888)
			break;
		insert(a, d);
	}
	i = 0;
	output(a);
	cout<<"\n\tAfter deleteMin operation :\n";
	int m = delmin(a);
	output(a);
}
