import java.io.*;

class First
{    
    public static void main(String args[]) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int test_cases=Integer.parseInt(br.readLine());
        String[] output=new String[test_cases];
        int t=test_cases;
        while(test_cases>0)
        {
            String data=br.readLine();
            int l=data.length();
            if((l%2)!=0)
            {
                output[test_cases-1]="NO";
            }
            else
            {
                int r=0,g=0,w=0,b=0;
                for(int i=0;i<data.length();i++)
                {
                    if(data.charAt(i)=='R')
                        r++;
                    else if(data.charAt(i)=='B')
                        b++;
                    else if(data.charAt(i)=='W')
                        w++;
                    else if(data.charAt(i)=='G')
                        g++;
                }
                int check=0;
                do
                {
                    if((r%2)!=0)
                    {
                        output[test_cases-1]="NO";
                        check=1;
                        continue;
                    }
                    else
                    {
                        
                        if((b%2)!=0)
                        {
                            output[test_cases-1]="NO";
                            check=1;
                            continue;
                        }
                        else
                        {
                            
                            if((g%2)!=0)
                            {
                                output[test_cases-1]="NO";
                                check=1;
                                continue;
                            }
                            else
                            {
                                
                                if((w%2)!=0)
                                {
                                    output[test_cases-1]="NO";
                                    check=1;
                                    continue;
                                }
                                else
                                {
                                    output[test_cases-1]="YES";
                                    check=1;
                                    continue;
                                }
                            }
                        }
                    }
                }while(check==0);
            }
            
            
            
            test_cases--;
        }
        for(int i=t-1;i>=0;i--)
            {
                    System.out.println(output[i]);
            }
    }
}