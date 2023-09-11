#include<stdio.h>
int main(){
	
	int t;
	char c;
    scanf("%d",&t);
	unsigned int arr[4]={0};
    scanf("%c",&c);
    
    while(t>0){
        scanf("%c",&c);
        if(c=='R')
            arr[0]++;
        else if(c=='G')
            arr[1]++;
        else if(c=='B')
            arr[2]++;
        else if(c=='W')
            arr[3]++;
        else if(c=='\n')
        {
            if(arr[0]%2==0&&arr[1]%2==0&&arr[2]%2==0&&arr[3]%2==0)
                printf("YES\n");
            else
                printf("NO\n");
            arr[0]=0;arr[1]=0;arr[2]=0;arr[3]=0;
            t--;
        }
	
    }
    
        

}
	
