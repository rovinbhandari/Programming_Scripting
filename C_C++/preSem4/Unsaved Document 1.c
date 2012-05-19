#include<stdio.h>

struct poly
{
 int coeff;
 int exp;
 struct poly *next;
};

void func( struct poly *p, int m )
{
 struct poly node;
 node.exp=m;
 printf("exp is %d",m);
 printf("Enter coeff\n");
 scanf("%d",&node.coeff);
 node.next=p;
 p=&node;
} 

void func2( struct poly *p, int r, int m )
{
 struct poly node;
 node.exp=m;
 node.coeff=r;
 node.next=p;
 p=&node;
}

void main()
{
 int d,n,n1,n2,i;
 struct poly a;
 struct poly *p1='NULL',*p2='NULL',*p3='NULL';
 printf("Enter degree for first polynomial\n");
 scanf("%d",&n1);
 for ( i=0; i<n1+1; i++ )
 {
  printf("Enter node\n");
  func(p1,n1);
 }
 printf("Enter degree for second polynomial");
 scanf("%d",&n2);
 for ( i=0; i<n2+1; i++);
 {
  printf("Enter node\n");
  func(p2, n2);
 }
 if(n1>n2)
  {
   n=n1;
   d=n1-n2;
  } 
 else if(n2>n1)
  {
   n=n2;
   d=n2-n1;
  } 
 else
  {
   n=n1;
   d=0;
  }
 int s;
 if(n==n1)
  for (i=0; i<d; i++)
  {
   s=p1->coeff;
   func2(p3,s,n);
   n--;
   p1=p1->next;   
  }
 else
  for (i=0; i<d; i++)
  {
   s=p2->coeff;
   func2(p3,s,n);
   n--;
   p2=p2->next;
  }
 int q=n;
 for (i=0; i<q+1; i++)
 {
  s=p1->coeff+p2->coeff;
  func2(p3,s,n);
  n--;
  p1=p1->next;
  p2=p2->next;
 }
 int z=p3->exp;
 for (i=0; i<=z; i++)
 {
  printf("Sum is\n");
  printf("%dx^%d",p3->coeff,p3->exp);
  p3=p3->next;
 }
}           
