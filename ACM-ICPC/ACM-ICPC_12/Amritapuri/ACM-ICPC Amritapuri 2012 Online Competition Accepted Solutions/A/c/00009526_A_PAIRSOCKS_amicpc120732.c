 #include <stdio.h>

main()
{
 int rFlag,bFlag,gFlag,wFlag;
 int i,j,T;
 char str[1000][51];

 scanf("%d",&T);
 
  for(i=0;i<T;++i)
   scanf("%s",str[i]);


  for(i=0;i<T;++i)
 {
    rFlag=bFlag=gFlag=wFlag=0;

    for(j=0;str[i][j]!='\0';++j)
   {
      if(str[i][j]>97 )
       str[i][j]-=32;

      switch(str[i][j])
     {
       case 'R' : if(rFlag==0)
                   rFlag=1;
                  else
                   rFlag=0;
                  break;

       case 'B' : if(bFlag==0)
                   bFlag=1;
                  else
                   bFlag=0;
                  break;

       case 'G' :  if(gFlag==0)
                   gFlag=1;
                  else
                   gFlag=0;
                  break;

       case 'W' : if(wFlag==0)
                   wFlag=1;
                  else
                   wFlag=0;                  
     }

  
   }

    if( rFlag + bFlag + wFlag + gFlag ==0 )
     printf("YES\n");
    else
     printf("NO\n");

  }

 
return 0;
}
