import java.util.Scanner;
public class PairTest
{
   public static void main(String[] args)
   {
        int notestcase;
        Scanner in=new Scanner(System.in);
        int no=in.nextInt();
        boolean[] result=new boolean[no];
        String case1;
        if(no>=1 && no<=1000)
        {
          for(int i=0;i<no;i++)
          {
            case1=in.next();
            if(case1.length()<=50)
            {
                result[i]=(case1.length()%2==0);
                if(result[i])
                {
                   int r=0,g=0,w=0,b=0;
                   for(int index=0;index<case1.length();index++)
                   {
                       char ch=case1.charAt(index);
                       if(ch=='R') r++;
                       else if(ch=='G') g++;
                       else if(ch=='B') b++;
                       else if(ch=='W') w++;
                       else
                          System.exit(0);
                   }
                   result[i]=(r%2==0 && g%2==0 && w%2==0 && g%2==0);
                }
            }
          }
          for(int i=0;i<no;i++ )
              System.out.println((result[i])?"YES":"NO");

        }
        else
        System.exit(0);

   }
}

