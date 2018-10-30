
public class chandanjava
{
	public static void main(String args[])
	{
		int a=10;
		int b= a + ++a + a++;
		int c= a++ + a++ + a--;
		int d= ++a + --a + a;
		int e= ++a + a++ + a++;
		int f= a++ + a++ + a;
		System.out.println(b+"\n"+c+"\n"+d+"\n"+e+"\n"+f+"\n");
	}
}