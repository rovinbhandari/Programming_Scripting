#include <iostream>
#include <string.h>

using namespace std;

int main(){

    int testcases,x,i,j,rcount=0,bcount=0,gcount=0,wcount=0,start=0;
    char socks[1000][50],tempstring[60],choice;
    cin>>testcases;


    x=testcases;
    while(x>0){
        //tempsting = fgets(name, 50, stdin);
        cin>>tempstring;
        strcpy( socks[start], tempstring );

        x--;
        start++;
    }

  for(j=0;j<testcases;j++){
      for(i=0;i<50;i++)
        {

            choice=socks[j][i];
            if(choice=='\0'){break;}
            switch(choice)
            {
                case 'r':
                case 'R': rcount++;
                          break;
                case 'w':
                case 'W': wcount++;
                          break;

                case 'g':
                case 'G': gcount++;
                          break;
                case 'b':
                case 'B': bcount++;
                          break;
            }
        }

    if((rcount%2==0)&&(bcount%2==0)&&(gcount%2==0)&&(wcount%2==0))
       cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;


            rcount=0;
            bcount=0;
            gcount=0;
            wcount=0;
  }



    return 0;
}
