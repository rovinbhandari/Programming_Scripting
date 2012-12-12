#include<iostream>
//#include<conio.h>
using namespace std;
int main()
{
    int n,e,b,c,d;
    char a[50];
    cin>>n;
    while(n--)
    {
              cin>>a;
              b=0;
              c=0;
              d=0;
              e=0;
              for(int i=0;a[i]!='\0';i++)
              {
                      switch(a[i])
                      {
                                  case 'R' : b++;break;
                                  case 'W' : c++;break;
                                  case 'G' : d++;break;
                                  case 'B' : e++;break;
                      }
              }
              if(b%2==0 && c%2==0 && d%2==0 && e%2==0)
                      cout<<"YES\n";
              else
                      cout<<"NO\n";
    }
  // getch();
    return 0;
}
