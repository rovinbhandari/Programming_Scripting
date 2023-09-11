import java.io.*;
class socks
{
public static void main(String args[])throws IOException
{
InputStreamReader reader=new InputStreamReader(System.in);
BufferedReader input=new BufferedReader(reader);
int i,j,l,t,flag=0,k;
String st="";
char str[]=new char[50];

t=Integer.parseInt(input.readLine());
for(k=1;k<=t;k++)
{  st=input.readLine();
   l=st.length();
   if(l%2!=0)
   {   System.out.println("NO");
       continue;
   }
   else
   {   for(i=0;i<l;i++)
          str[i]=st.charAt(i);
       for(i=0;i<l-1;i++)
       {  for(j=i+1;j<l;j++)
          {  if(str[i]==str[j])
             {  str[i]=str[j]=' ';
             }
          }
       }
    }
       flag=0;
       for(i=0;i<l;i++)
       {  if(str[i]!=' ')
               flag=1;
       }
         if(flag==1)
             System.out.println("NO");
          else
             System.out.println("YES");
       
   
}

}


}