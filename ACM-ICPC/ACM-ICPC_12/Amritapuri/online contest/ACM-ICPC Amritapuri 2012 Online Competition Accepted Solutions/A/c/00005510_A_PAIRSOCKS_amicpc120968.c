#include<stdio.h>
int main()
{
    int test,cr,cb,cw,cg,i,c1;
    char str[51],r,w,g,b;
    scanf("%d",&test);
    r=82;
    w=87;
    g=71;
    b=66;
    while(test--)
    {
          scanf("%s",str);
          cr=cw=cg=cb=0;
          c1=1;
              for(i=0;str[i]!='\0';i++)
              {
                    if(!(str[i]^r))    
                         cr++;
              }
              if((cr%2)==0)
              {
                  for(i=0;str[i]!='\0';i++)
                  {
                        if(!(str[i]^b))    
                             cb++;
                  }
                  if((cb%2)==0)
                  {
                      for(i=0;str[i]!='\0';i++)
                      {
                            if(!(str[i]^w))    
                                 cw++;
                      }
                      if((cw%2)==0)
                      {        
                               c1=0;              
                              for(i=0;str[i]!='\0';i++)
                              {
                                    if(!(str[i]^g))    
                                         cg++;
                              }
                      }
                  }
              }
              if((cg%2)==0 && c1==0)
                  printf("YES\n");
              else
                  printf("NO\n");
    }
    return 0;
}

                  
                              
