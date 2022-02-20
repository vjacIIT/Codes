// O(n) solution

import java.math.*;
import java.util.*;

class Main{
	private static final Scanner scanner = new Scanner(System.in);
	
	public static void main(String[] args){
		int v, cnt=0;
		ArrayList<BigInteger> arr = new ArrayList<BigInteger>();
		while(scanner.hasNextInt()){
			v = scanner.nextInt();
			if(v==-999999){						// reached the end, compute the max product
				// because all the values in arr are >= -99999
				BigInteger ans = BigInteger.valueOf(-999999);
				
				// min and max possible after taking the i'th element in arr
				ArrayList<BigInteger> incMin = new ArrayList<BigInteger>();
				ArrayList<BigInteger> incMax = new ArrayList<BigInteger>();
				//System.out.println(arr);
				incMin.add(arr.get(0));
				incMax.add(arr.get(0));
				ans = incMax.get(0);
				
				for(int i=1; i<cnt; i++){
					BigInteger mn = incMin.get(i-1).multiply(arr.get(i));
					BigInteger mx = incMax.get(i-1).multiply(arr.get(i));
					incMin.add((mn.min(mx)).min(arr.get(i)));
					incMax.add((mx.max(mn)).max(arr.get(i)));
					ans = ans.max(incMax.get(i));
				}
				
				System.out.println(ans);
				arr.clear();
				cnt=0; 
			}
			else{
				cnt++;
				arr.add(BigInteger.valueOf(v));
			} 
		}
	}	
}
