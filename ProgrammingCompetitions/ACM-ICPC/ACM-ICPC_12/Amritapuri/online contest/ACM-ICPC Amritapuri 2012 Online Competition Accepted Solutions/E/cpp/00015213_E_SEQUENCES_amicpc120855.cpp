#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <time.h>

using namespace std;

int main()
        {
        int T;
        cin>>T;

        for(int i=0;i<T;i++)
                {
                int N,Q;
                cin >> N;
                char *s=(char *)malloc(N*sizeof(char));
                scanf("%s",s);
                int *cum0=(int *)malloc(N*sizeof(int));
                int *cum1=(int *)malloc(N*sizeof(int));
                cin >> Q;

                double bsize=ceil(sqrt(N));
                int n_t=ceil(N/bsize);
                int *sub=(int *)malloc(n_t*sizeof(int));

                int count0=0,count1=0;

                for(int j=0;j<N;j++)
                        {
                        if(s[j] == '0') count0++;
                        if(s[j] == '1') count1++;
                        cum0[j]=count0;
                        cum1[j]=count1;
                        //cout << cum0[j] << cum1[j]<< endl;
                        }

                for(int j=0;j<N;)
                        {
                        int max_val=INT_MIN,max_i=0;;
                        for(int k=0;k<min((int)bsize,N-j);k++)
                                {
                                int index=j+k;
                                int val=((index<=0)?0:cum0[index-1])+(cum1[N-1]-((index<=0)?0:cum1[index-1]));
                                if(val>max_val)
                                        {
                                        max_val=val;
                                        sub[j/(int)bsize]=k;

                                        }
                                //cout << "sub "<<sub[j/(int)bsize]<< endl;
                                }
                        j+=bsize;
                        }

                for(int j=0;j<Q;j++)
                        {
                        int p,q;
                        cin >> p >> q;
                        p=p-1;
                        q=q-1;

                        int max_val=INT_MIN;

                        //printf("Here\n");

                        for(int k=p;(k<ceil(p/bsize)*bsize) && (k<=q);k++)
                                {
                                int i1=(s[p]=='0')?1:0;
                                int i2=(s[k]=='0')?1:0;
                                int i3=(s[k]=='1')?1:0;
                                int i4=(s[q]=='1')?1:0;

                                int val0=cum0[k]-cum0[p]+i1-i2;
                                int val1=cum1[q]-cum1[k]+i3;
                                int val=val0+val1;
                        //      cout <<"val1 "<< val <<  endl;
                                max_val=max(max_val,val);
                                }
                        for(int k=floor(q/bsize)*bsize;k>=p&&k<=q;k++)
                                {
                                int i1=(s[p]=='0')?1:0;
                                int i2=(s[k]=='0')?1:0;
                                int i3=(s[k]=='1')?1:0;
                                int i4=(s[q]=='1')?1:0;

                                int val0=cum0[k]-cum0[p]+i1-i2;
                                int val1=cum1[q]-cum1[k]+i3;
                                int val=val0+val1;

                                max_val=max(max_val,val);
                                }
                        for(int k=ceil(p/bsize)*bsize;(k+bsize-1)<=q;k=k+bsize)
                                {
                                int index=k+sub[k/(int)bsize];

                                int i1=(s[p]=='0')?1:0;
                                int i2=(s[index]=='0')?1:0;
                                int i3=(s[index]=='1')?1:0;
                                int i4=(s[q]=='1')?1:0;

                                int val0=cum0[index]-cum0[p]+i1-i2;
                                int val1=cum1[q]-cum1[index]+i3;
                                int val=val0+val1;
                        //      cout <<"val3 "<< val <<" " << index <<   endl;
                                max_val=max(max_val,val);
                                }
                        int i1=(s[p]=='0')?1:0;
                        int i4=(s[q]=='1')?1:0;

                        int val=cum0[q]-cum0[p]+i1;
                        printf("%d\n",max(max_val,val));

                        }

                }


        }