/*
	A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91  99.

	Find the largest palindrome made from the product of two 3-digit numbers.
*/

class r004
{
	public static void main(String args[])
	{
		int p, pro;
		p = pro = 1;
		String q, w;
		for(int i = 999; i > 500; i--)
		{
			for(int j = 999; j > 500; j--)
			{
				p = j * i;
				q = Integer.toString(p);
				w = "";
				for(int k = q.length() - 1; k >= 0; k--)
				{
					w += q.charAt(k);
					if(q.equals(w))
					{
						if(pro < p)
						{
							pro = p;
						}
					}
				}
			}
		}	
		System.out.println("\n\tLargest palindrome made of the product\n\tof two three digit numbers is " + pro);
	}
}
