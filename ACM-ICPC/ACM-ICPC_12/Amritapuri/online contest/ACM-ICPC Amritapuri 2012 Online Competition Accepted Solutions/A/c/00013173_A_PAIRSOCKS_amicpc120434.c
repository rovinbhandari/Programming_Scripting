

int main()
{
  int t,i,j,t1[1000],r,b,g,w;
  char s[50];char s1;
 scanf("%d\n",&t);
 for(i=0;i<t;i++)
 {
             j=0; r=0;b=0;g=0;w=0;
              
                
                 while( ( s1= getchar()) !='\n')
                 {
                     s[j]=s1;     
                         
                         
                 if(s[j]=='R')
                     r++;
                     if(s[j]=='G')
                     g++;
                     if(s[j]=='W')
                     w++;
                     if(s[j]=='B')
                     b++;
                     j++;    
                  }
 
                     
                     if( (r%2 ==0) &&(w%2==0) &&(g%2==0) && (b%2==0) )
                     
                     t1[i]=1;
                     
                     else
                     t1[i]=0;            
                                  
       }  
                                  
                                  for(i=0;i<t;i++)
                                  {
                                                  if(t1[i]==1)
                                                  printf("YES\n");
                                                  else
                                                  printf("NO\n");
                                                  }                 
                                 
  	
  return 0;
}
