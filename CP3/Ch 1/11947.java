import java.io.*;
import java.util.*;
import java.text.*;
import java.util.regex.*;

class Main{

	private static Scanner scanner = new Scanner(System.in);
	
	private static String findSign(int month, int date){
		if(month==1)	return date>20 ? "aquarius":"capricorn"; 
		else if(month==2)	return date>19 ? "pisces":"aquarius";
		else if(month==3)	return date>20	? "aries":"pisces";
		else if(month==4)	return date>20	? "taurus":"aries";
		else if(month==5)	return date>21	? "gemini":"taurus";
		else if(month==6)	return date>21	? "cancer":"gemini";
		else if(month==7)	return date>22	? "leo":"cancer";
		else if(month==8)	return date>21	? "virgo":"leo";
		else if(month==9)	return date>23	? "libra":"virgo";
		else if(month==10)	return date>23	? "scorpio":"libra";
		else if(month==11)	return date>22	? "sagittarius":"scorpio";
		else	return date>22	? "capricorn":"sagittarius";
	}
	
	public static void main(String[] args){
		int month, date, year, helper;
		int tc = scanner.nextInt();
		String s1, s2;
		scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");
		for(int i=1; i<=tc; i++){
			String str = scanner.nextLine();
			helper = Integer.valueOf(str);
			month = helper/1000000;
			date = (helper/10000)%100;
			year = helper%10000;
			Calendar gcal = new GregorianCalendar(year,month-1,date);
			gcal.add(Calendar.DATE,280);
			month = gcal.get(Calendar.MONTH) + 1;
			date = gcal.get(Calendar.DATE);
			year = gcal.get(Calendar.YEAR);
			s1=month<10 ? "0":"";		s2=date<10 ? "0":"";
			str = findSign(month,date);
			System.out.println(i+" "+s1+month+"/"+s2+date+"/"+year+" "+str);
		}
	}

}
