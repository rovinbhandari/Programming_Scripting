import java.util.HashMap;

class Main {
	
	static HashMap<Long,Long> map;
	
	
	public static long func(long n) {
		
		long ret = n;
		
		if (map.get(n)!= null) {
			ret = map.get(n);
		} else {
			if (n>=12) {
				
			long comp = func(n/2)+func(n/3)+func(n/4);
			
			if (comp > n)
				ret = comp;
			}
			map.put(n, ret);
		}
		
		
		return ret;
	}
	
	
	public static void main (String[] args) throws java.lang.Exception
	{
		java.io.BufferedReader r = new java.io.BufferedReader (new java.io.InputStreamReader (System.in));
		String s;
		map = new HashMap<Long, Long>(100);
		while ((s=r.readLine())  != null) {
			long num = Long.parseLong(s);
			long dollar = func(num);
			System.out.println(dollar);
		}
	}
	
}
