#include<stdio.h>
#include<math.h>




int Maxbuffersize=2000000;
char buffer[2000000];
char buffer2[2000000];
int bufpos,bufend,bufsize,bufpos2;


int getChar()
 {return buffer[bufpos++];
}



void skipWS() {
    while ((buffer[bufpos] == '\n' ||
    buffer[bufpos] == ' ' || buffer[bufpos] == '\t'))
    bufpos++;
    return;
    }

 int input() {
    int n = 0, x; skipWS();
    for (x = getChar(); x <= '9' && x >= '0'; x = getChar())
    n = (n << 3) + (n << 1) + (x - '0');
    
    return n;
    }




inline void print(const char* s) 
{
       while (*s)
        buffer2[bufpos2++] = *s++;
        return;
        }
        
        
void print(int x) 
{
    if (x < 0)
     {
    print('-'); print(-x); return;
    }
    char temp[1 << 4]; int idx = 0;
    do {
    temp[idx++] = '0' + (x % 10);
    x /= 10;
    } while (x != 0);
    temp[idx] = '\0';
    //reverse(temp, temp + idx);
    char temp2[idx+1];
    for(int i=0;i<idx;i++)
    temp2[i]=temp[idx-1-i];
    temp2[idx]='\0';
    print(temp2);
    return;
    }
    
    
inline void print(char ch) {buffer2[bufpos2++] = ch;}
    

        
inline void flushBuffer() {buffer2[bufpos2] = '\0'; printf("%s", buffer2); bufend = 0;}



int main()
{
     bufend=fread(buffer, sizeof(char), Maxbuffersize, stdin);
    bufpos=0;
    bufpos2=0;
    buffer[bufend]='\0';
          char ch;
         int t,i,cnt[4];
         //scanf("%d",&t); 
          t=input();
         while(t!=0)
         {
                     
                    cnt[0]=0;
                    cnt[1]=0;
                    cnt[2]=0;
                    cnt[3]=0;
                         t--;
                    
                   for(i=0;;i++)
                   {
                   
                   //scanf("%c",&ch);
                   ch=getChar();
                   //printf("%c",ch);
                   if(ch=='\n' || ch =='\r')
                   break;
                   if(ch=='R')
                   cnt[0]++;
                  
                   if(ch=='G')
                   cnt[1]++; 
                  
                   if(ch=='B')
                   cnt[2]++;
                   
                   if(ch=='W')
                   cnt[3]++;
                                     
                   }
                  if(((cnt[0]%2)==0)&&((cnt[1]%2)==0)&&((cnt[2]%2)==0)&&((cnt[3]%2)==0))
                  printf("YES\n");
                   else 
                  printf("NO\n");
              //    getch();
         }  
                   
      return 0;
      }

