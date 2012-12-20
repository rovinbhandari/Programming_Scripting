#include<stdio.h>
#include<string.h>
int main()
{

 	int numTestCases,i,rCount=0,gCount=0,bCount=0,wCount=0,j=0,lengthOfInputString=0,*result;
 	char inputString[50];
	//printf("enter the number of test cases\n");
	scanf("%d",&numTestCases);
    result = (int*)malloc(numTestCases*sizeof(int));
     //printf("enter input strings");
	for( i=0;i<numTestCases;i++ )
	{


        scanf("%s",inputString);
       // printf("%s",inputString);

        lengthOfInputString=strlen(inputString);
        //printf("length:%d",lengthOfInputString);
        if(lengthOfInputString%2==1)
        {
                result[i]=0;
                continue;
        }

        for (j=0;j<lengthOfInputString;j++)
        {
             if(inputString[j]=='R')
            rCount++;
            if(inputString[j]=='G')
            gCount++;
            if(inputString[j]=='B')
            bCount++;
            if(inputString[j]=='W')
            wCount++;
        }
        if(rCount%2==0 && bCount%2==0 && gCount%2 ==0 && wCount%2==0)
        result[i]=1;
        else
        result[i]=0;
        rCount=0;
        bCount=0;
        gCount=0;
        wCount=0;
    }
    for(i =0 ;i<numTestCases;i++)
    {   if(result[i]==0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
