class hanoi
{
  public static void main (String args[])
  {
    if (args.length != 1) {
      System.err.println("error: a single integer argument needed");
      System.exit(1);
    }
    Integer N = new Integer(args[0]);
    H_dohanoi(N.intValue(), 3, 1, 2);
    System.exit(0);
  }

  static void H_dohanoi(int n, int t, int f, int u)
  {
    if (n > 0) {
      H_dohanoi(n-1, u, f, t);
      H_moveit(f, t);
      H_dohanoi(n-1, t, u, f);
    }
  }

  static void H_moveit(int from, int to)
  {
    System.out.print("move ");
    System.out.print(from);
    System.out.print(" --> ");
    System.out.println(to);
  }
}
