#include <stdio.h>

main(){
       
       int t,i,j,r,g,b,w;
       char ar[50]={'\0'};
       
       scanf("%d",&t);
       
       
       for(i=0;i<t;i++){
                r=0;
                g=0;
                b=0;
                w=0;
                        
           scanf("%s",ar); 
           j=0;                
           while(ar[j]!='\0')            
           {
                if(ar[j]=='R')
                r++;                             
                if(ar[j]=='G')
                g++;
                if(ar[j]=='B')
                b++;
                if(ar[j]=='W')
                w++; 
                j++;                                       
           }             
            if(r%2==0&&g%2==0&&b%2==0&&w%2==0)
            printf("YES\n");
            
            else
            printf("NO\n");            
       }
       
       
       
return 0;       
}
