/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
     
     
   
    
   




import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author vibhor-world
 */
public class Main {
        static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)throws IOException {
        int t=input_no();
        for(int i=0;i<t;i++)
        {
            solve();
        }
        
        
        
        
        // TODO code application logic here
    }
    
    static void solve()throws IOException
    {
        int a=br.read();
        int arr[]=new int[4];
        while(a!=' '&&a!=10)
        {
            if(a=='R')
            {
                arr[0]++;
            }
            if(a=='G')
            {
                arr[1]++;
            }
            if(a=='B')
            {
                arr[2]++;
            }
            if(a=='W')
            {
                arr[3]++;
            }
            a=br.read();
        }
        int flag=0;
        for(int i=0;i<4;i++)
        {
            if(arr[i]%2==1)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        System.out.println("YES");
        else if(flag==1)
            System.out.println("NO");
        
        
    }
     public static int input_no()throws IOException
    {
        int no=0;
        int a=br.read();
        //System.out.println(a);
        while(a!=' '&&a!=10)
        {
                a=a-'0';
                no=(no<<3)+(no<<1);
                no=no+a;
                a=br.read();
        }
        
     
        return no;
    
    }
}
