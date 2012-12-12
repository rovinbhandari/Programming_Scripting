#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;

int main()
{
	int r,g,b,w,T,N,i;
	string list;

	cin>>T;
	for( ; T>0;T--){
		cin>>list;
		//cout<<list;
		int size=list.length();
		//cout<<size;
		if(size%2!= 0)
		{
			printf("NO\n");
			continue;
		}

		else{
//			cout<<"!\n";
		i=0;
		r=0;
		b=0;
		g=0;
		w=0;
		
		for(i=0;i<size;i++){
			//cout<<"!\n";
			char c=list[i];

			switch(c){
				case 'R':
					r++;
					break;
				case 'G':
					g++;
					break;
				case 'B':
					b++;
					break;

				case 'W':
					w++;
					break;
				default:
					break;
			}
		}
			//cout<<r<<g<<b<<w;

			if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
			{printf("YES\n");}
			else printf("NO\n");
		}
		}
	return(0);
}
