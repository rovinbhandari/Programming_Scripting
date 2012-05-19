class j2t2d
{
 public static void main(String args[])
 {
  int f=3000;
  int primArr[]=new int[f];
  int c,cp=1,k=0;
  for(int i=2;cp<=f;i++)
  {
   c=0;
   for(int n=1;n<=(int)(Math.sqrt(i));n++)
   {
    if(i%n==0)
    {
     c++;
    }
   }
   if(c==1)
   {
    cp++;
    primArr[k]=i;
    k++;
   }
  }
  for(int i=0;i<k;i++)
  {
   System.out.print(primArr[i]+"  ");
  }
  System.out.println("\nend");
 }
}




  
