import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;

/**
 *
 * @author abhishek khanna
 */
public class Main
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw=new PrintWriter(new OutputStreamWriter(System.out));
        int test=Integer.parseInt(br.readLine());
        for(int j=0;j<test;j++)
        {
            String[] str=br.readLine().split(" ");
            int N=Integer.parseInt(str[0]);
            int L=Integer.parseInt(str[1]);
            int H=Integer.parseInt(str[2]);
            int res=0;
            int[] arr=new int[N];
            int count=0;
            String[] s=br.readLine().split(" ");
            for(String st:s)
            {
                arr[count++]=Integer.parseInt(st);
            }
            Arrays.sort(arr);
            for(int i=0;i<N-2;i++)
            {
                int a=i+1;
                int b=N-1;
                while(a<b)
                {
                    int sum=arr[i]+arr[a]+arr[b];
                    if(sum<L)
                    {
                        a++;
                    }
                    else if(sum>H)
                    {
                        b--;
                    }
                    else
                    {
                        break;
                    }
                }
                if(a!=b)
                {
                    for(int k=a;k<b;k++)
                    {
                        int ind1=bs1(k+1,b,arr,L-arr[i]-arr[k]);
                        int ind2=bs2(k+1,b,arr,H-arr[i]-arr[k]);
                        int card=0;
                        //System.out.println(ind1+","+ind2);
                        if(ind2>=ind1)
                        {
                            card=ind2-ind1+1;
                        }
                        res=res+card;
                    }
                }
                //System.out.println(res+" "+i);
            }
            pw.println(res);
        }
        pw.flush();
        // TODO code application logic here
    }

    public static int bs1(int start,int end,int[] arr,int num)
    {
        int res=0;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(arr[mid]<num)
            {
                start=mid+1;
            }
            else if(arr[mid]>=num)
            {
                res=mid;
                end=mid-1;
            }
        }
        return res;
    }

    public static int bs2(int start,int end,int[] arr,int num)
    {
        int res=0;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(arr[mid]>num)
            {
                end=mid-1;
            }
            else if(arr[mid]<=num)
            {
                res=mid;
                start=mid+1;
            }
        }
        return res;
    }
}