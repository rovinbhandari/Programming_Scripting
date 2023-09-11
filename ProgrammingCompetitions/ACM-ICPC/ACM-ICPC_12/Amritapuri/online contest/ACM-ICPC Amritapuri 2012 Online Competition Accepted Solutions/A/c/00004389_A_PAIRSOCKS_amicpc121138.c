#include<stdio.h>
#include<stdlib.h>

int main(){

	int T ;
	char **ans=NULL;
	scanf("%d",&T);
	
	int i ;
	ans = (char**) malloc ( T*sizeof(char) );
	for(i=0;i<T;i++)
		ans[i] = (char*) malloc ( 4*sizeof(char) );
	int j = 0;
		
	for(i = 0; i < T ; i++){
		int count_B = 1;
		int count_G = 1 , count_R = 1 , count_W = 1 ;
		char ch ;
		char Str[55];
		j=0;
		scanf("%s",Str);	
		ch=Str[0];
		while(ch !=  '\0')
			{
				
				if(ch == 'R')
				count_R = count_R * -1;
						
				if(ch == 'G')
				count_G = count_G * -1;
	
			        if(ch == 'B')
				count_B = count_B * -1;
				
				if(ch == 'W')
				count_W = count_W * -1;
		
   			        j++;
			        ch = Str[j];
			}
		if(count_B == 1 && count_G == 1 && count_R == 1 && count_W ==1)
			ans[i] = "YES";
		else
			ans[i] = "NO";
	}
	
	for(i=0;i<T;i++){
		printf("%s\n",ans[i]);
	}
	
	
return 0;
}
