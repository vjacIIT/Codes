import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

class Main{

	private static final Scanner scanner = new Scanner(System.in);
	private static int months[] = {1,2,3,4,5,6,7,8,9,10,11,12};

	public static void main(String[] args){
		while(true){
			int increment = scanner.nextInt();
			int date = scanner.nextInt();
			int month = scanner.nextInt();
			int year = scanner.nextInt();
			if(increment==0 && date==0)	break;
			scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
			Calendar gcal = new GregorianCalendar(year,month-1,date);
			gcal.add(Calendar.DATE,increment);
			System.out.println(gcal.get(Calendar.DATE) + " " + months[gcal.get(Calendar.MONTH)] + " " + gcal.get(Calendar.YEAR));
		}
	}
}
