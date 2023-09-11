import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
/**
    * This will find how many pairs of numbers in the given array sum
    * up to the given number.
    *
    * @param array - array of integers
    * @param sum - The sum
    * @return int - number of pairs.
    */

class Main{
    public static void main(String[] args) throws IOException{
        
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int test=Integer.parseInt(br.readLine());
       
        for(int k=0;k<test;k++){
            
                String s=br.readLine();
                String t[]=s.split("\\s+");
                int n=Integer.parseInt(t[0]);
                int min=Integer.parseInt(t[1]);
                int max=Integer.parseInt(t[2]);
                //System.out.println("n="+n+"min="+min+""+max);
                int array[]=new int[n];
                
                    String arr=br.readLine();
                    
                    String ele[]=arr.split("\\s+");
                    
                    for(int i=0;i<n;i++)
                    array[i]=Integer.parseInt(ele[i]);
                


                int count=sumOfSubset(array,max,min);
                System.out.println(count);
            
        }
        
       
        
    }
    
    
    public static int sumOfSubset(int[] array, int max,int min)
{
        // This has a complexity of O ( n lg n )
        Arrays.sort(array);
        int sum1;
        
        int pairCount = 0;
        int leftIndex = 0;
        int rightIndex = array.length - 1;

        // The portion below has a complextiy of
        //  O ( n ) in the worst case.
        while ((array[rightIndex]+array[0]+array[1])> max)  //while (array[rightIndex] > sum + array[0])
        {
            rightIndex--;    
if(rightIndex==1)
return 0;
        }

        int temp=rightIndex;
        for(int i=0;i<temp;i++)
        {
            rightIndex=temp; //end maa lakh je
            leftIndex=i+1;
            while(i+2<=rightIndex){
            
                while (leftIndex < rightIndex)
                {
                    sum1=array[i] + array[leftIndex] + array[rightIndex];
                    if((sum1)<=max && (sum1)>=min)
                    {
                        pairCount++;
                        
                    }
                    else if((sum1) >max)
                    {
                        break;   
                    }
                    leftIndex++;
                }
                    leftIndex=i+1;
            
                rightIndex--;
            }
                    
            
        }
        

        return pairCount;
}

}