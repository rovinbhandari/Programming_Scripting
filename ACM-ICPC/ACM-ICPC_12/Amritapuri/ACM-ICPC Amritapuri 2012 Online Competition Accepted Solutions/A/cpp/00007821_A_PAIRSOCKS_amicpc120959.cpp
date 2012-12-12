#include<iostream>
#include<string>
using namespace std;
int main()
{
 int t,k,j,a[4];
 cin>>t;
  string str[t];
 for(int i=0;i<t;i++)
 {
   cin>>str[i];
 }
 for(int i=0;i<t;i++)
{
  a[0]=a[1]=a[2]=a[3]=0;
   if(str[i].length()%2==0)
   {
      for( j=0,k=str[i].length()-1;j<k;j++,k--)
           {
                switch(str[i].at(j))
                    {
                        case 'R':
                            a[0]++;
                                         break;
                         case 'G':
                           a[1]++;
                                   break;
                        case 'B':
                         a[2]++;
                           break;
                         case 'W':
                           a[3]++;
                            break;
                   }
                   switch(str[i].at(k))
                   {
                    case 'R':
                       a[0]++;
                          break;
                    case 'G':
                              a[1]++;
                               break;
                     case 'B':
                                  a[2]++;
                                  break;
                    case 'W':
                                   a[3]++;
                                            break;
                    }
                    if(j==k)
                     {
                      switch(str[i].at(j))
                       {
                       case 'R':
                          a[0]++;
                            break;
                       case 'G':
                            a[1]++;
                            break;
                       case 'B':
                            a[2]++;
                            break;
                       case 'W':
                            a[3]++;
                            break;
                        }
                 }
          }
   }
   else
    {
    a[0]=1;
    }
   if((a[0]%2==0)&&(a[1]%2==0)&&(a[2]%2==0)&&(a[3]%2==0))
   cout<<"YES\n";
   else
   cout<<"NO\n";
 }

}
