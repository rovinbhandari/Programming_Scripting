import java.util.HashMap;
import java.util.Scanner;
public class Acmicpc {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        for(int i=0;i<T;i++){
            String str=sc.next();
            int N=str.length();
            if(N!=0){
                HashMap<Character,Integer> hm=new HashMap<Character,Integer>();
                hm.put('R', 0);
                hm.put('G',0);
                hm.put('B', 0);
                hm.put('W',0);
                char a[]=new char[N];
                str.getChars(0, N, a, 0);
                for(int j=0;j<N;j++){
                    int cnt=hm.get(a[j]);
                    hm.put(a[j],cnt+1);
                }
                int flag=0;
                if(hm.get('R')%2==0){
                    if(hm.get('G')%2==0){
                        if(hm.get('B')%2==0){
                            if(hm.get('W')%2==0){
                                flag=1;
                                System.out.println("YES");
                            }
                        }
                    }
                }
                if(flag==0)
                    System.out.println("NO");
            }
            else
              System.out.println("YES");  
        }
    }
}
