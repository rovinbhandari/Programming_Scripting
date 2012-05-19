/* ICSE Together prg15 pg268 */
class j2t2a
{
 public static void main(String args[])
 {
  int primArr[]=new int[10];
  int c,cp=1,k=0;
  for(int i=1;cp<=10;i++)
  {
   c=0;
   for(int n=1;n<=i;n++)
   {
    if(i%n==0)
    {
     c++;
    }
   }
   if(c==2)
   {
    cp++;
    primArr[k]=i;
    k++;
   }
  }
  int odd=0;
  for(int i=0;i<k;i++)
  {
   System.out.print(" "+primArr[i]+"  \n");
   if(primArr[i]%2!=0)
   {
    odd++;
   }
  }
  System.out.println(odd);
 }
}




  
