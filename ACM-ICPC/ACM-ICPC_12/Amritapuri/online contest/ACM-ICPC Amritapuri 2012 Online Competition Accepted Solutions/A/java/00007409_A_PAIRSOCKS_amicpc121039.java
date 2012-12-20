import java.util.*;
public class sock
{
 public static void main(String[] args)
 {
  int n,m;
  int rcount=0,wcount=0,bcount=0,gcount=0;
  Scanner in =new Scanner(System.in);
  n=in.nextInt();
  if(n>1000 || n<1)
	System.exit(0);
  String[] a=new String[n];
  String[] ans=new String[n];
  for(int i=0;i<n;i++)
  {
   a[i]=in.next();
   if(a[i].length()>50)
	System.exit(0);
  }
  
  for(int i=0;i<n;i++)
  {
   char[] c=new char[a[i].length()];
   c=a[i].toCharArray();
   for(int j=0;j<c.length;j++)
   {
    if(c[j]=='R' || c[j]=='W' || c[j]=='B' || c[j]=='G')
    {}
    else
          System.exit(0);
   }
   for(int j=0;j<c.length;j++)
   {
    if(c[j]=='R')
      rcount++ ;
    if(c[j]=='W')
      wcount++;
    if(c[j]=='B')
      bcount++;
    if(c[j]=='G')
      gcount++;
   }
   if(rcount%2==0 && bcount%2==0 && gcount%2==0 && wcount%2==0)
       ans[i]="YES";
   else
       ans[i]="NO";    
   rcount=0;
   bcount=0;
   gcount=0;
   wcount=0;
  }
  for(int i=0;i<n;i++)
    System.out.println(ans[i]);
 }
}
