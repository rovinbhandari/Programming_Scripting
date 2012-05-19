import java.io.*;

class methodinmainclass
{
	static int one(int x)
	{
		System.out.println("in one");
		return 1;
	}
	/*
	int two(int x)
	{
		System.out.println("in two");
		return 2;
	}
	*/
	public static void main(String args[])
	{
		System.out.println("in main");
		System.out.println(one(84));
		//System.out.println(this.two(84));	// does not work.
	}
}

/*
	methodinmainclass.java:14: non-static method one(int) cannot be referenced from a static context
		System.out.println(one(84));
		
		
	if a method is not static, that "tells" the compiler that the method requires access to instance-level data in the class, (like a non-static field). This data would not be available unless an instance of the class has been created. So the compiler throws an error if you try to call the method from a static method.. If in fact the method does NOT reference any non-static member of the class, make the method static.
*/
