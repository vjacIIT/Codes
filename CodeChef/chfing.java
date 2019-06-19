/* package codechef; // don't place package name! */

import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{

	private static BigInteger one = BigInteger.ONE;
	private static BigInteger two = new BigInteger("2");
    private static BigInteger no = new BigInteger("1000000007");	
	
	static String solve(long n, long k) {
		BigInteger pdt1, pdt2;
		long terms = (k-1)/(n-1);
		long remainder = (k-1)%(n-1);
		BigInteger a = new BigInteger(String.valueOf(k-1));
        BigInteger b = new BigInteger(String.valueOf(k-n-remainder));
        if(n<k){
        	BigInteger r = new BigInteger(String.valueOf(remainder));
        	BigInteger t = new BigInteger(String.valueOf(terms));
        	pdt1 = t.multiply(r);
        	pdt2 = t.multiply(b);
        	pdt2 = pdt2.divide(two);
        	pdt2 = pdt2.add(pdt1);
        	a = pdt2.add(a);
        	a = a.mod(no);
        	return String.valueOf(a);
        }
        else{
        	a = a.mod(no);
        	return String.valueOf(a);
        }
    }

	private static final Scanner scanner = new Scanner(System.in);

	public static void main (String[] args)
	{
		int t = scanner.nextInt();
		scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
		for (int tItr = 0; tItr < t; tItr++) {
            String[] nk = scanner.nextLine().split(" ");

            long n = Long.parseLong(nk[0]);

            long k = Long.parseLong(nk[1]);

            String result = solve(n, k);
            System.out.println(result);
        }
        scanner.close();
	}
}

