#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
int t,r,g,b,w,lenght;
char shock[51];
scanf("%d",&t);
while(t--)
{
scanf("%s",shock);
lenght=strlen(shock);
r=count(shock,shock+lenght,'R');
b=count(shock,shock+lenght,'B');
g=count(shock,shock+lenght,'G');
w=count(shock,shock+lenght,'W');
if(r%2==0 && b%2==0 && g%2==0 && w%2==0)
printf("YES\n");
else
printf("NO\n");
}
return 0;
}
