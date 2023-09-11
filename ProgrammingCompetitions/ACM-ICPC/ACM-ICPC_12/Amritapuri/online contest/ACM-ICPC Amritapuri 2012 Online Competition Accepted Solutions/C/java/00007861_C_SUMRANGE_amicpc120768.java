import java.io.IOException;
import java.util.StringTokenizer;


public class sumrange {
	public static void main(String[] args) throws IOException {
		java.io.BufferedReader r = new java.io.BufferedReader
		(new java.io.InputStreamReader (System.in));
		StringTokenizer st = new StringTokenizer(r.readLine());
		int t = Integer.parseInt(st.nextToken());
		StringBuilder output = new StringBuilder();
		for(int i = 0 ; i < t ; i++)
		{
			st = new StringTokenizer(r.readLine());
			int n = Integer.parseInt(st.nextToken());
			int l = Integer.parseInt(st.nextToken());
			int h = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(r.readLine());
			int[] nums = new int[n];
			for(int m = 0 ; m < n ;m++)
			{
				nums[m] = Integer.parseInt(st.nextToken());
			}
			solve(nums , l , h);
		}
	}
	
	static void solve(int[] nums , int l , int h)
	{
		int n = nums.length;
		int count = 0;
		for(int i = 0 ; i < n-2;i++)
		{
			for(int j=i+1;j<n-1;j++)
			{
				if((nums[i] + nums[j]) < h)
				{
					for(int k = j+1;k<n;k++)
					{
						int sum = nums[i] + nums[j] + nums[k]; 
						if((l<= sum) && (sum<=h))
							count++;
					}
				}
			}
		}
		System.out.println(count);
	}

}
