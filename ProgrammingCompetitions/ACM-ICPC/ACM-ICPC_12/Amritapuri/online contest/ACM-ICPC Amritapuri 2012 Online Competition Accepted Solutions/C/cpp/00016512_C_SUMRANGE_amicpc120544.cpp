#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	vector<int> arr;
	vector<int> :: iterator left,right;
    int tests;
    scanf("%d",&tests);
   while(tests--)
   {
			int n,l,h,count=0,sum,i,j,target1,target2;
			scanf("%d%d%d",&n,&l,&h);
            arr.clear();
            for(int i=0;i<n;i++)
            {
				int temp;
                scanf("%d",&temp);
                arr.push_back(temp);
            }
			sort(arr.begin(),arr.end());
            for(i=0;i<n;i++)
               for(j=i+1;j<n;j++)
               {
                       sum=arr[i]+arr[j];
                       if(sum>=h)
                         break;
                        target1=l-sum;
                        target2=h-sum;
                       if(target1>0 && target2>0)
                       {
                        left = lower_bound(arr.begin()+j+1,arr.end(),target1);
						right = upper_bound(arr.begin()+j+1,arr.end(),target2);
						count+=int(right-left);       
                       }
                       else if(target1<=0 && target2>0)
                       {
                        right = upper_bound(arr.begin()+j+1,arr.end(),target2);
						count+=int(right-(arr.begin()+j+1));
                       }
               }         
             printf("%d\n",count);
   }
return 0;
}


