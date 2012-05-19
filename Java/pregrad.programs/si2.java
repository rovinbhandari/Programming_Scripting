class si2
{
  public static void main (String args[])
  {
    float p,r,t,s,a;
    p = Float.parseFloat(  args[0] );
    r = Float.parseFloat(  args[1] );
    t = Float.parseFloat(  args[2] );
    s = (p*r*t)/100;
    a = p + s;
    /* Float = Single Data Type
       (Float.parseFloat) = used to convert String Data 
       Type into Integer Data Type
    */
    System.out.println (" PRINCIPAL = Rs. " + p);
    System.out.println (" RATE = " + r + " % p.a.");
    System.out.println (" TIME = " + t + " years ");
    System.out.println (" SIMPLE INTEREST = Rs. " + s);
    System.out.println (" AMOUNT = Rs. " + a);
  }
}
