import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 *
 * @author Roger
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int x = Integer.parseInt(br.readLine());
    while(x-->0)
    {
        String str[]=br.readLine().split(" ");
        int arr[] = new int[Integer.parseInt(str[0])];
        for(int i=0;i<Integer.parseInt(str[0]);i++)
        {
            arr[i]=Integer.parseInt(br.readLine());
        }
         Box boxes []= new Box[Integer.parseInt(str[1])]; 
        String s[]= new String[Integer.parseInt(str[1])];
        double maxdiagonal=Double.MIN_VALUE;
        for(int i=0;i<Integer.parseInt(str[1]);i++)
        {
            s[i]= br.readLine();
            String str1[] = s[i].split(" ");
            for(int j=0;j<3;j++)
            {
                boxes[i] = new Box(Integer.parseInt(str1[0]),Integer.parseInt(str1[1]),Integer.parseInt(str1[2]));
                double a = Math.pow(Integer.parseInt(str1[0]),2);                
                double b = Math.pow(Integer.parseInt(str1[1]),2);
                double c = Math.pow(Integer.parseInt(str1[2]),2);
                double sum= a+b+c;
                double sqrt = (int) Math.sqrt(sum);
                if(sqrt>maxdiagonal)
                {
                    maxdiagonal = sqrt;
                    
                }
            }
            
        }
        Arrays.sort(arr);
        int count=0;
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]>maxdiagonal)
            {
                break;
            }
            else
            {
                count++;
            }
        }
        System.out.println(count);
       if(x!=0)
        br.readLine();
    }
    }
}
class Box {
    
   int length;
   int breadth;
   int height;
   public Box(int l,int b,int h)
   {
       length=l;
       breadth=b;
       height=h;
   }
}