#include<iostream>
//#include<conio.h>
using namespace std;
 int main()
 {
    int test,cr,cw,cg,cb,n;
    cin>>test;
    while(test--)
    {
        string c;
        cin>>c;
        n=c.size();


        if(n%2!=0)
        cout<<"NO"<<endl;
        else
        {
            cr=0;cw=0;cg=0;cb=0;

            for(int i=0;i<n;i++)
            {
                if(c[i]=='R')
                    cr++;
                else if(c[i]=='G')
                    cg++;

               else if(c[i]=='B')
                    cb++;
               else if(c[i]=='W')
                    cw++;
                /*switch(c[i])
                {
                    case 'R':
                    cr++;
                    break;
                    case 'W':
                    cw++;
                    break;
                    case 'G':
                    cg++;
                    break;
                    case 'B':
                    cb++;
                }*/
            }
            if(cr%2!=0 || cg%2!=0 || cb%2!=0 || cw%2!=0 )
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;

        }


    }
    //getch();
        return 0;

 }
