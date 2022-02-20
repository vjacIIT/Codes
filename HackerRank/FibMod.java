import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

// Problem name should be same as that of the class

public class Solution {

    // Complete the fibonacciModified function below.
    static BigInteger fibonacciModified(int t1, int t2, int n) {
    	BigInteger sqr = new BigInteger(String.valueOf(0));
		BigInteger sum= new BigInteger(String.valueOf(0));
		BigInteger f0 = new BigInteger(String.valueOf(t1));
		BigInteger f1 = new BigInteger(String.valueOf(t2));
		for(int i=0; i<n-2; i++){
			sqr = f1.multiply(f1);
			sum = f0.add(sqr);
			f0=f1;
			f1=sum;
		}
		return sum;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] t1T2n = scanner.nextLine().split(" ");

        int t1 = Integer.parseInt(t1T2n[0]);

        int t2 = Integer.parseInt(t1T2n[1]);

        int n = Integer.parseInt(t1T2n[2]);

        BigInteger result = fibonacciModified(t1, t2, n);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

