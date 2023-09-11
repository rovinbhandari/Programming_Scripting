import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class Main8{
    public static void main(String[] args) throws IOException {
    int R=0,B=0,G=0,W=0,T=0,w=5,x=5,y=5,z=5;
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    T=Integer.parseInt(br.readLine());
    String str[]=new String[T];
    for(int i=0;i<T;i++){
        str[i] = br.readLine();}
           for(int j=0;j<str.length;j++){R=0;G=0;B=0;W=0;w=1;x=1;y=1;z=1;
    for(int i=0;i<str[j].length();i++){
    if(str[j].charAt(i)=='R')        R++;
    else if(str[j].charAt(i)=='G')        G++;
    else if(str[j].charAt(i)=='B')        B++;
    else if(str[j].charAt(i)=='W')        W++;}

if(R%2==0) x=0; if(G%2==0) y=0; if(B%2==0) z=0; if(W%2==0) w=0;
    if((x+y+z+w)==0)
    System.out.println("YES");
else System.out.println("NO");
    }
}
}
