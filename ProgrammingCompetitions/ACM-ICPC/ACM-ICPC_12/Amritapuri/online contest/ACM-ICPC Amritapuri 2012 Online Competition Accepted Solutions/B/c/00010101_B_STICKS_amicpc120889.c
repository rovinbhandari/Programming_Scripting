#include <stdio.h>
main(){
       
       int t,n,m,i,j,k;
       double len,tmp,*l,a,b,c;
       char r;
       scanf("%d",&t);
       
       for(i=0;i<t;i++){
                   k=0;  
                      
           scanf("%d %d",&n,&m);                 
                 
                 l=(double *)malloc(n*sizeof(double));
                
           for(j=0;j<n;j++){
              scanf("%lf",l+j);                 
           }
           len=0;
           for(j=0;j<m;j++)
           {
               scanf("%lf %lf %lf",&a,&b,&c);
                    tmp=a*a+b*b+c*c;
                    if(tmp>len)
                    len=tmp;           
           }
           for(j=0;j<n;j++){
                            tmp=l[j]*l[j];
              if(tmp<=len)
              k++;                 
           }      
          printf("%d\n",k); 
          scanf("%c",&r);             
       }
       
       
       
return 0;       
}
