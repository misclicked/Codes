// Don't place your source in a package
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

// Please name your class Main
class Main {
	public static void main (String[] args) throws java.lang.Exception {
	    Scanner in = new Scanner(System.in);
	    BigInteger a,b;
	    while(in.hasNext()){
    		a = in.nextBigInteger();
    		b = in.nextBigInteger();
    		System.out.println(a.multiply(b));
	    }
	}
}