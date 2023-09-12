#include<stdio.h>
#include<math.h>
int main(){
    int t,n,m,j,i,max,count;
    scanf("%d",&t);
    while(t--){
               count=0;
               max=0;
               int pos;
            scanf("%d %d",&n,&m);
            int a[n];
            for(i=0;i<n;++i)
                            scanf("%d",&a[i]);
            int b[m][4];
            for(i=0;i<m;++i){
                            scanf("%d %d %d",&b[i][0],&b[i][1],&b[i][2]);
                            b[i][3]=(int)sqrt(pow(b[i][0],2)+pow(b[i][1],2)+pow(b[i][2],2));
                            if(max<b[i][3])
                                           max=b[i][3];
                                           pos=i;
                            }
            for(i=0;i<n;++i){
                            if(a[i]<max)
                                        count++;
                            if(a[i]==max){
                                          count++;
                                          max=0;
                                          for(j=0;j<m;++j){
                                            if(max<b[j][3]){
                                                max=b[j][3];
                                                pos=j;
                                            }
                                          }
                                          }
                            }
           printf("%d\n",count);
    }
    return 0;
}
