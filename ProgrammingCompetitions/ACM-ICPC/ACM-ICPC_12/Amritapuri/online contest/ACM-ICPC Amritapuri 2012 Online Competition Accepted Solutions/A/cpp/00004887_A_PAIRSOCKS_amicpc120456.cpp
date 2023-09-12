#include<iostream>
#include<string>
#include<algorithm>
#include<queue>

using namespace std ;
using std::string;

using namespace std;

int main()
{
  int n,i,j;
  string str1;
  queue<string> str;
  int r=0,g=0,b=0,w=0;
  cin>>n;

  for(i=0;i<n;i++) {    
    cin>>str1;
    str.push(str1);
  }


  while(!str.empty()) {
    str1=str.front();
    str.pop();
    r=g=b=w=0;
    for(i=0;i<str1.length();i++) {
      switch(str1[i]){
        case 'R':
            r++;
            break;
        case 'G':
            g++;
            break;
        case 'B':
            b++;
            break;
        case 'W':
            w++;
            break;
        default:
           break;
      }
    }
    if(r%2==0 && g%2==0 && b%2==0 && w%2==0) {
     cout<<"YES"<<"\n";
    }
    else {
     cout<<"NO"<<"\n";
    }
  }   
  return 0;
}

