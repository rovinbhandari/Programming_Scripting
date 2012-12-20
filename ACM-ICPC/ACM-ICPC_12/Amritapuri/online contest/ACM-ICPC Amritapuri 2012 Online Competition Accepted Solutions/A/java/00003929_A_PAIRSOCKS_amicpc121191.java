import java.util.*;
import java.io.*;
class Pair
{    public static void main(String args[]) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int noOfTest=Integer.parseInt(br.readLine());
        while(noOfTest>0)
        {
            String input=br.readLine();
            int colour[]=new int[4];
            int len=input.length();
            for(int i=0;i<len;i++)
            {
                if(input.charAt(i)== 'R')
                { 
                    colour[0]++;
                }
                else if(input.charAt(i)== 'B')
                { 
                    colour[1]++;
                }
                else if(input.charAt(i)== 'G')
                { 
                    colour[2]++;
                }
                else if(input.charAt(i)== 'W')
                { 
                    colour[3]++;
                }                              
                
            }
            if(colour[0]%2==0 && colour[1]%2==0 && colour[2]%2==0 && colour[3]%2==0 )
            {
                System.out.println("YES");
            }
            else
            {
                
                System.out.println("NO");
            }
            colour[0]=colour[1]=colour[2]=colour[3]=0;
            noOfTest--;
        }
    }
}