import java.util.Scanner;
public class Rgbw {
    public static void main(String[] args) {
        Scanner sin = new Scanner(System.in);
        int tc = sin.nextInt();
        for(int i=0;i<tc;i++)
        {
            String str = sin.next();
            int r=0,b=0,g=0,w=0;
            for(int j=0;j<str.length();j++)
            {
                if(str.charAt(j) == 'r' || str.charAt(j) == 'R')
                    r++;
                if(str.charAt(j) == 'b' || str.charAt(j) == 'B')
                    b++;
                if(str.charAt(j) == 'G' || str.charAt(j) == 'g')
                    g++;
                if(str.charAt(j) == 'w' || str.charAt(j) == 'W')
                    w++;
            }
            if(r%2!=0||g%2!=0||w%2!=0||b%2!=0)
                System.out.println("NO");
            else
                System.out.println("YES");
        }
     }
}