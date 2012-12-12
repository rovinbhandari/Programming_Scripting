#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define SZ(a) a.size()
#define SORT(a) sort(a.begin(),a.end())

using namespace std;

bool myfunc(  pair <int,pair<int ,int> > a,   pair <int,pair<int ,int> > b)
{
        if(a.first<= b.first)
                return true;
        return false;
}

vector<pair <int,pair<int ,int> > > sum;
pair <int,pair<int ,int> > temp;
int len=0;
int n,l,h,a[1010];
//int array[100]={2,4,4,6,7};
int fOne(int search)
{

  int first = 0;
   int last = n - 1;
   int middle = (first+last)/2;

   while( first <= last )
   {
      if ( a[middle] < search )
         first = middle + 1;
      else if ( a[middle] == search && (middle==0 || a[middle]!=search) )
      {
         //printf("%d found at location %d.\n", search, middle+1);
         return middle;
         break ;
        }
      else
         last = middle - 1;

      middle = (first + last)/2;
   }
   if ( first > last )
      //printf("Not found! %d is not present in the list.\n", search);
      return first;
}

int fTwo(int search)
{
   int first = 0;
   int last = n - 1;
   int middle = (first+last)/2;

   while( first <= last )
   {
      if ( a[middle] > search )
         last = middle - 1;
      else if ( a[middle] == search && (middle==(len-1) ||a[middle]!=search) )
      {
         //printf("%d found at location %d.\n", search, middle+1);
         return middle;
         break;
      }
      else
         first = middle +1;

      middle = (first + last)/2;
   }
   if ( first > last )
      //printf("Not found! %d is not present in the list.\n", search);
      return last;
}

/*void f()
{
        len =5;
        printf("%d\n",fTwo(1));
}
*/

int main()
{
   //freopen("read.txt","r",stdin);
   //freopen("write.txt","w",stdout);
  //f();
  //return 0;

   int test;
   scanf("%d",&test);


   while(test--)
   {
        scanf("%d %d %d",&n,&l,&h);
        REP(i,n)
                scanf("%d",&a[i]);
        sort(a,a+n);

        /*printf("De1\n");
        REP(i,n)
                printf("%d ",a[i]);
        printf("\n\n");

        */

        len=0;
        REP(i,n)
                FOR(j,i+1,n)
                {
                        temp.first = a[i]+a[j];
                        temp.second.first=i;
                        temp.second.second=j;
                        len++;
                        sum.push_back(temp);
                }
        //sort(sum.begin(),sum.end(),myfunc);

        /*
        printf("De2\n");
        REP(i,len)
                printf("%d[%d][%d] ",sum[i].first,sum[i].second.first, sum[i].second.second);
        printf("\n\n");
       // */

        //
       // printf("three\n");
        int ans=0;
        FOR(i,0,len)
        {
            int val = sum[i].first;

            int indexOne,tempOne=l-val,indexTwo,tempTwo = h-val;
                //
           indexOne = fOne(tempOne);
           indexTwo = fTwo(tempTwo);
           int cnt = indexTwo - indexOne +1;
           //printf("%d %d %d %d\n",tempOne,indexOne,tempTwo,indexTwo);
           int ia = sum[i].second.first;
           int ib = sum[i].second.second;

           if((indexOne >= n) ||(indexTwo<=-1))
                cnt=0;

           else
           {if( ia>= indexOne && ia<=indexTwo)
                cnt--;
            if(ib>=indexOne && ib<=indexTwo)
                cnt--;
           }
         //  printf("%d %d %d %d %d\n",tempOne,indexOne,tempTwo,indexTwo,cnt);
          if(indexOne<=indexTwo)
          ans+=cnt;
        //

        }
        //printf("threeEnd\n");
        printf("%d\n",ans/3);
        sum.clear();
   }
  return 0;
}
