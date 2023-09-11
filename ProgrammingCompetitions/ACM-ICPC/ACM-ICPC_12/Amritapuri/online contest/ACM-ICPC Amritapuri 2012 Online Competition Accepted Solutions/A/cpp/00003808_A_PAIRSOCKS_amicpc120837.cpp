#include <cstdio>
#include <cstring>
#define SIZE 50

using namespace std;

int socks[4];
char sockstring[SIZE];

int main()
{
        int T;
	scanf("%d",&T);
	for (int t=0;t<T;t++)
	{
		for(int i=0;i<4;i++)
			socks[i]=0;
		scanf("%s",sockstring);
		int len=strlen(sockstring);
		for(int i=0;i<len;i++)
		{
			switch (sockstring[i])
			{
				case 'R':socks[0]++;
					 break;
				case 'G':socks[1]++;
					 break;
				case 'B':socks[2]++;
					 break;
				case 'W':socks[3]++;
					 break;
			}
		}
		int flag=true;
		for(int i=0;i<4;i++)
		{
			if (socks[i]%2)
			{
				flag=false;break;
			}
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");

	
	}
	return 0;
}

