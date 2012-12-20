#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
  {
      int n,i=0,j,k=0;
      char in[55];
      scanf("%d",&n);
      int count[4];
      int ok[n];
      for(j=0;j<n;j++)
      {
          scanf("%s",in);
          for(i=0;i<4;i++)
        {
          count[i]=0;
        }

          i=0;
          while(i<strlen(in))
        {
            if(in[i]=='R')
            {
                count[0]++;
            }
            else if(in[i]=='G')
            {
                count[1]++;
            }
            else if(in[i]=='B')
            {
                count[2]++;
            }
            else if(in[i]=='W')
            {
                count[3]++;
            }
            i++;
        }

        if((count[0]%2==0) && (count[1]%2==0) && (count[2]%2==0) && (count[3]%2==0))
            {
                ok[k]=1;
                k++;
            }
        else
        {
            ok[k]=0;
            k++;
        }

      }

      for(i=0;i<n;i++)
      {
          if(ok[i]==1)
          {
              printf("YES\n");
          }
          else
          {
              printf("NO\n");
          }

      }

      return 0;
  }




