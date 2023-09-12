import java.util.Scanner;

class PairSocks
{
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
  //      System.out.print("Input: ");
        short T = in.nextShort();
        in.nextLine();
        String op[] = new String[T];
        for(short i=0; i<T; i++)
        {
            String ci = in.nextLine();
            StringBuilder c= new StringBuilder(ci);
            for(int j=0;j<c.length();j++)
            {
                char ch = c.charAt(j);
                if(ch == 'R' || ch == 'G' || ch == 'B' || ch == 'W')
                {
                    for(int k =j+1; k<c.length(); k++)
                    {
                        if(c.charAt(k)==ch)
                        {
                            c.setCharAt(k,'*');
                            c.setCharAt(j,'*');
                            break;
                        }
                    }
                }
            }
            byte count = 0;
            for(int k=0; k<c.length(); k++)
            {
                if(c.charAt(k) == '*')
                count++;
                else
                break;
            }
            if(count == c.length())    
            op[i] = "YES";
            else
            op[i] = "NO";
        }
        in.close();
     //   System.out.println("\nOutput : ");
        for(short i=0; i<op.length; i++)
        System.out.println(op[i]);
    }
}
        
            
        