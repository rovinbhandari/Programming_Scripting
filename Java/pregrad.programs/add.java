class add
{
  public static void main( String  args[]   )
  {
    int sum=0 , i;
    for(i = 0 ; i < args.length ; i++)
    {
      sum = sum + Integer.parseInt(  args[i] );
      /*  Integer.parseInt
          Float.parseFloat
          Double.parseDouble
      */
    }

  System.out.println( " Sum = "+sum);
  }
}
