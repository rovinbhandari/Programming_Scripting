# include <stdio.h>

void main()
    {
    int t,i, f,j, arr[4];
    char ch[51];
    scanf("%d",&t);
    for(i=0;i<t;i++)
        {
        for(j=0;j<4;j++)
            arr[j]=0;
        
        scanf("%s",ch);
        j=0;
        while(ch[j]!='\0')
            {
            switch(ch[j])
                {
                case 'R':
                    arr[0]+=1;
                break;
                case 'G':
                    arr[1]+=1;
                break;
                case 'B':
                    arr[2]+=1;
                break;
                case 'W':
                    arr[3]+=1;
                break;
                }
            j++;
            }
            
        f=0;
        for(j=0;j<4;j++)
            f+=arr[j]%2;
        if(f)
            fprintf(stdout,"NO\n");
        else
            fprintf(stdout,"YES\n");
        }
    }
