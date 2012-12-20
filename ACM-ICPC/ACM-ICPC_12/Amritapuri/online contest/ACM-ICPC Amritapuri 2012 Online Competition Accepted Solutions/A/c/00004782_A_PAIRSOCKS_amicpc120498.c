    #include <stdio.h>
    #include <string.h>
     
    #define SIZE 50
     
    int main(int argc, char *argv[])
    {
        int i,j,n,r,g,b,w,O[1000];
	    char buffer[SIZE],yes[]="YES",no[]="NO";
	     
	    scanf("%d\n",&n);
     
	  
		    for (i = 0; i < n; i++)
		    {   r=g=b=w=0; 
                scanf("%s",buffer);
                j=0;
                
                while(buffer[j]!='\0')
			    {
			       
			       if(buffer[j]=='R')
			    	                  r++;
			    	else if(buffer[j]=='G')
			    	                  g++;
                    else if(buffer[j]=='B')
			    	                  b++;
                    else if(buffer[j]=='W')
			    	                  w++;
			    	                  
                    j++;
                }
                
                if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
			       {
                           O[i]=1;                                          
                   }
                else
                   {
                          O[i]=0;
                   }
			    
   			 }
             for(i=0;i<n;i++)
             {
                             if(O[i]==1)
                             {          
                                        printf("%s\n",yes);
                             }
                             else 
                             {          
                                        printf("%s\n",no);
                             }
                             
             }
		     
         return 0;
    }  
