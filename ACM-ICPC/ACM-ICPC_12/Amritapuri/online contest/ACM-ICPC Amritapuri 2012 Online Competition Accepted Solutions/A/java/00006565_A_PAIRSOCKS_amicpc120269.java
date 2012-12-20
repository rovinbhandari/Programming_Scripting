import java.util.Scanner;
class Main
{
public static void main(String arg[])
{
    Scanner sc=new Scanner(System.in);
    String s;
    char a[];
    int r,g,i,b,w;
    
    int t=sc.nextInt();
    while(t!=0)
    {
        s=sc.next();
        r=g=b=w=0;
        a=new char[s.length()];
        a=s.toCharArray();
        
        if(a.length%2==0)
        {
        for(i=0;i<a.length;i++)
        {
            if(a[i]=='R')
                r++;
            else if(a[i]=='G')
                g++;
            else if(a[i]=='B')
                b++;
            else if(a[i]=='W')
                w++;
           
        }
     
        if(r%2==0 && b%2==0 && w%2==0 && b%2==0)
            System.out.println("YES");
       
        else
                System.out.println("NO");
        }
        else
                System.out.println("NO");
        
        
        t--;
    }
}
}