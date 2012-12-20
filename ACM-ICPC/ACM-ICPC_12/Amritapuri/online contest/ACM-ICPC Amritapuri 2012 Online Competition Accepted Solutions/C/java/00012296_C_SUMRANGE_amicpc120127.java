import java.util.*;
import java.io.*;
import java.math.*;
import java.lang.*;
 
public class Main {
 
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        try
        {
            Parserdoubt pd=new Parserdoubt(System.in);
            PrintWriter pw=new PrintWriter(System.out);
            int t=pd.nextInt();
            while(t-->0)
            {
                int n=pd.nextInt();
                int L=pd.nextInt();
                int H=pd.nextInt();
                int arr[]=new int[n];
                int vals[]=new int[1000001];
                for(int i=0;i<n;i++)
                {
                    arr[i]=pd.nextInt();
                    vals[arr[i]]++;
                }
                int psum[]=new int[1000001];
                psum[1]=vals[1];
                for(int i=2;i<=1000000;i++)
                    psum[i]=psum[i-1]+vals[i];
                int res=0;
                for(int i=0;i<n;i++)
                {
                    for(int j=i+1;j<n;j++)
                    {
                        int tmp=arr[i]+arr[j];
                        //System.out.println(tmp);
                        if(tmp<H)
                        {
                            int minsum=0;
                            if(L>=tmp)
                            {
                                minsum=L-tmp;
                            }
                            int maxsum=H-tmp;
                            res+=psum[maxsum]-psum[Math.max(0,minsum-1)];
                            if(arr[i]>=minsum&&arr[i]<=maxsum)
                                res--;
                            if(arr[j]>=minsum&&arr[j]<=maxsum)
                                res--;
                        }
                    }
                }
                pw.println(res/3);
            }
            pw.flush();
            
        }
        catch(Exception e)
        {
            e.printStackTrace();
        }
    }
 
}
 
class Parserdoubt {
 
    final private int BUFFER_SIZE = 1 << 17;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;
 
    public Parserdoubt(InputStream in) {
        din = new DataInputStream(in);
        buffer = new byte[BUFFER_SIZE];
        bufferPointer = bytesRead = 0;
    }
 
    public String nextString() throws Exception {
        StringBuffer sb = new StringBuffer("");
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        do {
            sb.append((char) c);
            c = read();
        } while (c > ' ');
        return sb.toString();
    }
 
    public char nextChar() throws Exception {
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        return (char) c;
    }
 
    public int nextInt() throws Exception {
        int ret = 0;
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        boolean neg = c == '-';
        if (neg) {
            c = read();
        }
        do {
            ret = ret * 10 + c - '0';
            c = read();
        } while (c > ' ');
        if (neg) {
            return -ret;
        }
        return ret;
    }
 
    public long nextLong() throws Exception {
        long ret = 0;
        byte c = read();
        while (c <= ' ') {
            c = read();
        }
        boolean neg = c == '-';
        if (neg) {
            c = read();
        }
        do {
            ret = ret * 10 + c - '0';
            c = read();
        } while (c > ' ');
        if (neg) {
            return -ret;
        }
        return ret;
    }
 
    private void fillBuffer() throws Exception {
        bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
        if (bytesRead == -1) {
            buffer[0] = -1;
        }
    }
 
    private byte read() throws Exception {
        if (bufferPointer == bytesRead) {
            fillBuffer();
        }
        return buffer[bufferPointer++];
    }
}