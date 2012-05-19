import java.io.*;

class classvariable
{
	static int x;
	static int y;
	
	public static void main(String args[])
	{
		System.out.println("in main");
		x = 5;
		y = 84;
		System.out.println("x = " + x);
		System.out.println("y = " + y);
	}
}

/*
	classvariable.java:11: non-static variable x cannot be referenced from a static context
		x = 5;
		^
	classvariable.java:13: non-static variable x cannot be referenced from a static context
		System.out.println("x = " + x);
		                            ^
	2 errors
*/

