#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char s[1001];
int fre[26];
int main()
{
    int t;
    int flag=1;
    scanf("%d",&t);
    for(;t>0;t--){
    scanf("%s",s);
    for(int i=0;i<26;i++)fre[i]=0;
    for(int i=0;i<strlen(s);i++)
    {
            fre[s[i]-'A']++;
    }
    flag=1;
    for(int i=0;i<26;i++)
    {
            if(fre[i]%2==1){printf("NO\n");flag=0;break;}
    }
    if(flag==1)printf("YES\n");
}
return 0;
}
