 #include<stdio.h>
 #include<string.h>
 int main()
 {
    int t,i,l;
    char a[100];

    scanf("%d",&t);
    while(t--)
    {          int b[26]={0};
        scanf("%s",a);
        l=strlen(a);
        for(i=0;i<l;i++)
            b[a[i]-'A']++;
        if((b['B'-'A']%2==0)&&(b['G'-'A']%2==0)&&(b['W'-'A']%2==0)&&(b['R'-'A']%2==0))
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
 }
