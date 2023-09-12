



import java.io.DataInputStream;
import java.io.InputStream;



public class Main {
	public static void main(String[] args) throws Exception {
		Main a = new Main();

		Parserdoubt pd = a.new Parserdoubt(System.in);
		StringBuffer sb = new StringBuffer();
		int cases = pd.nextInt();
		String input="";
		for(int i=0;i<cases;i++){
			input= pd.nextString();
			int countR=0,countG=0,countB=0,countW=0;
			
			for(int j=0;j<input.length();j++){
				if(input.charAt(j)=='R'){countR++;}
				else 		if(input.charAt(j)=='G'){countG++;}
				else	if(input.charAt(j)=='B'){countB++;}
				else	if(input.charAt(j)=='W'){countW++;}
				
			}
			
			if(countR%2==0&&countG%2==0&&countB%2==0&&countW%2==0){
				sb.append("YES"+"\n");
			}
			else{
				sb.append("NO"+"\n");
			}
			
		}
		
		System.out.print(sb);
		
	
	
	}
	
	
	
	
	
	class Parserdoubt {
		final private int BUFFER_SIZE = 1 << 17;

		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;

		public Parserdoubt(InputStream in) {
			din = new DataInputStream(in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}

		public String nextString() throws Exception {
			StringBuffer sb = new StringBuffer("");
			byte c = read();
			while (c <= ' ')
				c = read();
			do {
				sb.append((char) c);
				c = read();
			} while (c > ' ');
			return sb.toString();
		}

		public char nextChar() throws Exception {
			byte c = read();
			while (c <= ' ')
				c = read();
			return (char) c;
		}

		public int nextInt() throws Exception {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = c == '-';
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
				c = read();
			} while (c > ' ');
			if (neg)
				return -ret;
			return ret;
		}

		public long nextLong() throws Exception {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = c == '-';
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
				c = read();
			} while (c > ' ');
			if (neg)
				return -ret;
			return ret;
		}

		private void fillBuffer() throws Exception {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}

		private byte read() throws Exception {
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}
	}

	
}
