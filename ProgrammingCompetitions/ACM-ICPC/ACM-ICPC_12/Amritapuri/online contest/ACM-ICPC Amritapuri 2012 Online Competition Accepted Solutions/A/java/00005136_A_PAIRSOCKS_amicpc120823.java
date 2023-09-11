import java.util.Scanner;
class pairSocks
{
    public static void main(String a[])
    {
        int n;
        String test[];
        char colors[] = {'R','G','B','W'};
        Scanner s=new Scanner(System.in);
        n=s.nextInt();
        if(n>=1&&n<=1000)
        {
            test = new String[n];
            for(int i=0;i<n;i++)
            {	
                test[i]=s.next();
            }
            for(String cases:test)
            {
                if(cases.length()>50)
                {
                    System.out.println("NO");
                    continue;
                }
                //System.out.println("Case : " + cases);
                boolean allpairs=false;
                int count;
                for(char x:colors)
                {
                    allpairs=false;
                    count=0;
                    for(int i=0;i<cases.length();i++)
                    {
                       if(x==cases.charAt(i))
                            count++;
                    }
                    if(count%2==0)
                        allpairs = true;
                    else
                        break;
                }
                if(!allpairs)
                    System.out.println("NO");
                else
                    System.out.println("YES");
            }
        }
    }
}
