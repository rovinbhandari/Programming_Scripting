#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
          int num, loop;
          char s[1000][1000];
          
          cin >> num;
          for (loop = 0; loop < num; loop++) 
              cin >> s[loop];
         
          
       for(loop = 0; loop < num; loop++) {
                 
          
          int ctr, ctg, ctb, ctw;
          int i,n;
          char str[1000];

          strcpy(str,s[loop]);
          ctr = ctg = ctw = ctb = 0;
          n = strlen(str);

          for(i = 0;i < n;i++)
                          {
                                          if(str[i] == 'R')
                                                         {
                                                         ctr++;
                                                         }
                                          if(str[i] == 'G')
                                                         {
                                                         ctg++;
                                                         }
                                          if(str[i] == 'B')
                                                         {
                                                         ctb++;
                                                         }
                                          if(str[i] == 'W')
                                                         {
                                                         ctw++;
                                                         }
                          }

             
             if((ctr%2!=0) || (ctg%2!=0) || (ctb%2!=0) || (ctw%2!=0))             
                         {
                         cout<<"NO\n";
                         }
             else
                 {
                         cout<<"YES\n";
                 }
       }          
       return(0);
}
