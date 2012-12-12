#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long i,j,k,p;
	int tc;

	cin >> tc;

	long n=0,l=0,h=0;	
	for (p=0;p<tc;p++)
	{
		cin >> n;
		cin >> l;
		cin >> h;


		//cout << "N is " << n << " l is " << l << " h is " << h;
		long a[n];
		for (j=0;j<n;j++)
		{
			cin >> a[j];
		}

//		cout << "sorted";
//		cin >> n;
		sort(a,a+sizeof(a)/sizeof(a[0]));
		
//		cout << "sorted2";
//		cin >> n;
		i=0;j=0;k=0;
		long count = 0;
		long e=0,f=0;
		for (i=0;i<n;i++)
		{
			j=i+1;
			k=n-1;
		
			while(k>j)
			{
				if ((a[i]+a[j]+a[k] >= l) && (a[i]+a[j]+a[k] <= h))
				{	
					count++;
					//cout << "(" << i << "," << j << "," << k << ")\n";

					for(e=k-1;e>j;e--)
					{
						if ((a[i]+a[j]+a[e] >= l) && (a[i]+a[j]+a[e] <= h))
						{	
							count++;
							//cout << "(" << i << "," << j << "," << e << ") - 2 \n";
						}
						else
							break;
					}


					for(e=j+1;e<k;e++)
					{
						if ((a[i]+a[k]+a[e] >= l) && (a[i]+a[k]+a[e] <= h))
						{	
							count++;
							//cout << "(" << i << "," << e << "," << k << ") - 3 \n";
						}
						else
							break;
					}

					j++;
					k--;

				}

				if (a[i] + a[j] + a[k] > h)
					k-- ;
				else if (a[i] + a[j] + a[k] < l)
					j++;				
			}
	
		}

		cout << count << "\n";
	}

	//finished input
	
}
