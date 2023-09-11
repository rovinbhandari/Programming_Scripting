import java.util.Scanner;


public class  Main  {
	
	public static void main(String[] args){
		
        Scanner in = new Scanner(System.in);
        
        String nums = in.nextLine();
        int r=0,g=0,b=0,w=0;
        int num = Integer.parseInt(nums);
        int [] Arr = new int[num];
        
        for ( int i = 0; i < num; i++)
        {
        	r=0;g=0;b=0;w=0;
//        	System.out.println("hello");
        	String n = in.nextLine();
        	for ( int j =0 ; j< n.length(); j++)
        	{
        		char c = n.charAt(j);
        		switch (c)
        		{
	        		case 'R':
	        			r++;
	        			break;
	        		case 'G':
	        			g++;
	        			break;
	        		case 'B':
	        			b++;
	        			break;
	        		case 'W':
	        			w++;
	        			break;
        		}
        		
        	}
//        	System.out.println(r+","+g+","+b+","+w);
        	if( (r%2==0)&& (g%2==0)&&(b%2==0)&&(w%2==0) )
        	{
        		Arr[i] = 1;
        	}
        	else{
        		Arr[i] = 0;
        	}
//        	System.out.println("line"+n);
        }
        in.close();
        
        for( int i=0; i <Arr.length; i++){
        	if( Arr[i] == 0 ) System.out.println("NO");
        	else System.out.println("YES");
        }
        
        
        
	}

}
