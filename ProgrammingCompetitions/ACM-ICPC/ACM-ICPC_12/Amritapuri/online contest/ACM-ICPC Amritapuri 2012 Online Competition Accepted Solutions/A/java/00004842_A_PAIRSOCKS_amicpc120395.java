import java.util.Scanner;
public class Main {
public static void main(String[] args) {
        Scanner dev = new Scanner(System.in);
        int n = dev.nextInt();
        String[] a = new String[n];
        for(int i=0;i<n;i++)
        {
        a[i]=dev.next();
        }
        for(int ii=0;ii<n;ii++)
        {
         int r=0,g=0,b=0,w=0;
        for(int j=0;j<a[ii].length();j++)
        {
            if(a[ii].charAt(j)=='R')
            {
                r++;
            }
            else if(a[ii].charAt(j) == 'G')
            {
                g++;
            }
            else if(a[ii].charAt(j) == 'B')
            {
                b++;
            }
           else
            {
                w++;
            }
        }
         if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
                {
                    System.out.println("YES");
                }
 else
                {
            System.out.println("NO");
 }}}}

