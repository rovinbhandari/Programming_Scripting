//to find length of a given string
 import java.io.*;
class StrLength
{
 public static void main(String s[])throws Exception
 { 
   BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
   int T,i,j;
   String str;
   int len;
   T=Integer.parseInt(br.readLine());
   int ans[]=new int[T];
      for(i=0;i<T;i++)
     {
        int r=0,b=0,w=0,g=0;
        str=br.readLine();
        len=str.length();
        for(j=0;j<len;j++)
         {
            if(str.charAt(j)=='R')
               r++;
            else if(str.charAt(j)=='B')
               b++;
            else if(str.charAt(j)=='W')
               w++;
            else
               g++;
         }
           r=r%2;
           b=b%2;
           w=w%2;      
           g=g%2;
          
          if(r+b+w+g!=0)
          System.out.println("NO");
          else
          System.out.println("YES");

      

     }
  }
}