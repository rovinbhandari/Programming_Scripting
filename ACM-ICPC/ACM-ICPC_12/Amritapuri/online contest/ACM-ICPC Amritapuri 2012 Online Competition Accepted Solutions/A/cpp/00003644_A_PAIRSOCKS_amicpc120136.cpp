#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
#define For(i,lb,ub) for(int i=lb;i<ub;i++)
int main()
{
  int t;
  scanf("%d",&t);
  vector<char*> ans(t); 
  For(j,0,t)
  {
    char s[55];
    scanf("%s",s);
    int r=0,g=0,b=0,w=0;
//     'R', 'G', 'B' or 'W
    int len=strlen(s);//length(s)
    For(i,0,len)
    {
      switch(s[i])
      {
	case 'R': r++;break;
	case 'G': g++;break;
	case 'B': b++;break;
	case 'W': w++;break;
      }
    }
    if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
      ans[j]="YES";
    else
      ans[j]="NO";
  }
  For(j,0,t)
    printf("%s\n",ans[j]);
  return 0;
}
