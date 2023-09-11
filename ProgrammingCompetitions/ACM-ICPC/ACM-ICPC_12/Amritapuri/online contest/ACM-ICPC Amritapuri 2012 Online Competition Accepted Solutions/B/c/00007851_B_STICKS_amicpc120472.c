#include<stdio.h>
#include<stdlib.h>
long isqrt (x) long long x;{
  long   squaredbit, root;
long long remainder;
   if (x<1) return 0;
  
   /* Load the binary constant 01 00 00 ... 00, where the number
    * of zero bits to the right of the single one bit
    * is even, and the one bit is as far left as is consistant
    * with that condition.)
    */
   squaredbit  = (long) ((((unsigned long) ~0L) >> 1) & 
                        ~(((unsigned long) ~0L) >> 2));
   /* This portable load replaces the loop that used to be 
    * here, and was donated by  legalize@xmission.com 
    */

   /* Form bits of the answer. */
   remainder = x;  root = 0;
   while (squaredbit > 0) {
     if (remainder >= (squaredbit | root)) {
         remainder -= (squaredbit | root);
         root >>= 1; root |= squaredbit;
     } else {
         root >>= 1;
     }
     squaredbit >>= 2; 
   }

   return root;
}
long int sqrt2(long int A,long int B, long int C)
{
	return (isqrt((long long) ((long long)A*(long long)A) + ((long long)B*(long long)B) + ((long long)C*(long long)C)));
}
int main()
{
	int T;			// No. of test cases
	char ch;
	long int i,j;
	long int N,M;
	long int L[50000],A,B,C,max,dia;
	long int count;		
	scanf("%d",&T);
	//printf("%d\n",T);
	for (i = 0; i<T; i++)
	{		
		count = 0;
		max = 0;
		scanf("%ld%ld",&N,&M);
		//printf("%ld %ld\n",N,M);
		for (j = 0; j<N;j++)
		{
			scanf("%ld", &L[j]);
			//printf("%ld\n",L[j]);
		}
		for (j = 0; j<M; j++)
		{
			scanf("%ld%ld%ld",&A,&B,&C);
			dia = sqrt2(A,B,C);
			//dia = isqrt((A*A) + (B*B) + (C*C));
			if(dia > max)
				max = dia;
			//printf("%ld %ld %ld %ld\n",A,B,C,dia);
		}
		for(j = 0; j < N; j++)
			if(L[j] <= max)
				count++;
		printf("%ld",count);
		scanf("%c",&ch);
		printf("\n");
		//printf("%ld %ld %ld %ld %ld %ld %ld\n",sqrt2(10,10,10),sqrt2(8,9,12),sqrt2(12,3,7),sqrt2(30000,30000,30000),sqrt2(67,60,1397),sqrt2(75,61,61),sqrt2(321,123,456));
	}

return 0;
}
