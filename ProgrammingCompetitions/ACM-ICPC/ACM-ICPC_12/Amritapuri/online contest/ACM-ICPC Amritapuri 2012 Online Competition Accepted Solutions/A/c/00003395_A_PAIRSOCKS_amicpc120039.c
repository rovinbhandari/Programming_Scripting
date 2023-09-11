#include<stdio.h>

int main()
{
    int t,i,j;
    int arr[4];
    char str[60];
    
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%s",str);
        for(j=0;j<4;j++)
            arr[j]=0;
        for(j=0;str[j]!='\0';j++)
        {
            switch(str[j])
            {
                case 'R':arr[0]++;
                         break;
                case 'G':arr[1]++;
                         break;
                case 'B':arr[2]++;
                         break;
                case 'W':arr[3]++;
                         break;
            }
        }
        if(arr[0]%2==0 && arr[1]%2==0 && arr[2]%2==0 && arr[3]%2==0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
