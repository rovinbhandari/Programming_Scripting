#include <iostream>
#include <list>
#include <queue>

using namespace std;


long long int ans(long long int num)	
{
	long long fix = 1000000000 + 7;
	if(num == 1)
	{
		return 2;
	}
	else if((num % 2) == 0)
	{
		long long int temp = ans(num / 2);
		temp = temp * temp;
		temp = temp % fix;
		return temp;
	}
	else if((num % 2) == 1)
	{
		long long int temp = ans((num - 1) / 2);
		temp = temp * temp;
		//temp = temp % fix;
		temp = temp * 2;
		temp = temp % fix;
		return temp;
	}
	return 0;
}
	
	
void call()
{
	int num;
	cin >> num;
	if(num <= 0)
	{
		cout << 0 << endl;
		return;
	}
	list<int> *arr;
	arr = new list<int> [num];
	
	int *check;
	check = new int[num];
	
	for(int i = 0; i < num; i++)
	check[i] = -1;
	
	int comp = 0;
	
	int rivals, curr;
	
	//cout << "here";
	
	for(int i =0; i < num; i++)
	{
		cin >> rivals;
		for(int j =0; j < rivals; j++)
		{
			cin >> curr;
			//cout << "here2";
			arr[i].push_back(curr);
			arr[curr].push_back(i);
			//cout << "here3";
		}
	}
	
	bool flag = true;
	
	for(int i = 0; i < num; i++)
	{
		if(check[i] == -1)
		{
			comp ++;
			//int mod = 0;
			queue<int> bfs;
			bfs.push(i);
			check[i] = 0;
			while(!(bfs.empty()))
			{   
				int elem = bfs.front();
				bfs.pop();
				list<int>::iterator itr1 = arr[elem].begin();
				list<int>::iterator itr2 = arr[elem].end();
				while(itr1 != itr2)
				{
					int now = (*itr1);
					itr1++;
					if(check[now] == -1)
					{	check[now] = check[elem] + 1;
						bfs.push(now);
					}
					else if((check[now] % 2) != ((check[elem] + 1) % 2))
					{
						cout << 0 << endl;
						return;
					}
				}
			}
		}
	}
			
	
	if (flag == true)
	{
		long long int a = ans(comp);
		//code to print answer using comp;
		cout << a<< endl;
	}
}


int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		call();
	}
	
	//long long int a = ans(100);
	//cout << a << "Here" << endl;
	return 0;
}
