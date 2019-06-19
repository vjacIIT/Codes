import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class primeSum {
    static boolean is_prime(long n){
        if(n<=3)    return n>1;
        else if(n%2==0 || n%3==0)    return false;
        long i=5;
        while(i*i<=n){
            if(n%i==0 || n%(i+2)==0)    return false;
            i=i+6;
        }
        return true;
        
    }
    
     //Function to check and return prime numbers 
    static boolean checkPrime(long n) 
    { 
        boolean a;
        if(n<=100){
                a = is_prime(n);
                return a;
        }
        // Converting long to BigInteger 
        BigInteger b = new BigInteger(String.valueOf(n)); 
  
        return b.isProbablePrime(1); 
    } 

    // Complete the solve function below.
    static String solve(long n, long k) {
        boolean p;
        if(n==1)    return "No";
        else{
            if(k==1){
                p = checkPrime(n);
                if(p)    return "Yes";
                else    return "No";
            }
            else if(k==2){
                if(n%2==0 && n!=2)  return "Yes";
                else{
                    p = checkPrime(n-2);
                    if(p)    return "Yes";
                    else    return "No";
                }
            }
            else{
                if(n>=2*k)   return "Yes";
                else    return "No";
            }
        }
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int tItr = 0; tItr < t; tItr++) {
            String[] nk = scanner.nextLine().split(" ");

            long n = Long.parseLong(nk[0]);

            long k = Long.parseLong(nk[1]);

            String result = solve(n, k);
            //System.out.println(result);

           bufferedWriter.write(result);
          bufferedWriter.newLine();
        }

       bufferedWriter.close();

       scanner.close();
    }
}

