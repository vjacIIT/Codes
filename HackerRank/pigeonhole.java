import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class specialMultiple {

    static String solve(int n) {
    	int cnt=0, result;
    	BigInteger b, v;
    	BigInteger m = new BigInteger(String.valueOf(n));
    	String[] s = new String[n];
    	BigInteger[] r = new BigInteger[n];
		BigInteger[] value = new BigInteger[5*n];
		for(int i=0; i<n; i++){
			s[i]="";
			for(int j=i; j<n; j++)	s[i]+='9';
			b = new BigInteger(s[i]);
			if((b.mod(m)).intValue()==0){
					value[cnt]=b;
					cnt++;
			}
			r[i]=b;
		}
		for(int i=n-1; i>=0; i--){
			for(int j=n-1; j>=0; j--){
				if(i!=j &&  ( ( r[i].subtract(r[j]) ).mod(m) ).intValue()==0 ){	
					value[cnt]=(r[i].subtract(r[j])).abs();
					cnt++;
				}
			}
		}
		v = r[0];
		v = v.add(v);		// will find the minimum value in the value array
		for(int i=cnt-1; i>=0; i--){
			result = v.compareTo(value[i]);
			System.out.println(value[i]);
			if(result==1)	v=value[i];
		}
		return String.valueOf(v);
    }
    public static void main(String[] args) {
    	String s;
    	s = solve(5);
    	System.out.println(s);
    	s = solve(7);
    	System.out.println(s);
    	s = solve(1);
    	System.out.println(s);
    }
}

// This program do not find the minimum number multiple of n which has only 0's and 9's in it.
// But this program proves pigeonhole principle
